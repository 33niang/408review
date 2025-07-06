//
// Created by sansan on 25-7-7.
// 孩子兄弟链表为存储结构,递归求树的深度
//


#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    char data;
    struct node*firstchild,*nextsibling;
}CSNode,*CSTree;

void build_CSTree(CSTree *t) {
    char ch;
    scanf(" %c",&ch);
    if (ch=='#')
        *t=NULL;
    else {
        (*t)=(CSNode*)malloc(sizeof(CSNode));
        (*t)->data=ch;
        (*t)->firstchild=NULL;
        (*t)->nextsibling=NULL;
        build_CSTree(&(*t)->firstchild);
        build_CSTree(&(*t)->nextsibling);
    }
}

int tree_height(CSTree t) {
    if (t==NULL)
        return 0;
    else
        return tree_height(t->firstchild)+1>tree_height(t->nextsibling)?tree_height(t->firstchild)+1:tree_height(t->nextsibling);
}

int main() {
    CSTree t;
    // ABD#E##CF####
    build_CSTree(&t);
    printf("height=%d\n",tree_height(t));

    return 0;
}
