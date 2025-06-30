//
// Created by sansan on 25-7-1.
// 求先序遍历中第k的节点的值,已知节点总数
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

// 用指针传递一个k,防止值传递造成k值"回退"
void pre_order_visit_tree_search_k(Tree t,int *k) {
    if (t == NULL||*k<=0) // 到达叶子结点或者k<=0跳出循环
        return;
    (*k)--; // 因为k在这里-1,所以第一个和第二个if不会冲突
    if (*k==0)
        printf("第k个值为%c\n",t->data);
    // printf("%c ", t->data);
    pre_order_visit_tree_search_k(t->lchild,k);
    pre_order_visit_tree_search_k(t->rchild,k);
}


int main() {
    Tree t;
    // ABD##E##CF##G##
    build_tree(&t);

    int k=3;
    pre_order_visit_tree_search_k(t,&k);
    if (k>0)
        printf("k值过大\n");
    return 0;

}
