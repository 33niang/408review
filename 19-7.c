/*
һά����A[m+n]�����������Ա�a[m]��b[n]
��дһ���㷨��a��b��ǰ��˳�򻥻� ����֮ǰA��a[m]+b[n],����A��b[n]+a[m]
��:m=4,n=3,A[m+n]=A[7]={1,2,3,,4,5,6,7},reverse֮����{5.6,7,1,2,3,4}
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int data[MAXSIZE];
	int length;
}SqList;

//left��right�������±�
void reverse(SqList* L, int left,int right) {
	if (L == NULL) {
		printf("��ָ��\n");
		return;
	}
	if (left > right) {
		printf("��Χ���Ϸ�\n");
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
	reverse(&A, 0, 6);//left �� right���±�
	printf("��������\n");
	print_sqlist(A);
	printf("��ǰn�ͺ�m���ֱ�����\n");//n=3,m=4
	reverse(&A, 0, 2);
	reverse(&A, 3, 6);
	print_sqlist(A);
}