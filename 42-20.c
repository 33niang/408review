//
// Created by sansan on 25-6-4.
// ��ͷ����a1...an
// �������б��a1,an,a2,an-1......
// Ҫ��:�ռ临�Ӷ�o(1),�����ܿ�
//

#include<stdio.h>
#include<stdlib.h>

typedef struct lnode {
    int data;
    struct lnode* next;
} NODE;

int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int n = 9;

void buildlist(NODE** L) {
    (*L) = (NODE*)malloc(sizeof(NODE));
    (*L)->next = NULL;
    (*L)->data = a[0];
    NODE* s, * r = *L;

    for (int i = 1; i < n; i++) {
        s = (NODE*)malloc(sizeof(NODE));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
}

void disp(NODE* L) {
    if (!L)
        return;
    NODE* p = L;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

NODE* reverselist(NODE* L) {//reverse��һ������,Ȼ�����ǰ���
    if (!L)
        return NULL;
    if (!L->next)
        return NULL;
    //ͷ�巨����
    NODE* p = L, * r = NULL;
    NODE* temp;
    while (p) {
        temp = p;
        p = p->next;
        temp->next = r;
        r = temp;
    }
    return r;
}
void ReArrange(NODE* L) {
    if (!L || !L->next)
        return;
    NODE* slow = L, * fast = L;//���ÿ���ָ���������һ��
    while (fast->next && fast) {
        slow = slow->next;
        fast = fast->next->next;
    }

    NODE* list2 = reverselist(slow->next);
    slow->next = NULL;
    //������L��list2������,������Ҫ��list2�������L
    int num = 1;
    NODE* p = L;
    NODE* temp;//��list2���뵽temp����
    NODE* q = list2;
    while (q) {
        temp = p->next;
        p->next = q;
        q = q->next;
        p->next->next = temp;
        p = temp;
    }

}
int main() {
    NODE* L = NULL;
    buildlist(&L);
    disp(L);
    ReArrange(L);
    disp(L);
    return 0;
}