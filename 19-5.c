/*
有序顺序表L  (默认升序)
删除其中所有重复的值x
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int a[MAXSIZE];
	int length;
}SqList;

int deletelist(SqList *L) {
    if (L == NULL)
        return 0;
    if (L->length <= 1)//长度为1或0，必无重复元素
        return 1;
    int black = 0;//设置黑指针指向当前元素
    int red;   //设置红指针指向需要和黑指针比较的元素，若不同，就把红指针的元素指向黑指针的下一个位置
    for (red=1; red < L->length; red++) {
        if (L->a[red] != L->a[black]) {
            black++;
            L->a[black] = L->a[red];
        }
    }
    L->length = black + 1;
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
    L.a[1] = 2;
    L.a[2] = 3;
    L.a[3] = 3;
    L.a[4] = 3;
    L.a[5] = 5;
    L.a[6] = 6;
    L.a[7] = 7;
    L.a[8] = 7;
    L.a[9] = 7;

    L.length = 10;
    


    print_sqlist(L);

    if (deletelist(&L))
        print_sqlist(L);
    else
        printf("no\n");

    return 0;
}