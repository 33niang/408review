/*
给定三元组(a,b,c)的距离D=|a-b|+|b-c|+|c-a|
三个集合S1,S2,S3,按照升序分别存储在三个数组里
计算所有有可能的三元组(a,b,c)(a∈S1,b∈S2,c∈S3}
*/

#include<stdio.h>
#include<math.h>
#define MAX 0x7fffffff
int my_abs(int a) {
	return a < 0 ? -a : a;
}

int min(int a, int b) {
	return a < b ? a : b;
}
int my_min(int a, int b, int c) {
	if (min(a, min(b, c)) == a)
		return 1;
	return 0;
}

int my_find_min(int a[], int b[], int c[], int na, int nb, int nc) {
	int i = 0, j = 0, k = 0, ans = MAX;
	while (i < na && j < nb && k < nc && ans>0) {
		int v = my_abs(a[i] - b[j]) + my_abs(b[j] - c[k]) + my_abs(c[k] - a[i]);
		if (v < ans)
			ans = v;
		if (my_min(a[i], b[j], c[k]))
			i++;
		else if (my_min(b[j], a[i], c[k]))
			j++;
		else if (my_min(c[k], a[i], b[j]))
			k++;
	}
	return ans;
}
int main()
{
	int a[3] = { -1,0,9 };
	int b[4] = { -25,-10,10,11 };
	int c[5] = { 2,9,17,30,41 };
	int na = 3, nb = 4, nc = 5;
	printf("%d\n", my_find_min(a, b, c, 3, 4, 5));

	return 0;
}