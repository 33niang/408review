/*
����˳���L
����s,t,��s<t
ɾ��ֵ��s��t֮���Ԫ�أ�����s,t��
��s,t��С�������˳���Ϊ�գ����ش�����Ϣ
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int a[MAXSIZE];
	int length;
}SqList;

int deletesqlist(SqList* L, int s, int t) {
    if (s >= t) {
        printf("��Χ���Ϸ�\n");
        return 0;
    }
    if (L == NULL || L->length == 0) {
        printf("˳�����ʧ�ܻ���˳���Ϊ��\n");
        return 0;
    }
    int k = 0;
    int i = 0;
    for (i = 0; i < L->length; i++) {
        if (L->a[i] >= s && L->a[i] <= t)
            k++;
        else {
            L->a[i - k] = L->a[i];
        }

    }
    L->length -= k;
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

    int s= 2;
    int t= 4;

    print_sqlist(L);
    if (deletesqlist(&L, s, t))
        print_sqlist(L);
    else
        printf("ʧ��\n");
	return 0;
}
