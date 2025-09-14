//
// Created by sansan on 25-9-14.
// 判断一个二叉树是否为二叉排序树
//


#include<stdio.h>
#include<stdlib.h>
typedef struct treenode {
    char data;
    struct treenode *lchild,*rchild;
}treenode,*tree;

void buildtree(tree *t) {
    char ch;
    scanf("%c",&ch);
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


int pre=-99999;
int is_ok(tree t) {
    if (t==NULL)
        return 1;
    else {
        int bl=is_ok(t->lchild);
        if (bl==0||t->data<=pre)
            return 0;
        pre=t->data;
        return is_ok(t->rchild);
    }
}

int main() {
    tree t;
    // FECA#B##D###HG##I##
    buildtree(&t);
    printf("%d\n",is_ok(t));

    return 0;
}
