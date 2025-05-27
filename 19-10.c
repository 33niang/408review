/*
n个整数,n＞1，将其放到一维数组R中
将R中保存的元素左移p个位置
p=3,R={1,2,3,4,5,6,7}
1234567->4567123
*/

#include <stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int data[MAXSIZE];
	int length;
}SqList;

void reverse(SqList* L, int l, int r) {
	if (l > r)
		return;
	int i;
	int temp;
	for (i = l; i <= (l + r) / 2; i++) {
		temp = L->data[r + l - i];
		L->data[r + l - i] = L->data[i];
		L->data[i] = temp;
	}
}

void print_sqlist(SqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}
void change(SqList* L, int p) {
	reverse(L,0, p-1);
	printf("0-2\n");
	print_sqlist(*L);
	reverse(L, p, L->length - 1);
	printf("3-6\n");
	print_sqlist(*L);
	reverse(L,0, L->length-1);
	printf("0-6\n");
	print_sqlist(*L);
}

int main()
{
	SqList L = { {1,2,3,4,5,6,7},7 };
	//p=3
	change(&L, 3);
	printf("结果\n");
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
	
	return 0;
}