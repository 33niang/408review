/*
给定顺序表L
给定s,t,有s<t
删除值在s到t之间的元素（包括s,t）
若s,t大小不合理或顺序表为空，返回错误信息
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int a[MAXSIZE];
	int length;
}SqList;

int deletesqlist(SqList* L, int s, int t) {
    if (s >= t) {
        printf("范围不合法\n");
        return 0;
    }
    if (L == NULL || L->length == 0) {
        printf("顺序表传入失败或者顺序表为空\n");
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
        printf("失败\n");
	return 0;
}
