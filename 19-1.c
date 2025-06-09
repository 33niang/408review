/*
从顺序表删除唯一的最小值，并且返回删除的值。
删除的位置由最后一个元素填补。
若表为空，返回错误信息
*/
 
#include<stdio.h>

#define MAXSIZE 50

typedef struct SqList {
	int a[MAXSIZE];
	int length;
}SqList;

int DeleteMin(SqList* L,int* e) {
    if (L == NULL || e == NULL) {
        printf("空指针\n");
        return 0;
    }
    if (L->length == 0) {
        printf("空数组\n");
        return 0;
    }
    int min = L->a[0];
    int flag = 0;
    int i = 0;
    for (i = 1; i < L->length; i++) {
        if (L->a[i] < min) {
            flag = i;
            min = L->a[i];
        }
    }
    *e = min;
    //把最后一个元素放到最小值的位置上
    L->a[flag] = L->a[L->length - 1];
    L->length--;
    return 1;
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

    int i = 0;
    printf("之前");
    for (i = 0; i < L.length; i++) {
        printf("%d ", L.a[i]);
    }
    printf("\n");
    int e=0;
    if (DeleteMin(&L, &e)) {

        printf("之后");
        for (i = 0; i < L.length; i++) {
            printf("%d ", L.a[i]);
        }
        printf("\n");
        printf("最小值为%d", e);
    }
    else {
        printf("error\n");
    }

    return 0;
}
