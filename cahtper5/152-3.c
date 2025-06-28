//
// Created by sansan on 25-6-28.
// 非递归求树的高度
//


#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct TreeNode {
    char data;
    struct TreeNode* lchild, * rchild;
} TreeNode, * Tree;

typedef struct queue {
    TreeNode* data[MAXSIZE];
    int front, rear;
} sq_queue;

void create_tree(Tree* t) {
    char ch;
    scanf_s(" %c", &ch);
    if (ch == '#')
        *t = NULL;
    else {
        (*t) = (TreeNode*)malloc(sizeof(TreeNode));
        (*t)->data = ch;
        (*t)->lchild = NULL;
        (*t)->rchild = NULL;
        create_tree(&(*t)->lchild);
        create_tree(&(*t)->rchild);
    }
}

int enter_queue(sq_queue* q, TreeNode* x) {
    if (q->front == (q->rear + 1) % MAXSIZE)
        return 0; // 队满,无法入队
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAXSIZE;
    return 1;
}

int out_queue(sq_queue* q, TreeNode** x) {
    if (q->front == q->rear)
        return 0; // 队空,无法出队
    *x = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return 1;
}

// 用一个队列来层次遍历,并且增加计数器

// last方法,last指针指向当前层最后一个节点
int tree_height_last_method(Tree t) {
    if (!t)
        return 0;
    sq_queue q;
    q.front = q.rear = 0; // 队列初始化
    int height = 0;
    Tree p; // 出栈时候将Tree带出的节点
    int last; // 标记该层最后一个节点

    enter_queue(&q, t);
    last = q.rear; // 将last赋值为当前最后一个节点

    // 开始层序遍历
    while (q.front != q.rear) {
        out_queue(&q, &p);
        printf("%c ", p->data);
        if (p->lchild)
            enter_queue(&q, p->lchild);
        if (p->rchild)
            enter_queue(&q, p->rchild);
        if (q.front == last) {
            height++;
            last = q.rear;
        }
    }
    return height;
}

// 记录当前层一共有多少个节点,
int tree_height_number_method(Tree t) {
    if (!t)
        return 0;
    sq_queue q;
    q.front = q.rear = 0; // 队列初始化
    int height = 0;
    Tree p=t; // 出栈时候将Tree带出的节点

    enter_queue(&q, t);

    // 开始层序遍历
    while (q.front != q.rear) {
        //先记录该层有多少个节点
        int num = (q.rear + MAXSIZE - q.front) % MAXSIZE;
        height++;
        for (int i = 0; i < num; i++) {
            out_queue(&q, &p);

            printf("%c ", p->data);
        }
        if (p->lchild)
            enter_queue(&q, p->lchild);
        if (p->rchild)
            enter_queue(&q, p->rchild);
    }
    return height;
}


int main() {
    Tree t;
    // ABD##E##CF##G##
    create_tree(&t);
    printf("\n%d", tree_height_number_method(t));
}
