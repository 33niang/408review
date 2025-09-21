//
// Created by sansan on 25-9-21.
// 遍历二叉树判断是否为平衡二叉树
//

#include <ctype.h>
#include<stdio.h>
#include<stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct treenode {
    char data;
    struct treenode*lchild,*rchild;
}treenode,*tree;


void buildtree(tree *t) {
    char ch;
    scanf(" %c",&ch);
    if (ch == '#')
        (*t)=NULL;
    else {
        (*t)=(treenode*)malloc(sizeof(treenode));
        (*t)->data=ch;
        (*t)->lchild=NULL;
        (*t)->rchild=NULL;
        buildtree(&(*t)->lchild);
        buildtree(&(*t)->rchild);
    }
}

// 你可以在 #include 后面加上这个宏定义
#define max(a, b) ((a) > (b) ? (a) : (b))

void is_avl(tree t, int *ba, int *h) {
    int h1, h2, b1, b2; // 用于接收左右子树的高度和平衡因子
    if (t == NULL) {
        *h = 0;
        *ba = 1;
    }
    else if (t->lchild == NULL && t->rchild == NULL) {
        *h = 1;
        *ba = 1;
    }
    else {
        // 递归调用，获取左右子树的高度和平衡状态
        is_avl(t->lchild, &b1, &h1);
        is_avl(t->rchild, &b2, &h2);

        // 计算当前节点的高度
        *h = max(h1, h2) + 1;

        // 判断当前节点是否平衡
        if (abs(h1 - h2) <= 1) {
            // 当前节点平衡，则整个树的平衡状态取决于左右子树的平衡状态
            *ba = b1 && b2;
        }
        else {
            // 当前节点不平衡，则整个树不平衡
            *ba = 0;
        }
    }
}

int main() {
    tree t;
    // FECA#B##D###HG##I##
    buildtree(&t);
    int ba,h;
    is_avl(t,&ba,&h);
    printf("%d\n",ba);

    return 0;

}
