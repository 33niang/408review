/*
Ҫ��˳���L����Ԫ������
�ռ临�Ӷ�Ϊo(1)
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
    int a[MAXSIZE];
    int length;
}SqList;


int reverse(SqList* L) {
    if (L == NULL) {
        printf("��ָ��\n");
        return 0;
    }
    int i = 0;
    int temp;
    for (i = 0; i < L->length / 2; i++) {
        temp = L->a[L->length - i - 1];
        L->a[L->length - i - 1] = L->a[i];
        L->a[i] = temp;
    }
    return 1;
}

void print_sqlist(SqList L) {
    int i = 0;
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.a[i]);
    }
    printf("\n");
}
int main()
{
    SqList L;
    L.a[0] = 2;
    L.a[1] = 3;
    L.a[2] = 5;
    L.a[3] = 7;
    L.a[4] = 1;
    L.a[5] = 9;
    L.a[6] = 8;
    L.a[7] = 55;
    L.length = 8;

    print_sqlist(L);
    if (reverse(&L) == 0) {
        printf("ʧ��\n");
    }
    else {
        print_sqlist(L);
    }
    return 0;
}

