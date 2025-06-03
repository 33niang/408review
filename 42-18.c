//
// Created by sansan on 25-6-3.
//��ͷ��㵥�����浥��
//������������ͬ��׺ʱ����洢�ռ�
//str1��str2Ϊ����ͷ���
//����ṹΪ{data,next}
//Ѱ�ҹ������ֵ���ʼ�ڵ�p
//

#include<stdio.h>
#include<stdlib.h>

typedef struct sqlist {
    char data[50]; //C99֧����������,������Ҫ��data[]�ŵ��ṹ�����,������ǰ��ָ�������С
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
    (*L)->data = 0; //���������ֳ�ʼ���ܺ����
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
    if (length1 > length2) { //�жϳ��ȴ�С׼���ƶ�ָ��
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
    //�ֶ��޸�str2��βָ��,�����str1�й�����׺
    str2->next->next->next = str1->next->next->next->next->next;
    disp(str2);
    printf("%c\n", find_node(str1, str2)->data);



    return 0;
}
