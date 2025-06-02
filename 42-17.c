//
// Created by sansan on 25-6-3.
// ����ͷ��������Ѱ�ҵ�����k���ڵ��ֵ
// ��û�ҵ�����0;�ҵ�����1,�����data
//


#include <stdio.h>
#include<stdlib.h>

typedef struct sqlist {
    int data[50];
    int length;
} sqlist;

typedef struct lnode {
    int data;
    struct lnode* link;
} lnode, * linklist;

void buildlist(linklist* L, sqlist a) {
    (*L) = (lnode*)malloc(sizeof(lnode));
    (*L)->data = 0;
    (*L)->link = NULL; //����ط�����ʼ���ᱻgrok˵��
    lnode* s, * r = (*L);
    for (int i = 0; i < a.length; i++) {
        s = (lnode*)malloc(sizeof(lnode));
        s->data = a.data[i];
        r->link = s;
        r = r->link;
    }
    r->link = NULL;
}

void disp(linklist L) {
    if (!L || !L->link)
        return;
    lnode* p = L->link;
    while (p) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n");
}

int search_k(linklist L, int k) {
    if (k <= 0)
        return 0;
    if (!L || !L->link)
        return 0;
    lnode* prior = L->link, * last = L->link;
    int flag = k;
    while (flag--) {
        prior = prior->link;
        if (prior == NULL)
            return 0;
    }
    while (prior) {
        prior = prior->link;
        last = last->link;
    }
    printf("%d\n", last->data);
    return 1;
}

int main() {
    sqlist a = { {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 10 };
    linklist L = NULL;
    buildlist(&L, a);
    disp(L);

    if (search_k(L, 1)) {
        printf("�ɹ�\n");
    }
    else {
        printf("ʧ��\n");
    }

    return 0;
}
