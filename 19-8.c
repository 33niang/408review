/*
线性表A[n]内元素递增有序
要求时间最少，寻找其中等于x的元素,
若找到，就与后续元素交换，
若没找到，就将其插入到顺序表中，并保持递增有序
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int data[MAXSIZE];
	int length;
}SqList;


void search(SqList *L, int x) {
	int left, right,mid;//数组下标
	left = 0;
	right = L->length - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (L->data[mid] == x)//找到x的位置
			break;
		else if (L->data[mid] > x)//x可能在左半段，更新right指针
			right = mid - 1;
		else
			left = mid + 1;//x可能在右半段，更新left指针
	}
	if (L->data[mid] == x && mid != L->length - 1) {//找到x的位置,与后一位元素交换位置
		int t = L->data[mid];
		L->data[mid] = L->data[mid + 1];
		L->data[mid + 1] = t;
	}
	if (left > right) {//没找到x的位置，进行插入
		int i;
		for (i = L->length - 1; i > right+1; i--) {
			L->data[i + 1] = L->data[i];
		}
		L->data[i + 1] = x;
		L->length += 1;
	}
}
int main()
{
	SqList A = { {1,2,3,4,5,6,8,9,10}, 9 };
	search(&A, 7);
	for (int i = 0; i < A.length; i++) {
		printf("%d ", A.data[i]);
	}
	printf("\n");
	return 0;
}