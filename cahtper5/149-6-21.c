//
// Created by sansan on 25-6-28.
// 已知二叉树的先序和中序
// 还原二叉树
//

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode*lchild,*rchild;
}TreeNode,*Tree;

int pos =0;
Tree build(char a[],char b[],int start,int end) {
    if (start<=end) {
        TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
        root ->data=a[pos];
        int i;
        for (i=start;i<=end;i++)
            if (b[i]==root->data)
                break;
        pos++;
        root->lchild=build(a,b,start,i-1);
        root->rchild=build(a,b,i+1,end);
        return root;
    }
    return NULL;
}
void postOrderPrint(Tree t) {
    if (t) {
        postOrderPrint(t->lchild);
        postOrderPrint(t->rchild);
        printf("%c ", t->data);
    }
}

// 好难啊

int main() {

    //先序 ABDECF
    //中序 DBEAFC
    char a[]={'a','b','d','e','c','f'};
    char b[]={'d','b','e','a','f','c'};
    Tree root=build(a,b,0,5);
    printf("post_order:\n");
    postOrderPrint(root);
    return 0;
}
