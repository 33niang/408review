//
// Created by sansan on 25-7-2.
// 将给定二叉树转换为中缀表达式
// 通过括号反应计算次序
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char data[10];
    struct node *left, *right;
} BTree;

void build_tree(BTree **t) {
    char ch[10];
    scanf(" %s", ch);
    if (strcmp(ch, "#") == 0)
        (*t) = NULL;
    else {
        (*t) = (BTree *) malloc(sizeof(BTree));
        strcpy((*t)->data, ch);
        (*t)->left = (*t)->right = NULL;
        build_tree(&(*t)->left);
        build_tree(&(*t)->right);
    }
}

void to_in_order(BTree *t, int deep) {
    if (t == NULL)
        return;
    else if (t->left == NULL && t->right == NULL)
        printf("%s", t->data);
    else {
        if (deep > 1)
            printf("(");
        to_in_order(t->left, deep + 1);
        printf("%s", t->data);
        to_in_order(t->right, deep + 1);
        if (deep > 1)
            printf(")");
    }
}

int main() {
    BTree *t;
    // 这里的例子加空格是因为scanf读取的是%s,不是%c,不加空格会将一长串字符都读到一个ch里
    // * + a # # b # # * c # # - # d # #
    // + * a # # b # # - # - c # # d # #
    build_tree(&t);
    to_in_order(t,1);

    return 0;
}
