//
// Created by sansan on 25-9-21.
// 设计算法,求出给定二叉排序书中最小和最大的关键字
//

#include<stdio.h>
#include<stdlib.h>

typedef struct treenode {
    char data;
    struct treenode *lchild,*rchild;
}treenode,*tree;

void buildtree(tree*t) {
    char ch;
    scanf(" %c",&ch);
    if (ch=='#')
        *t=NULL;
    else {
        *t=(treenode*)malloc(sizeof(treenode));
        (*t)->data=ch;
        (*t)->lchild=NULL;
        (*t)->rchild=NULL;
        buildtree(&(*t)->lchild);
        buildtree(&(*t)->rchild);
    }
}


void search_small_and_big(tree t) {
    treenode *p=t;
    // min
    while (p->lchild)
        p=p->lchild;
    printf("min = %c\n",p->data);
    // max
    p=t;
    while (p->rchild)
        p=p->rchild;
    printf("max = %c\n",p->data);
}
int main() {
    tree t;
    // FECA#B##D###HG##I##
    buildtree(&t);
    search_small_and_big(t);

    return 0;
}
