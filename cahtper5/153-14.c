//
// Created by sansan on 25-7-2.
// 判断二叉树是否相似
// 其实就是树形长得一样
//


#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct TreeNode {
    char data;
    struct TreeNode *lchild, *rchild;
} TreeNode, *Tree;

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

// 先序遍历判断是否相似
int is_similar_tree(Tree t1,Tree t2) {
    if (t1==NULL&&t2==NULL)
        return 1;

    // 到了这一步t1和t2不可能同为NULL,故只判断他俩是否有一个为NULL,则另一个必不为NULL
    if (t1==NULL||t2==NULL)
        return 0;

    return is_similar_tree(t1->lchild,t2->lchild)&&is_similar_tree(t1->rchild,t2->rchild);
}

int main(){
    Tree t1;
    // ABDBC##D##E##E##CF##G##
    build_tree(&t1);

    Tree t2;
    build_tree(&t2);

    if (is_similar_tree(t1,t2))
        printf("similar\n");
    else
        printf("no similar\n");
    return 0;
}
