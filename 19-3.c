/*
˳���L����Ϊn
Ҫ��ʱ�临�Ӷ�o(n),�ռ临�Ӷ�o(1)
ɾ������ֵΪx��Ԫ��
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int a[MAXSIZE];
	int length;
}SqList;

int DeleteX(SqList* L, int x) {
    if (L == NULL||L->length==0)
        return 0;
    int k = 0;//������L���ж��ٸ�x���м������������Ԫ��ǰ��
    int i = 0;//ѭ������
    for (i = 0; i < L->length; i++) {
        if (L->a[i] == x)
            k++;
        else
            L->a[i - k] = L->a[i];
    }
    L->length = L->length - k;
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
    L.a[0] = 5;
    L.a[1] = 2;
    L.a[2] = 0;
    L.a[3] = 1;
    L.a[4] = 3;
    L.a[5] = 1;
    L.a[6] = 4;
    L.a[7] = 1;
    L.a[8] = 1;
    L.a[9] = 4;
    L.length = 10;

    print_sqlist(L);
    if (DeleteX(&L, 1)) {
        print_sqlist(L);
    }
    else {
        printf("ʧ��\n");
    }

}