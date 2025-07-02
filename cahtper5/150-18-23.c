//
// Created by sansan on 25-7-2.
// 中序线索二叉树中查找指定节点在前驱节点的算法
//

// 若指定节点有rchild,则前驱为rchild
// 若指定节点有lchild,则前驱为lchild
// 若指定节点为中序序列第一个节点,即前线索为NULL,则前驱为NULL
// 若没有lchild和rchild,找ancestor的lchild
// 其他情况 前驱为NULL

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *lchild, *rchild;
    int ltag, rtag;
} TreeNode, *Tree;

void build_tree(Tree *t) {
    char ch;
    scanf(" %c", &ch);
    if (ch == '#')
        *t = NULL;
    else {
        (*t) = (TreeNode *) malloc(sizeof(TreeNode));
        (*t)->data = ch;
        (*t)->ltag = (*t)->rtag = 0;
        (*t)->lchild = (*t)->rchild = NULL;
        build_tree(&(*t)->lchild);
        build_tree(&(*t)->rchild);
    }
}

// 中序线索化
void mid_sequence_clusterization(Tree *t, TreeNode **pre) {
    if (*t) {
        // 左子树线索化
        mid_sequence_clusterization(&(*t)->lchild, pre);
        if ((*t)->lchild == NULL) {
            (*t)->ltag = 1;
            (*t)->lchild = *pre;
        } else
            (*t)->ltag = 0;

        if ((*pre) != NULL && (*pre)->rchild == NULL) {
            (*pre)->rtag = 1;
            (*pre)->rchild = (*t);
        }
        *pre = (*t); // 更新前驱
        mid_sequence_clusterization(&(*t)->rchild,pre);
    }
}

// 找后序序列指定节点的前驱
Tree search_pre_node_in_post(Tree t,TreeNode*p) {
    TreeNode*q;
    if (p->rtag==0)
        q=p->rchild;
    else if (p->ltag==0)
        q=p->lchild;
    else if (p->lchild==NULL)
        q=NULL;
    else {
        while (p->ltag==1&&p->lchild)
            p=p->lchild;
        if (p->ltag==0)
            q=p->lchild;
        else
            q=NULL;
    }
    return q;
}

int main() {
    Tree t;
    // ABD##E##CF##G##
    build_tree(&t);

    TreeNode* pre=NULL;
    mid_sequence_clusterization(&t,&pre);

    printf("%c\n",search_pre_node_in_post(t,t->rchild)->data);

    return 0;
}
