/*
����ΪL����������S
��L/2(����ȡ��)λ�õ���Ϊ��λ��
�����ȳ�����S1��S2
��S1��S2�ϲ�֮�����λ��
ʱ��,�ռ临�ӶȾ���������
����:S1={11,13,15,17,19},S2={2,4,6,8,20},��λ��Ϊ11
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int data[MAXSIZE];
	int length;
}SqList;

//���轨����������ķ�����΢�е��鷳��������ô����ô����
void search(SqList S1, SqList S2) {
	int i = 0;
	int a[MAXSIZE] = { 0 };//��������
	int len = (S1.length + S2.length) / 2;//��������һ�³���,��ʵ����length
	int s1 = 0, s2 = 0;//˫ָ���ʶ��������
	while (i <= len - 1) {
		if (S1.data[s1] <= S2.data[s2])
			a[i++] = S1.data[s1++];
		else
			a[i++] = S2.data[s2++];
	}

	printf("%d\n", a[len-1]);
}
int main()
{
	SqList S1 = { {11,13,15,17,19},5 };
	SqList S2 = { {2,4,6,8,20},5 };
	search(S1, S2);

}