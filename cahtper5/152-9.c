//
// Created by sansan on 25-7-1.
// 在二叉树中查找所有值为x的节点,打印x节点的所有祖先
// 假设x的值不多于1个
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

// flag指针广播法
void search_parent_node(Tree t, char x, int *flag) {
    if (t == NULL)
        return;
    if (*flag == 1)
        return;
    if (t->data == x)
        *flag = 1;
    search_parent_node(t->lchild, x, flag);
    search_parent_node(t->rchild, x, flag);
    if (*flag == 1 && t->data != x)
        printf("%c ", t->data);
}

// 向上传递法,查找当前节点的孩子是否有x,若有则打印当前孩子
int find_and_print_ancestors(Tree t, char x) {
    if (t == NULL)
        return 0;
    if (t->data == x)
        return 1;
    // 如果当前节点的左右孩子有任意一个返回了1,则打印
    if (find_and_print_ancestors(t->lchild, x) || find_and_print_ancestors(t->rchild, x)) {
        printf("%c ", t->data);
        // 继续向上传递找到x的信息
        return 1;
    }
    // 若没找到孩子,则默认返回0
    return 0;
}

// 栈输出法
// 就这个方法最绕`(*>﹏<*)′
typedef struct {
    TreeNode* t;
    int tag; // 标志当前节点的左右子树是否被访问过
}stack;

void use_stack_print_ancestors(Tree t,char x) {
    //创建一个stack
    stack s[100];
    int top=-1;
    while (t!=NULL||top>-1) {
        while (t!=NULL&&t->data!=x) {
            s[++top].t=t;
            s[top].tag=0;
            t=t->lchild;
        }

        if (t!=NULL&&t->data==x) {
            printf("ancestors: ");
            for (int i=0;i<=top;i++) {
                printf("%c ",s[i].t->data);
            }
            return ;
        }

        while (top!=-1&&s[top].tag==1) {
            top--;
        }

        if (top!=-1) {
            s[top].tag=1;
            t=s[top].t->rchild;
        }
    }
}
int main() {
    Tree t;
    // ABDBC##D##E##E##CF##G##
    build_tree(&t);
    char x = 'F';
    int flag = 0; // 判断是否找到x节点以及控制是否递归
    search_parent_node(t, x, &flag);
    printf("\n");
    find_and_print_ancestors(t, x);
    printf("\n");
    use_stack_print_ancestors(t,x);
    return 0;
}

//
//        A
//     /     \
//    B       C
//  D   E   F   G
// /\  / \ / \ / \
// H I G K L M N  O
//
