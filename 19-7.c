/*
一维数组A[m+n]中有两个线性表a[m]和b[n]
编写一个算法将a和b的前后顺序互换 ，即之前A是a[m]+b[n],现在A是b[n]+a[m]
例:m=4,n=3,A[m+n]=A[7]={1,2,3,,4,5,6,7},reverse之后是{5.6,7,1,2,3,4}
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int data[MAXSIZE];
	int length;
}SqList;

//left和right是数组下标
void reverse(SqList* L, int left,int right) {
	if (L == NULL) {
		printf("空指针\n");
		return;
	}
	if (left > right) {
		printf("范围不合法\n");
		return;
	}
	int i;
	int temp;
	for (i = left; i < (left + right) / 2; i++) {
		temp = L->data[left + right - i];
		L->data[left + right - i] = L->data[i];
		L->data[i] = temp;
	}
}

void print_sqlist(SqList L) {
	int i = 0;
	for (i; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}

int main()
{
	SqList A = { {1,2,3,4,5,6,7},7 };
	print_sqlist(A);
	reverse(&A, 0, 6);//left 和 right是下标
	printf("整体逆置\n");
	print_sqlist(A);
	printf("把前n和后m个分别逆置\n");//n=3,m=4
	reverse(&A, 0, 2);
	reverse(&A, 3, 6);
	print_sqlist(A);
}