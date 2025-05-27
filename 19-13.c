/*
Ѱ��һ��������δ���ֵ���С������
��:
{2,3,4}->1
{1,2,3}->4
*/
#include<stdio.h>
#define MAXSIZE 50
typedef struct SqList {
	int data[MAXSIZE];
	int length;
}SqList;

void SearchMin(SqList L) {
	//���ܳ��ֵĽ��һ����1��length+1֮��
	//����һ����������,�±��1��ʼ,�п��ܳ��ֵĽ�����Ϊlength+1
	if (L.length == 0) {
		printf("������ֵ�Ľ���\n");
		return;
	}
	if (L.length > MAXSIZE-2) {
		printf("ԭ�������\n");
		return;
	}
	int a[MAXSIZE] = { 0 };
	int i;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] > 0 && L.data[i] <= L.length + 1) {
			a[L.data[i]] = 1;
		}
	}
	for (i = 1; i <= L.length+1; i++) {
		if (a[i] == 0)
			break;
	}
	printf("%d\n", i);
}
int main()
{
	SqList L = { {-5,3,2,3},4 };
	SearchMin(L);
	SqList L1 = { {1,2,3,4},4 };	
	SearchMin(L1);


	SqList test1 = { {-5, 3, 2, 3}, 4 }; // Ӧ���1
	SqList test2 = { {1, 2, 3, 4}, 4 };  // Ӧ���5
	SqList test3 = { {2, 3, 4}, 3 };     // Ӧ���1
	SqList test4 = { {1, 1, 1}, 3 };     // Ӧ���2
	SqList test5 = { {}, 0 };            // ���������

	printf("����1: "); SearchMin(test1);
	printf("����2: "); SearchMin(test2);
	printf("����3: "); SearchMin(test3);
	printf("����4: "); SearchMin(test4);
	printf("����5: "); SearchMin(test5);
	return 0;
}