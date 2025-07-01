//
// Created by sansan on 25-7-2.
// 求非空二叉树的宽度
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

// 层序遍历求宽度
int tree_max_width(Tree t) {
    if (!t)
        return 0;
    sq_queue s;
    s.front = s.rear = 0;
    int width=0; // 记录当前层数的width
    int max_width=0; // 记录全局的width的最大值
    Tree p = t; // 暂存t
    enter_queue(&s, p);
    int flag = 0;
    while (s.front !=s.rear) {
        flag= s.rear; // 记录当前一轮的rear指针
        width=0;
        while (flag!=s.front) {// 当前记录的rear指针,也就是flag!=front的时候开始循环,结束循环代表一层结束
            out_queue(&s,&p);
            width++;
            if (p->lchild)
                enter_queue(&s,p->lchild);
            if (p->rchild)
                enter_queue(&s,p->rchild);
        }
        if (width>max_width)
            max_width=width;
    }
    return max_width;
}


int main() {
    Tree t;
    build_tree(&t);
    printf("%d\n",tree_max_width(t));

    return 0;
}
