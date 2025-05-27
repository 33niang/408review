/*
长度为L的升序序列S
第L/2(向上取整)位置的数为中位数
给定等长序列S1和S2
求S1和S2合并之后的中位数
时间,空间复杂度尽可能优秀
例如:S1={11,13,15,17,19},S2={2,4,6,8,20},中位数为11
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int data[MAXSIZE];
	int length;
}SqList;

//无需建立辅助数组的方法稍微有点麻烦，还是怎么简单怎么来吧
void search(SqList S1, SqList S2) {
	int i = 0;
	int a[MAXSIZE] = { 0 };//辅助数组
	int len = (S1.length + S2.length) / 2;//象征性求一下长度,其实就是length
	int s1 = 0, s2 = 0;//双指针标识两个数组
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