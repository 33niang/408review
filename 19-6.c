/*
���������ϲ���һ���µ������
Ĭ������
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int a[MAXSIZE];
	int length;
}SqList;

int merge(SqList L, SqList M, SqList* N) {

    int i=0, j=0, k=0;//i,j��ΪL��M���±꣬k��ΪN���±�
    if ((L.length + M.length) > MAXSIZE)//��ֹ�ϲ�֮���������
        return 0;
    //��������L��M��length>0�����=0�����while֮����жϣ�ֱ�ӷ�����ȷ���
    while (i<L.length && j<M.length) {
        if (L.a[i] <= M.a[j])
            N->a[k++] = L.a[i++];
        else
            N->a[k++] = M.a[j++];
    }
    if (i == L.length)//L���鶼������
        for (j; j < M.length; j)
            N->a[k++] = M.a[j++];
    else if (j == M.length)//M���鶼������
        for (i; i < L.length; i++)
            N->a[k++] = L.a[i];//����ط�֮ǰд����a++������˰���û������������һ��i��j ��������
    N->length = k;

    return 1;
}

void print_sqlist(SqList L) {
    int i = 0;
    for (i; i < L.length; i++) {
        printf("%d ", L.a[i]);
    }
    printf("\n");
}
int main() 
{
    SqList L;
    L.a[0] = 1;
    L.a[1] = 3;
    L.a[2] = 5;
    L.a[3] = 7;
    L.a[4] = 9;
    L.length = 5;

    SqList M;
    M.a[0] = 2;
    M.a[1] = 4;
    M.a[2] = 6;
    M.length = 3;

    print_sqlist(L);
    print_sqlist(M);

    SqList N;//���ܺϲ�֮���������
    N.length = 0;
    if (merge(L, M, &N))
        print_sqlist(N);
    printf("%d", N.length);
    return 0;
}
