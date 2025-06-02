//
// Created by sansan on 25-6-2.
//������1��������������ŵ���ͷ���ĵ�������
//����kʹ����������k��λ��
//��{0,1,2,3},k=1    ���ƽ��Ϊ{3,0,1,2}
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
    while (p = p->next)//������ôд��,��ϲ����ide���һ���ɫ������
        length++;
    return length;
}

void cyclerightShift(linklist* L, int k) {
    if (!(*L))
        return;

    if (length_list(*L) < k) {
        k = k % length_list((*L));
    }
    lnode* p = *L;//�ݴ�ͷ���
    int temp = length_list(*L) - k;//����k��length��ֵ,�����ƶ�ͷ���ָ��L
    while (temp--)
        *L = (*L)->next;
    lnode* r = (*L);//һֱѭ��������L��ĩβ,֮����p����
    while (r->next)
        r = r->next;
    r->next = p;
    lnode* search_tail = p;//search_tail����Ѱ�ҵ�L��ǰһ���ڵ�,��ΪNULL
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
