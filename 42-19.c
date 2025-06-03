//
// Created by sansan on 25-6-3.
//��������m������,|data|<=n
//�ڵ�Ϊ{data,link}
//Ҫ��ʱ�価���ܸ�Ч
//ֻ������һ�γ��ֵĽڵ�,�������������ֵĽڵ����һ�γ��ֵĽڵ����ֵ��ͬ,��ɾ��
//����:head -> 21 -> -15 -> -15 -> -7 -> 15 -> NULL
//���:head -> 21 -> -15 -> -7 -> NULL
//

#include<stdio.h>
#include<stdlib.h>

//������������,��СΪn+1
//��������ֵ���������Ӧλ����1
//֮����������ֵ��ͬ�Ľڵ�������,��Ϊ1����

typedef struct sqlist {
    int* data;
    int length;
} sqlist;

typedef struct lnode {
    int data;
    struct lnode* link;
} lnode, * linklist;

int n = 1000; //ȫ�ֱ���n

void buildlist(linklist* L, int a[], int length) {
    (*L) = (lnode*)malloc(sizeof(lnode));
    if (*L == NULL)
        return;
    lnode* s, * r = *L;
    for (int i = 0; i < length; i++) {
        s = (lnode*)malloc(sizeof(lnode));
        if (!s)
            return;
        s->data = a[i];
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

void saveabsvalue(linklist L, sqlist a) {
    if (!L || !L->link)
        return;

    //������ȫ����0
    for (int i = 0; i < n + 1; i++)
        a.data[i] = 0;
    lnode* p = L->link;
    lnode* pre = L;
    while (p) {
        if (a.data[abs(p->data)]) {//�������������м�¼�����ɾ����֧
            lnode* temp = p;
            p = p->link;
            pre->link = p;
            free(temp);
        }
        else {//������û�м�¼,�����ǵ�һ��ɨ�赽��ǰֵ,Ӧ����������
            a.data[abs(p->data)] = 1;
            pre = pre->link;
            p = p->link;
        }
    }
}

int main() {
    sqlist a;
    //��ʼ������a
    a.data = (int*)malloc(sizeof(int) * (n + 1));
    a.length = n + 1;
    int b[] = { 1, -9, 2, -8, 3, -7, 4, -6, 5, -5, 6, -4, 7, -3, 8, -2, 9, -1 };
    int b_size = sizeof(b) / sizeof(b[0]);

    linklist L = NULL;

    buildlist(&L, b, b_size);
    disp(L);

    //�������������
    saveabsvalue(L, a);

    disp(L);//һ�ι�,ţ��


    return 0;
}
