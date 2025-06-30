//

// Created by sansan on 25-6-28.

// 判断一个二叉树是否为完全二叉树

//



#include <stdio.h>

#include <stdlib.h>



#define MAXSIZE 100



typedef struct TreeNode {

    char data;

    struct TreeNode *lchild, *rchild;

} TreeNode, *Tree;



typedef struct queue {

    TreeNode *data[MAXSIZE];

    int front, rear;

} sq_queue;



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



int is_empty(sq_queue s) {

    if (s.front == s.rear)

        return 1;

    return 0;

}



int is_full(sq_queue s) {

    if (s.front == (s.rear + 1) % MAXSIZE)

        return 1;

    return 0;

}



int enter_queue(sq_queue *s, TreeNode *x) {

    if (is_full(*s))

        return 0;

    s->data[s->rear] = x;

    s->rear = (s->rear + 1) % MAXSIZE;

    return 1;

}



int out_queue(sq_queue *s, TreeNode **x) {

    if (is_empty(*s))

        return 0;

    *x = s->data[s->front];

    s->front = (s->front + 1) % MAXSIZE;

    return 1;

}



int is_complete_binary_tree(Tree t) {

    sq_queue s;

    s.front = s.rear = 0;

    int flag = 1;

    int ans = 1;

    if (t==NULL)

        ans=1;

    if (t->lchild==NULL&&t->rchild==NULL)

        ans=1;

    enter_queue(&s,t);

    TreeNode*p;

    while (!is_empty(s)) {

        out_queue(&s,&p);

        if (p->lchild==NULL) {

            out_queue(&s,&p);

            if (p->lchild==NULL) {

                flag=0;

                if (p->rchild)

                    ans=0;

            }

        }

        else {

            if (flag) {

                // 之前不存在缺孩子的节点

                enter_queue(&s,p->lchild);

                if (p->rchild)

                    enter_queue(&s,p->rchild);

                else

                    flag=0;

            }

            else

                ans=0;

        }

    }





    return ans;

}



int main() {

    //ABD##E##CF##G## 完全二叉树

    //ABD###CE##F## 非完全二叉树

    Tree t;

    build_tree(&t);

    if (is_complete_binary_tree(t))

        printf("yes\n");

    else

        printf("no\n");



}
