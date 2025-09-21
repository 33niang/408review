//
// Created by sansan on 25-9-21.
// 从二叉排序树中输出值不小于k的关键字
//

#include <ctype.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct treenode {
    char data;
    struct treenode *lchild, *rchild;
} treenode, *tree;

void buildtree(tree *t) {
    char ch;
    scanf(" %c", &ch);
    if (ch == '#') {
        *t = NULL;
    } else {
        *t = (treenode *) malloc(sizeof(treenode));
        (*t)->data = ch;
        (*t)->lchild = NULL;
        (*t)->rchild = NULL;
        buildtree(&(*t)->lchild);
        buildtree(&(*t)->rchild);
    }
}

void print_dayudengyu_k(tree t, char key) {
    if (!t)
        return;
    if (t->rchild != NULL)
        print_dayudengyu_k(t->rchild, key);
    if (t->data >= key)
        printf("%c ", t->data);
    if (t->lchild != NULL)
        print_dayudengyu_k(t->lchild, key);
}

int main() {
    tree t;
    // FECA#B##D###HG##I##
    buildtree(&t);
    print_dayudengyu_k(t,'E');


    return 0;
}
