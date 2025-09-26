//
// Created by sansan on 25-9-27.
// 有n(n>=2)个正整数构成的集合A={ak|0<=k<n}
// 将其划分为两个不相交的子集，元素个数分别为n1和n2
// A1和A2中元素和为S1和S2
// 设计算法使得|n1-n2|最小，且|S1-S2|最大
//

#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    while (low < high) {
        while (low < high && pivot <= a[high])
            high--;
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

// 找到枢轴==k-1即可
void set_partition(int a[], int n) {
    int k = n / 2;
    int low = 0, high = n - 1;

    while (low < high) {
        int pivot_pos = partition(a, low, high);

        if (pivot_pos == k - 1)
            return;
        else if (pivot_pos < k - 1)
            low = pivot_pos + 1;

        else
            high = pivot_pos - 1;
    }
}

int main() {
    int a[] = {10, 2, 8, 5, 9, 1, 7, 4, 6, 3};
    int n = sizeof(a) / sizeof(a[0]);

    // 调用函数对数组进行划分
    set_partition(a, n);

    // ----- 划分完成后，再进行计算和打印 -----
    int k = n / 2;
    long long s1 = 0;
    long long s2 = 0;

    printf("集合 A1 (前 %d 个最小的数): ", k);
    for (int i = 0; i < k; i++) {
        s1 += a[i];
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("集合 A2 (后 %d 个最大的数): ", n - k);
    for (int i = k; i < n; i++) {
        s2 += a[i];
        printf("%d ", a[i]);
    }
    printf("\n\n");

    printf("S1 的和 = %lld\n", s1);
    printf("S2 的和 = %lld\n", s2);
    printf("|S1 - S2| 的最大值为: %lld\n", llabs(s1 - s2));

    return 0;
}
