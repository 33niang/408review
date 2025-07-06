//
// Created by sansan on 25-7-7.
// 编程求孩子兄弟表示法存储的森林的叶子结点个数
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

int leaf_number(CSTree t) {
    if (t == NULL)
        return 0;
    if (t->firstchild == NULL)
        return 1 + leaf_number(t->nextsibling);
    else
        return leaf_number(t->firstchild) + leaf_number(t->nextsibling);

}
int main() {
    CSTree t;
    // ABD#E##C##FG###
    build_CSTree(&t);
    printf("%d\n",leaf_number(t));

    return 0;
}
