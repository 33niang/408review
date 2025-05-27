/*
���Ա�A[n]��Ԫ�ص�������
Ҫ��ʱ�����٣�Ѱ�����е���x��Ԫ��,
���ҵ����������Ԫ�ؽ�����
��û�ҵ����ͽ�����뵽˳����У������ֵ�������
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int data[MAXSIZE];
	int length;
}SqList;


void search(SqList *L, int x) {
	int left, right,mid;//�����±�
	left = 0;
	right = L->length - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (L->data[mid] == x)//�ҵ�x��λ��
			break;
		else if (L->data[mid] > x)//x���������Σ�����rightָ��
			right = mid - 1;
		else
			left = mid + 1;//x�������Ұ�Σ�����leftָ��
	}
	if (L->data[mid] == x && mid != L->length - 1) {//�ҵ�x��λ��,���һλԪ�ؽ���λ��
		int t = L->data[mid];
		L->data[mid] = L->data[mid + 1];
		L->data[mid + 1] = t;
	}
	if (left > right) {//û�ҵ�x��λ�ã����в���
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