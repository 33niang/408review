/*
寻找一个数组中未出现的最小的正数
例:
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
	//可能出现的结果一定在1到length+1之间
	//开辟一个辅助数组,下标从1开始,有可能出现的结果最大为length+1
	if (L.length == 0) {
		printf("传个带值的进来\n");
		return;
	}
	if (L.length > MAXSIZE-2) {
		printf("原数组过大\n");
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


	SqList test1 = { {-5, 3, 2, 3}, 4 }; // 应输出1
	SqList test2 = { {1, 2, 3, 4}, 4 };  // 应输出5
	SqList test3 = { {2, 3, 4}, 3 };     // 应输出1
	SqList test4 = { {1, 1, 1}, 3 };     // 应输出2
	SqList test5 = { {}, 0 };            // 空数组测试

	printf("测试1: "); SearchMin(test1);
	printf("测试2: "); SearchMin(test2);
	printf("测试3: "); SearchMin(test3);
	printf("测试4: "); SearchMin(test4);
	printf("测试5: "); SearchMin(test5);
	return 0;
}