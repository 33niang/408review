/*
两个有序表合并成一个新的有序表
默认升序
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int a[MAXSIZE];
	int length;
}SqList;

int merge(SqList L, SqList M, SqList* N) {

    int i=0, j=0, k=0;//i,j作为L和M的下标，k作为N的下标
    if ((L.length + M.length) > MAXSIZE)//防止合并之后数组过大
        return 0;
    //无需特判L和M的length>0，如果=0会进入while之后的判断，直接返回正确结果
    while (i<L.length && j<M.length) {
        if (L.a[i] <= M.a[j])
            N->a[k++] = L.a[i++];
        else
            N->a[k++] = M.a[j++];
    }
    if (i == L.length)//L数组都用完了
        for (j; j < M.length; j)
            N->a[k++] = M.a[j++];
    else if (j == M.length)//M数组都用完了
        for (i; i < L.length; i++)
            N->a[k++] = L.a[i];//这个地方之前写成了a++，检查了半天没检查出来，导致一个i和j 加了两次
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

    SqList N;//接受合并之后的新数组
    N.length = 0;
    if (merge(L, M, &N))
        print_sqlist(N);
    printf("%d", N.length);
    return 0;
}
