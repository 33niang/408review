//
// Created by sansan on 25-7-2.
// 将二叉树的叶子节点连成一个链表
// 表头指针为head,使用叶子结点的右指针存放链表指针
//

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct TreeNode {
    char data;
    struct TreeNode *lchild, *rchild;
} TreeNode, *Tree;

void build_tree(Tree *t) {
    char ch;
    scanf(" %c", &ch);
    if (ch == '#')
        *t = NULL;
    else {
        (*t) = (TreeNode *) malloc(sizeof(TreeNode));
        (*t)->data = ch;
        (*t)->lchild = NULL;
        (*t)->rchild = NULL;
        build_tree(&(*t)->lchild);
        build_tree(&(*t)->rchild);
    }
}

typedef struct queue {
    TreeNode *data[MAXSIZE];
    int front, rear;
} sq_queue;

int enter_queue(sq_queue *s, TreeNode *x) {
    if (s->front == ((s->rear) + 1) % MAXSIZE)
        return 0;
    s->data[s->rear] = x;
    s->rear = (s->rear + 1) % MAXSIZE;
    return 1;
}

int out_queue(sq_queue *s, TreeNode * *x) {
    if (s->front == s->rear)
        return 0;
    *x = s->data[s->front];
    s->front = (s->front + 1) % MAXSIZE;
    return 1;
}

// 前序遍历二叉树,检测到t->lchild==NULL&&r->child==NULL记录当前节点
void linklist_tree_leaf(Tree t,TreeNode** pre) {
    if (t==NULL)
            return;
    if (t->lchild==NULL&&t->rchild==NULL) {
        (*pre)->rchild=t;
        (*pre)=t;

    }
    if (t->lchild)
        linklist_tree_leaf(t->lchild,pre);
    if (t->rchild)
        linklist_tree_leaf(t->rchild,pre);
}


void disp(TreeNode *head) {
    if (!head)
        return;
    TreeNode *p=head;
    while (p) {
        printf("%c ",p->data);
        p=p->rchild;
    }
}
int main() {
    Tree t;
    // ABDBC##D##E##E##CF##G##
    build_tree(&t);

    TreeNode*head=(TreeNode*)malloc(sizeof(TreeNode));
    head->lchild=head->rchild=NULL;
    
    TreeNode*pre=head;
    linklist_tree_leaf(t,&pre);
    disp(head->rchild);

    free(head);

    return 0;
}
