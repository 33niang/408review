//
// Created by sansan on 25-6-22.
// 二叉树顺序存储
// 求i和j节点最近的公共祖先
//

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    int data;
    int is_empty;//-1为空
}TreeNode;

//初始化tree
void init_tree(TreeNode a[], int n) {
    for (int i = 0; i < n ; i++) {
        a[i].data = 0;
        a[i].is_empty = -1;
    }
}
int search_node(TreeNode a[], int i, int j) {
    if (a[i].is_empty == -1 || a[j].is_empty == -1)
        return 0;
    while (i != j) {//判断i和j的大小,大的/2,直到i==j
        if (i > j)
            i = i / 2;
        else
            j = j / 2;
    }
    return i;

}

int main() {
    //创建一个大小为n+1的数组,a[0]空着
    const int SIZE = 16;
    TreeNode tree[16];

    // 初始化树
    init_tree(tree, SIZE);

    // 填充一些测试数据 (完全二叉树)
    for (int i = 1; i < SIZE; i++) {
        tree[i].data = i;
        tree[i].is_empty = 0; // 标记为非空
    }

    // 测试用例1: 兄弟节点
    int lca = search_node(tree, 4, 5);
    printf("LCA of 4 and 5 is: %d\n", lca); // 应该输出2

    // 测试用例2: 不同层的节点
    lca = search_node(tree, 7, 2);
    printf("LCA of 7 and 2 is: %d\n", lca); // 应该输出1

    // 测试用例3: 一个节点是另一个的祖先
    lca = search_node(tree, 1, 3);
    printf("LCA of 1 and 3 is: %d\n", lca); // 应该输出1

    // 测试用例4: 无效节点
    tree[6].is_empty = -1; // 将节点6标记为空
    lca = search_node(tree, 6, 12);
    printf("LCA of 6(empty) and 12 is: %d\n", lca); // 应该输出0并打印错误


    return 0;
}
