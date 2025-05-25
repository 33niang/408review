/*
顺序表L长度为n
要求时间复杂度o(n),空间复杂度o(1)
删除所有值为x的元素
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
    int k = 0;//对数组L中有多少个x进行计数，方便后续元素前移
    int i = 0;//循环变量
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
        printf("失败\n");
    }

}