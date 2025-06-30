//
// Created by sansan on 25-7-1.
// 删除二叉树中每个值为x的节点及其孩子
//

#include<stdio.h>
#include<stdlib.h>

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

//删除当前节点以及其子树
void delete_current_node(Tree *t) {
    if (t == NULL || *t == NULL)
        return;
    delete_current_node(&(*t)->lchild);
    delete_current_node(&(*t)->rchild);
    free(*t);
    (*t) = NULL;
}

// 后序遍历删除值为x的节点以及子树
void delete_x_node(Tree *t, char x) {
    if (t == NULL||(*t)==NULL)
        return;

    delete_x_node(&(*t)->lchild, x);
    delete_x_node(&(*t)->rchild, x);
    // 这里删除当前节点无需记录pre节点防止"断链",
    // 因为t的来源是父节点的左右指针的地址,并不是左右指针指向的节点地址,
    // delete_current_node最后已经把(*t)=NULL了,已经完成了孩子节点置空这一操作
    if ((*t)->data==x)
        delete_current_node(t);
}

// 后序遍历用来验证结果
void post_disp_tree(Tree t) {
    if (t == NULL)
        return;
    post_disp_tree(t->lchild);
    post_disp_tree(t->rchild);
    printf(" %c ", t->data);
}

int main() {
    Tree t;
    // ABDBC##D##E##E##CF##G##
    build_tree(&t);
    delete_x_node(&t, 'D');
    post_disp_tree(t);

    return 0;
}
