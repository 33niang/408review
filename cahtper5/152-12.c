//
// Created by sansan on 25-7-2.
// 已知一个满二叉树的先序序列,求后序序列
//

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct TreeNode {
    char data;
    struct TreeNode *lchild, *rchild;
} TreeNode, *Tree;

// 把二叉树还原回去再输出后序,太简单不写了
void build_tree(Tree *t) {
    char ch;
    scanf(" %c", &ch);
    if (ch == '#')
        *t = NULL;
    else {
        (*t) = (TreeNode *) malloc(sizeof(TreeNode));
        (*t)->data = ch;
        (*t)->lchild = NULL;
        (*t)->rchild = NULL;
        build_tree(&(*t)->lchild);
        build_tree(&(*t)->rchild);
    }
}


void pre_to_post(char pre[], int pre_length_start, int pre_length_end, char post[], int post_length_start,int post_length_end) {
    int half;
    if (pre_length_start <= pre_length_end) {
        post[post_length_end] = pre[pre_length_start];
        half= (pre_length_end - pre_length_start) / 2;
        pre_to_post(pre, pre_length_start + 1, pre_length_start + half, post, post_length_start,post_length_start + half - 1);
        pre_to_post(pre, pre_length_start + half + 1, pre_length_end, post, post_length_start + half,post_length_end - 1);
    }
}

int main() {
    //ABD##E##C##
    char pre[8] = "ABDECFG";
    char post[8];
    pre_to_post(pre, 0, 6, post, 0, 6);
    for (int i = 0; i <= 6; i++)
        printf("%c ", post[i]);
    return 0;
}
