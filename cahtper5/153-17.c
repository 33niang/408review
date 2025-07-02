//
// Created by sansan on 25-7-3.
// 非空二叉树T的节点值均为正整数
// 采用顺序存储
// T中不存在的节点在数组SqBiTNode用-1表示
// 判断T是否为二叉搜索树(左子树上的值都小于根节点,右子树上的所有值都大于根节点)

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <limits.h>
#define MAX_SIZE 100

typedef struct {
    int SqBiTNode[MAX_SIZE];
    int ElemNum;
} SqBiTree;

//
bool is_BST(SqBiTree t, int i,int min,int max) {
    // i为当前要判断的节点的数组下标,min为当前节点允许的最小值,max为当前节点允许的最大值
    if (i>=t.ElemNum||t.SqBiTNode[i]==-1)
        return 1;
    int current=t.SqBiTNode[i];
    if (current>=max||current<=min)
        return 0;
    // 递归检查左右子树
    return is_BST(t,2*i+1,min,current)&&is_BST(t,2*i+2,current,max);
}



int main() {


    SqBiTree tree1 = {0};
    for(int i = 0; i < MAX_SIZE; i++) tree1.SqBiTNode[i] = -1;

    // 手动构建一个树
    tree1.SqBiTNode[0] = 5;
    tree1.SqBiTNode[1] = 3;
    tree1.SqBiTNode[2] = 8;
    tree1.SqBiTNode[3] = 1;
    tree1.SqBiTNode[4] = 4;
    tree1.SqBiTNode[5] = 6;
    tree1.SqBiTNode[6] = 9;
    tree1.ElemNum=7;
    

    if (is_BST(tree1,0,0,INT_MAX)) {
        printf("Tree 1 是一个二叉搜索树。\n");
    } else {
        printf("Tree 1 不是一个二叉搜索树。\n");
    }


    return 0;
}
