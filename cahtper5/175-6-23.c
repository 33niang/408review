//
// Created by sansan on 25-7-7.
// 已知一棵树的层次序列以及每个节点的度
// 构造此树的孩子兄弟链表
//

#include<stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *leftchild,*rightbrother;
}TreeNode,*Tree;

void create(Tree *t, char e[], int degree[], int n) {
    // 1. 分配一个指针数组，大小为 n，而不是固定的 10
    Tree* point = (Tree*)malloc(n * sizeof(Tree));

    // 2. 为每个节点分配空间并初始化
    for (int i = 0; i < n; i++) {
        point[i] = (TreeNode*)malloc(sizeof(TreeNode));
        point[i]->data = e[i];
        point[i]->leftchild = point[i]->rightbrother = NULL;
    }

    int k = 0; // k 指向即将成为孩子节点的那个节点在层次序列中的下标
    for (int i = 0; i < n; i++) { // i 遍历所有可能的父节点
        int d = degree[i];
        if (d > 0) { // 如果当前节点有孩子
            k++; // k 指向第一个孩子
            point[i]->leftchild = point[k];
            // 连接所有兄弟节点
            for (int j = 2; j <= d; j++) {
                k++; // k 指向下一个孩子
                point[k - 1]->rightbrother = point[k];
            }
        }
    }

    // 3. 修正：通过解引用 *t 来修改 main 函数中的 t
    *t = point[0];

    // 4. 修正：只释放辅助的指针数组，树的节点不释放
    free(point);
}

void disp(Tree t) {
    if (t) {
        printf("%c ",t->data);
        disp(t->leftchild);
        disp(t->rightbrother);
    }
}

int main() {
    Tree t;
    char e[8]="ABCDEFG";
    int degree[8]={3,2,1,0,0,0,0};
    create(&t,e,degree,7);
    disp(t);

    return 0;
}

