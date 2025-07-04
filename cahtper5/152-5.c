//
// Created by sansan on 25-6-30.
// 计算一个二叉树所有的双分支节点个数
//

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50

typedef struct TreeNode {
    char data;
    struct TreeNode *lchild, *rchild;
} TreeNode, *Tree;

typedef struct queue {
    TreeNode *data[MAXSIZE];
    int front, rear;
} sq_queue;

int enter_queue(sq_queue *q, TreeNode *x) {
    if (q->front == (q->rear + 1) % MAXSIZE)
        return 0;
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAXSIZE;
    return 1;
}

int out_queue(sq_queue *q, TreeNode **x) {
    if (q->front == q->rear)
        return 0;
    *x = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return 1;
}

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

int double_branch_node_num(Tree t) {
    if (t == NULL)
        return 0;
    sq_queue s;
    s.front = s.rear = 0;
    int num = 0; // 记录双分支节点数
    TreeNode *q; //负责出入队的节点
    enter_queue(&s, t); // 手动入第一个节点
    while (s.front != s.rear) {
        // queue非空的时候循环
        out_queue(&s, &q);
        printf("%c ", q->data);
        if (q->lchild && q->rchild)
            num++;
        if (q->lchild)
            enter_queue(&s, q->lchild);
        if (q->rchild)
            enter_queue(&s, q->rchild);
    }
    return num;
}

// 递归求解双分支节点总数
int double_branch_node_num_RECURSIVE_METHOD(Tree t) {
    if (t==NULL)
        return 0;
    // 如果节点不为空,就递归的返回下一级的左右孩子的双分支节点数,如果lchild&&rchild存在则+1,否则+0
    return double_branch_node_num_RECURSIVE_METHOD(t->lchild)+double_branch_node_num_RECURSIVE_METHOD(t->rchild)+((t->lchild&&t->rchild)?1:0);

}
int main() {
    Tree t;
    build_tree(&t);
    //ABD##E##CF##G##  3个
    printf("\ndouble node num is:%d", double_branch_node_num_RECURSIVE_METHOD(t));
    return 0;
}
