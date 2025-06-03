//
// Created by sansan on 25-6-2.
//单链表有环
//编写算法判断单链表是否有环
//默认有头结点,省事
//
//如果题目允许修改链表结构给链表加一个freq域就好了,直接跑一遍就知道有没有了
//

#include<stdio.h>
#include <stdlib.h>

typedef struct lnode {
    int data;
    struct lnode* next;
} lnode, * linklist;

typedef struct {
    int data[50];
    int length;
} sqlist;

void buildlist(linklist* L, sqlist a) {
    (*L) = (lnode*)malloc(sizeof(lnode));
    if (!(*L))
        return;
    lnode* r = (*L);
    for (int i = 0; i < a.length; i++) {
        lnode* s = (lnode*)malloc(sizeof(lnode));
        s->data = a.data[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
}

void deletelist(linklist* L) {
    lnode* p = (*L)->next;
    while (p) {
        lnode* temp = p;
        p = p->next;
        free(temp);
    }
    (*L)->next = NULL;
}

void disp(linklist L) {
    if (!L)
        return;
    if (L->next == NULL) {
        printf("空\n");
        return;
    }
    int counter = 90; //测试使用,防止输出过长
    lnode* p = L->next;
    while (p && counter--) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void loop_list(linklist L) {
    //测试函数,仅用于生成循环链表,不用写的太严格,能用就行

    lnode* p = L->next;
    for (int i = 0; i < 10; i++)
        p = p->next;
    lnode* r = p;
    while (r->next != NULL)
        r = r->next;
    r->next = p;
}

int slow_and_fast(linklist L) {
    if (!L)
        return 0;
    if (L->next == NULL) //防止访问->next->next 报错
        return 0;
    if (L->next->next == L->next) //有一个节点且为环
        return 1;
    lnode* slow = L->next;
    lnode* fast = L->next->next;
    while (fast && fast->next) {
        if (slow == fast)
            return 1;
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
}

int main() {
    sqlist a = { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, 20 };
    linklist L = NULL;
    buildlist(&L, a);
    disp(L);

    if (slow_and_fast(L))
        printf("have\n");
    else
        printf("no\n");
    //deletelist(&L);

    loop_list(L);
    disp(L);

    if (slow_and_fast(L))
        printf("have");
    else
        printf("no");
    deletelist(&L);


    return 0;
}
