//
// Created by sansan on 25-9-10.
// 线性表(顺序表/链表)各结点被查找概率不等
// 若找到指定的节点,就与其前驱节点交换,使得经常被查找的节点位于表的前端
//

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50

typedef struct sqlist {
    int data[MAX_SIZE];
    int length;
} sqlist;

typedef struct lnode {
    int data;
    struct lnode *next;
} lnode, *linklist;

void buildlist(linklist *L, sqlist a) {
    (*L) = (lnode *) malloc(sizeof(lnode));
    if (!(*L))
        return;
    lnode *r = (*L), *s;
    for (int i = 0; i < a.length; i++) {
        s = (lnode *) malloc(sizeof(lnode));
        if (!s)
            return;
        s->data = a.data[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
}

void disp(linklist l) {
    if (l == NULL)
        return;
    if (l->next == NULL)
        return;
    lnode *p = l->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int search_and_exchange_sqlist(sqlist *l, int key) {
    for (int i = 0; i < l->length; i++)
        if (l->data[i] == key && i != 0) {
            // 若找到并且不是第0个元素,则交换
            int temp = l->data[i];
            l->data[i] = l->data[i - 1];
            l->data[i - 1] = temp;
            return 1;
        }
    return 0;
}

int search_and_exchange_linklist(linklist *l, int key) {
    if (*l == NULL || (*l)->next == NULL || (*l)->next->next == NULL)
        return 0;
    if ((*l)->next->data==key)
        return 1;
    lnode *pre_pre = *l;
    lnode *pre = (*l)->next;
    lnode *p = pre->next;
    while (p) {
        if (p->data == key) {
            // 交换pre和p
            pre_pre->next = p;
            pre->next=p->next;
            p->next = pre;
            return 1;
        }
        pre_pre = pre_pre->next;
        pre = pre->next;
        p = p->next;
    }
}

int main() {
    // --- Sequential List Test ---
    sqlist l = {{1, 2, 3, 4, 5, 6, 7, 8}, 8};
    printf("Original sequential list data: ");
    for (int i = 0; i < l.length; i++)
        printf("%d ", l.data[i]);
    printf("\n");

    int result = search_and_exchange_sqlist(&l, 8);
    if (result) {
        printf("After finding 8 and swapping in the sequential list: ");
        for (int i = 0; i < l.length; i++)
            printf("%d ", l.data[i]);
        printf("\n");
    }

    // --- Linked List Test ---
    printf("\n--- Linked List Test ---\n");
    linklist l2;
    // Create a new sequential list for the linked list test
    sqlist l_for_link = {{1, 2, 3, 4, 5}, 5};
    buildlist(&l2, l_for_link);

    printf("Original linked list data: ");
    disp(l2);

    int key_to_find = 5;
    result = search_and_exchange_linklist(&l2, key_to_find);
    if (result) {
        printf("After finding %d and swapping in the linked list: ", key_to_find);
        disp(l2);
    }

    // Search for the same number again to see if it moves further forward
    result = search_and_exchange_linklist(&l2, key_to_find);
    if (result) {
        printf("After finding %d again and swapping: ", key_to_find);
        disp(l2);
    }

    return 0;
}
