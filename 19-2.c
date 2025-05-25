/*
顺序表L长度为n
要求时间复杂度o(n),空间复杂度o(1)
删除表中所有值为x的元素 
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int a[MAXSIZE];
	int length;
}SqList;



