//
// Created by sansan on 25-6-28.
// 二叉树从下而上,从右到左的层次遍历
//

//用一个stack存入正常的层次遍历的信息,然后入栈,最后出栈

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct TreeNode {
    char data;
    struct TreeNode*lchild,*rchild;
}TreeNode,*Tree;

typedef struct queue {
    TreeNode* data[MAXSIZE];
    int front,rear;
}sq_queue;

typedef struct stack{
    TreeNode*data[MAXSIZE];
    int top;
}stack;

// 入栈
int push(stack *S,TreeNode* x) {
    if (S->top==MAXSIZE-1)
        return 0;
    S->data[++S->top]=x;
    return 1;
}

// 出栈
int pop(stack *S,TreeNode **x) {
    if (S->top==-1)
        return 0;
    *x=S->data[S->top--];
    return 1;
}

//队列判空
int is_empty(sq_queue q) {
    if (q.front==q.rear)
        return 1; // 为空
    return 0; // 未空
}

// 队列判满
int is_full(sq_queue q) {
    if ((q.rear+1)%MAXSIZE==q.front)
        return 1;
    return 0;
}

// 入队
int enter_queue(sq_queue *q,TreeNode* x) {
    if (is_full(*q))
        return 0;
    q->data[q->rear]=x;
    q->rear=(q->rear+1)%MAXSIZE;
    return 1;
}

int out_squeue(sq_queue *q,TreeNode **x) {
    if (is_empty(*q))
        return 0;
    *x=q->data[q->front];
    q->front=(q->front+1)%MAXSIZE;
    return 1;
}

void create_tree(Tree *t) {
    char ch;
    scanf(" %c",&ch);
    if (ch=='#')
        *t=NULL;
    else {
        *t=(TreeNode *)malloc(sizeof(TreeNode));
        (*t)->data=ch;
        (*t)->lchild=NULL;
        (*t)->rchild=NULL;
        // 先序遍历递归构建tree
        create_tree(&(*t)->lchild);
        create_tree(&(*t)->rchild);
    }
}

void solve(Tree t) {
    stack s;
    sq_queue q;
    TreeNode *p;
    if (t) {
        s.top=-1; // 初始化stack
        q.front=q.rear=0;
        enter_queue(&q,t);
        while (!is_empty(q)) { // 如果队列非空
            out_squeue(&q,&p);
            push(&s,p);
            if (p->lchild)
                enter_queue(&q,p->lchild);
            if (p->rchild)
                enter_queue(&q,p->rchild);
        }
        while (!(s.top==-1)) { // stack非空
            pop(&s,&p);
            printf("%c ",p->data);
        }

    }
}

int main() {
    Tree t;
    // ABD##E##CF##G##
    create_tree(&t);
    //
    //     A
    //    / \
    //   B   C
    //  / \ / \
    // D  E F  G
    //

    solve(t);
    return 0;
}
