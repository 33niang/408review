//
// Created by sansan on 25-6-30.
// 二叉树左右子树交换
//


#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode*lchild,*rchild;
}TreeNode,*Tree;

void build_tree(Tree *t) {
    char ch;
    scanf(" %c",&ch);
    if (ch=='#')
        *t=NULL;
    else {
        (*t)=(TreeNode*)malloc(sizeof(TreeNode));
        (*t)->data=ch;
        (*t)->lchild=NULL;
        (*t)->rchild=NULL;
        build_tree(&(*t)->lchild);
        build_tree(&(*t)->rchild);
    }
}

// 后序遍历并且交换左右子树
void exchange_left_and_right_subtrees(Tree t) {
    if (t==NULL)
        return;
    exchange_left_and_right_subtrees(t->lchild);
    exchange_left_and_right_subtrees(t->rchild);

    TreeNode* temp=t->rchild;
    t->rchild=t->lchild;
    t->lchild=temp;
}

// 后序遍历用来验证结果
void post_disp_tree(Tree t) {
    if (t==NULL)
        return;
    post_disp_tree(t->lchild);
    post_disp_tree(t->rchild);
    printf(" %c ",t->data);
}
int main() {
    Tree t;
    //ABD##E##CF##G##
    build_tree(&t);
    exchange_left_and_right_subtrees(t);
    post_disp_tree(t);

    return 0;
}
