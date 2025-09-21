//
// Created by sansan on 25-9-18.
// 求指定节点在二叉排序树中的层次
//

#include<stdio.h>
#include<stdlib.h>

typedef struct treenode {
    char data;
    struct treenode *lchild, *rchild;
} treenode, *tree;

void buildtree(tree *t) {
    char ch;
    scanf(" %c", &ch);
    if (ch == '#')
        *t = NULL;
    else {
        (*t) = (treenode *) malloc(sizeof(treenode));
        (*t)->data = ch;
        (*t)->lchild = NULL;
        buildtree(&(*t)->lchild);
        buildtree(&(*t)->rchild);
    }
}

int search_node_high(tree t, treenode *p) {
    int level = 1; // 根节点是第一层
    treenode *tt = t;
    while (tt) {
        if (tt->data == p->data)
            return level;
        else if (tt->data > p->data)
            tt = tt->lchild;
        else
            tt = tt->rchild;
        level++;
    }
    return -1; // 没找到
}


int main() {
    tree t;
    // FECA#B##D###HG##I##
    buildtree(&t);
    printf("%d\n",search_node_high(t,t->lchild->lchild->lchild->rchild));

    return 0;
}
