/*
һ���������У���n��Ԫ�أ�����г���n/2������ͬԪ�أ���Ϊ��Ԫ�أ�
����Ԫ���Ƿ���ڣ������ڵ��ڼ�
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int data[MAXSIZE];
	int length;
}SqList;

int half(SqList L, int* num) {
	if (L.length == 0)
		return 0;
	int c = L.data[0];
	int count = 1;
	int i;
	for (i = 1; i < L.length; i++) {
		if (L.data[i] == c)
			count++;
		else {
			if (count > 0)
				count--;
			else {
				c = L.data[i];
				count = 1;
			}
		}
	}
	int k = 0;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] == c)
			k++;
	}
	if (k > L.length / 2) {
		*num = c;
		return 1;
	}
	return 0;
}
int main()
{
	SqList a = { {0,5,5,3,5,7,5,5},8 };
	SqList b = { {0,5,5,3,5,1,5,7},8 };

	int num;
	if (half(a, &num))
		printf("%d\n", num);
	else
		printf("no search\n");

	if (half(b, &num))
		printf("%d\n", num);
	else
		printf("no search\n");

	return 0;
}