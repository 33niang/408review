/*
要求将顺序表L所有元素逆置
时间复杂度为o(1)
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int a[MAXSIZE];
	int length;
}SqList;

