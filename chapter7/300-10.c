//
// Created by sansan on 25-9-21.
// 二叉排序树,有n个节点,查找第k(1<=k<=n)小的结点,并返回指针,
// 要求算法的平均时间复杂度为o(logn)
// 二叉树节点成员为data,lchild,rchild,count,count为以该节点为根的子树上的结点的个数
//

#include<stdio.h>
#include<stdlib.h>

typedef struct treenode {
    char data;
    struct treenode*lchild,*rchild;
    int count;
}treenode,*tree;


void buildtree(tree* t) {
    char ch;
    scanf(" %c", &ch);
    if (ch == '#') {
        *t = NULL;
    } else {
        *t = (treenode*)malloc(sizeof(treenode));
        (*t)->data = ch;
        (*t)->count = -1; // 暂时设置为-1,后序会用另一个函数为count赋值
        buildtree(&(*t)->lchild);
        buildtree(&(*t)->rchild);
    }
}

// 后序遍历递归为结点count赋值
int update_node_count(tree t) {
    if (t==NULL)
        return 0;
    int left_count=update_node_count(t->lchild);
    int right_count=update_node_count(t->rchild);
    t->count=left_count+right_count+1;
    return t->count;


}

treenode* search_min_k(tree t,int k) {
    if (t==NULL||k<1||k>t->count)
        return NULL;
    if (t->lchild==NULL) {
        if (k==1)
            return t;
        else
            return search_min_k(t->rchild,k-1);
    }
    else {
        if (t->lchild->count==k-1)
            return t;
        if (t->lchild->count>k-1)
            return search_min_k(t->lchild,k);
        if (t->lchild->count<k-1)
            return search_min_k(t->rchild,k-t->lchild->count-1);
    }
}

int main() {
    tree t;
    // M F C A # # # J G # # K # # T P # # W V # # Z # #
    buildtree(&t);
    update_node_count(t);
    printf("%c\n",search_min_k(t,3)->data);
    return 0;
}

//         M
//       /   \
//      /     \
//     F       T
//    / \     / \
//   C   J   P   W
//  /   / \     / \
//  A   G   K   V   Z
