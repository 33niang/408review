//
// Created by sansan on 25-7-2.
// 求叶子节点的带权路径和
// ∑ weight*deep

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50

typedef struct TreeNode {
    struct TreeNode *left;
    unsigned int weight;
    struct TreeNode *right;
} *Tree, TreeNode;


void build_tree(Tree *t) {
    int ch;
    scanf(" %d", &ch);
    if (ch == -1)
        (*t) = NULL;
    else {
        (*t) = (TreeNode *) malloc(sizeof(TreeNode));
        (*t)->weight = ch;
        (*t)->left = (*t)->right = NULL;
        build_tree(&(*t)->left);
        build_tree(&(*t)->right);
    }
}

typedef struct queue {
    TreeNode *data[MAXSIZE];
    int front, rear;
} sq_queue;

int enter_queue(sq_queue *s, TreeNode *x) {
    if (s->front == (s->rear + 1) % MAXSIZE)
        return 0;
    s->data[s->rear] = x;
    s->rear = (s->rear + 1) % MAXSIZE;
    return 1;
}

int out_queue(sq_queue *s, TreeNode **x) {
    if (s->front == s->rear)
        return 0;
    *x = s->data[s->front];
    s->front = (s->front + 1) % MAXSIZE;
    return 1;
}

// 层序遍历求出深度deep,然后deep*weight
int WPL(Tree t) {
    if (!t)
        return 0;
    // 创建队列以及初始化
    sq_queue s;
    s.front = s.rear = 0;

    TreeNode *p = t;
    enter_queue(&s, p); // 第一个节点入队

    int flag; // 标记当前循环是否到达该层的最后一个节点
    int deep = 1; // 根节点为第一层
    int sum = 0; // 记录总的带权路径长度

    while (!(s.front == s.rear)) {
        // 队列非空时循环
        flag = s.rear;

        while (flag != s.front) {
            // 该层循环到达本层最后
            out_queue(&s, &p);
            if (p->left)
                enter_queue(&s, p->left);
            if (p->right)
                enter_queue(&s, p->right);
            if (p->left == NULL && p->right == NULL)
                sum += (deep * p->weight);
        }
        deep += 1;
    }
    return sum;
}

int main() {
    Tree t;
    // 1 1 2 -1 -1 3 -1 -1 1 4 -1 -1 -1
    build_tree(&t);
    printf("%d\n", WPL(t));

    return 0;
}
