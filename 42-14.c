//
// Created by sansan on 25-6-2.
//将大于1个数量的整数存放到无头结点的单链表中
//输入k使得链表右移k个位置
//例{0,1,2,3},k=1    右移结果为{3,0,1,2}
//

#include<stdio.h>
#include<stdlib.h>

typedef struct lnode {
    int data;
    struct lnode* next;
} lnode, * linklist;

typedef struct sqlist {
    int data[50];
    int length;
} sqlist;

void buildlist(linklist* L, sqlist a) {
    (*L) = (lnode*)malloc(sizeof(lnode));
    if (!(*L))
        return;
    (*L)->data = a.data[0];
    lnode* s;
    lnode* r = *L;
    for (int i = 1; i < a.length; i++) {
        s = (lnode*)malloc(sizeof(lnode));
        s->data = a.data[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
}

void disp(linklist L) {
    if (!L)
        return;
    lnode* p = L;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int length_list(linklist L) {
    if (!L)
        return 0;
    int length = 1;
    lnode* p = L;
    while (p = p->next)//故意这么写的,就喜欢看ide给我画橙色波浪线
        length++;
    return length;
}

void cyclerightShift(linklist* L, int k) {
    if (!(*L))
        return;

    if (length_list(*L) < k) {
        k = k % length_list((*L));
    }
    lnode* p = *L;//暂存头结点
    int temp = length_list(*L) - k;//计算k和length差值,用来移动头结点指针L
    while (temp--)
        *L = (*L)->next;
    lnode* r = (*L);//一直循环到现在L的末尾,之后与p相连
    while (r->next)
        r = r->next;
    r->next = p;
    lnode* search_tail = p;//search_tail用来寻找到L的前一个节点,置为NULL
    while (search_tail->next != (*L))
        search_tail = search_tail->next;
    search_tail->next = NULL;
}

int main() {
    linklist L = NULL;
    sqlist a = { {1, 2, 3, 4, 5,6,7,8,9,10}, 10 };
    buildlist(&L, a);
    disp(L);
    printf("L's length = %d\n", length_list(L));
    cyclerightShift(&L, 5);
    disp(L);
    return 0;
}
