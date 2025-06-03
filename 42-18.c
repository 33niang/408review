//
// Created by sansan on 25-6-3.
//带头结点单链表保存单词
//两个单词有相同后缀时候共享存储空间
//str1和str2为两个头结点
//链表结构为{data,next}
//寻找公共部分的起始节点p
//

#include<stdio.h>
#include<stdlib.h>

typedef struct sqlist {
    char data[50]; //C99支持柔性数组,但是需要把data[]放到结构体最后,或者在前面指明数组大小
    int length;
} sqlist;

typedef struct lnode {
    char data;
    struct lnode* next;
} lnode, * linklist;

void buildlist(linklist* L, sqlist a) {
    *L = (lnode*)malloc(sizeof(lnode));
    if (*L == NULL)
        return;
    (*L)->data = 0; //单词用数字初始化很合理吧
    lnode* s, * r = (*L);
    for (int i = 0; i < a.length; i++) {
        s = (lnode*)malloc(sizeof(lnode));
        if (!s)
            return;
        s->data = a.data[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
}

void disp(linklist L) {
    if (!L || !L->next)
        return;
    lnode* p = L->next;
    while (p) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

int length_list(linklist L) {
    if (!L || !L->next)
        return 0;
    int length = 0;
    lnode* p = L->next;
    while (p) {
        p = p->next;
        length++;
    }
    return length;
}

lnode* find_node(linklist str1, linklist str2) {
    if (!str1 || !str2 || !str1->next || !str2->next)
        return NULL;
    lnode* p1 = str1;
    lnode* p2 = str2;
    int length1 = length_list(str1);
    int length2 = length_list(str2);
    int num;
    if (length1 > length2) { //判断长度大小准备移动指针
        num = length1 - length2;
        while (num--)
            p1 = p1->next;
    }
    else {
        num = length2 - length1;
        while (num--)
            p2 = p2->next;
    }
    while (p1) {
        if (p1->next == p2->next)
            return p1->next;
        p1 = p1->next;
        p2 = p2->next;
    }
    return NULL;
}

int main() {
    sqlist a = { "loading", 7 };
    sqlist b = { "be", 2 };
    linklist str1 = NULL;
    linklist str2 = NULL;
    buildlist(&str1, a);
    buildlist(&str2, b);
    printf("str1: ");
    disp(str1);
    printf("str2: ");
    //手动修改str2的尾指针,让其和str1有公共后缀
    str2->next->next->next = str1->next->next->next->next->next;
    disp(str2);
    printf("%c\n", find_node(str1, str2)->data);



    return 0;
}
