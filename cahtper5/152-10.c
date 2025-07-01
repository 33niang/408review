//
// Created by sansan on 25-7-1.
// 二叉树中有p,q任意两个指针,指向任意两个节点
// 编写算法找到p和q的最近公共祖先节点
//

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    struct TreeNode *LLINK;
    char INFO;
    struct TreeNode *RLINK
} TreeNode, *Tree;

void build_tree(Tree *t) {
    char ch;
    scanf(" %c", &ch);
    if (ch == '#')
        *t = NULL;
    else {
        (*t) = (TreeNode *) malloc(sizeof(TreeNode));
        (*t)->INFO = ch;
        (*t)->LLINK = NULL;
        (*t)->RLINK = NULL;
        build_tree(&(*t)->LLINK);
        build_tree(&(*t)->RLINK);
    }
}

// 分别寻找p和q的路径,然后用两个数组保存路径再从根节点逐一比较

//先序寻找节点p的所有ancestors
int search_path(Tree t, TreeNode *p, TreeNode *path[], int *path_length) {
    if (t == NULL)
        return 0;
    path[*path_length] = t;
    (*path_length)++;
    if (t == p)
        return 1;

    if (search_path(t->LLINK, p, path, path_length))
        return 1;
    if (search_path(t->RLINK, p, path,path_length))
        return 1;
    (*path_length)--;

    return 0;
}

Tree find_recently_ancestors_node(Tree t, TreeNode *p, TreeNode *q) {
    if (t == NULL)
        return NULL;
    // 创建两个数组存储路径
    TreeNode *path_p[100];
    int length_p = 0;
    TreeNode *path_q[100];
    int length_q = 0;

    search_path(t, p, path_p, &length_p);
    search_path(t, q, path_q, &length_q);

    int i = 0;
    while (i < length_p && i < length_q && path_p[i] == path_q[i])
        i++;
    if (i == 0)
        return NULL;
    else
        return path_p[i - 1];
}

// 查找节点指针,方便验证
Tree find_node(Tree t, char data) {
    if (t == NULL)
        return NULL;
    if (t->INFO == data)
        return t;
    TreeNode *found = find_node(t->LLINK, data);
    if (found)
        return found;
    return find_node(t->RLINK, data);
}

// 后序遍历递归法
// 这个方法更难想了,还是第一种方法简单
Tree find(Tree t,TreeNode*p,TreeNode *q) {
    if (t==NULL||t==p||t==q) {
        return t;
    }
    Tree left_found=find(t->LLINK,p,q);
    Tree right_found=find(t->RLINK,p,q);
    if (left_found&&right_found)
        return t;
    return (left_found!=NULL)?left_found:right_found;
}
int main() {
    Tree ROOT;
    // ABD##E##C##
    build_tree(&ROOT);
    TreeNode *p = find_node(ROOT, 'D');
    TreeNode *q = find_node(ROOT, 'E');

    Tree lca = find_recently_ancestors_node(ROOT, p, q);
    if (lca) {
        printf("节点 %c 和 %c 的最近公共祖先是: %c\n", p->INFO, q->INFO, lca->INFO);
    } else {
        printf("未找到公共祖先。\n");
    }
    printf("p和q最近的祖先是:%c\n",find(ROOT,p,q)->INFO);
    return 0;
}
