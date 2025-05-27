/*
给定三个序列A,B,C,长度均为n
序列内无重复元素且递增
设计一个时间上尽量高效的算法,逐行输出三个序列内重复的元素
例:A={1,2,3},B={2,3,4},C={-1,0,2},输出2
*/

#include<stdio.h>
#define MAXSIZE 50

typedef struct SqList {
	int data[MAXSIZE];
	int length;
}SqList;

//二分查找
int search(SqList L, int x) {
	int left, right, mid;
	left = 0;
	right = L.length - 1;
	while (left <= right) {
		mid = (left + right) / 2; 
		if (L.data[mid] == x)//找到返回1
			return 1;
		else if (L.data[mid] > x)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return 0;
}
//寻找三个顺序表中相同的元素
void findequal(SqList  L1, SqList L2,SqList L3) {
	int i;//第一个表的循环变量
	for (i = 0; i < L1.length; i++) {
		if(search(L2,L1.data[i]) && search(L3,L1.data[i]))
			printf("%d ",L1.data[i]);
	}
	printf("\n");
}

//三指针法
void FindCommonElements(SqList L1, SqList L2, SqList L3) {
	int i = 0, j = 0, k = 0;
	while (i < L1.length && j < L2.length && k < L3.length) {
		if (L1.data[i] == L2.data[j] && L2.data[j] == L3.data[k]) {
			printf("%d\n", L1.data[i]);
			i++, j++, k++;
		}
		else if (L1.data[i] < L2.data[j])//else if里面不用三个全比较一遍，这三个会慢慢蛄蛹前进
			i++;
		else if (L2.data[j] < L3.data[k])
			j++;
		else if (L3.data[k] < L1.data[i])
			k++;
	}
	printf("\n");
}
int main()
{
	SqList L1 = { {2, 5, 8, 10, 12, 15, 18, 20, 22, 25}, 10 };
	SqList L2 = { { 1, 5, 9, 10, 13, 15, 17, 20, 23, 25 }, 10 };
	SqList L3 = { { 3, 5, 10, 12, 15, 16, 20, 21, 25, 30 },10 };
	//未找到元素的特判懒得写了,反正题目也没说
	findequal(L1, L2, L3);//两次二分法,o(nlogn)

	FindCommonElements(L1, L2, L3);//三指针法,o(1)
	return 0;
}