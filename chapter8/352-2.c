//
// Created by sansan on 25-9-26.
// 仅在数组中找到第k小的数
//

#include<stdio.h>

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

int quick_sort(int a[], int low, int high, int k) {
    if (low < high) {
        int pivot_pos = partition(a, low, high);
        if (pivot_pos == k)
            return a[pivot_pos];
        else if (pivot_pos > k)
            return quick_sort(a, low, pivot_pos - 1, k);
        else
            return quick_sort(a, pivot_pos + 1, high, k);
    }
    return -1;
}

int main() {
    int arr[] = {4, 2, 7, 1, 9, 5, 3, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 我们想找第 3 小的数。
    // 因为你的函数是基于数组索引（从0开始）来查找的，
    // 所以第 k 小的数对应的索引是 k-1。
    // 因此，要找第 3 小的数，我们需要传入索引 k = 2。
    int k_index = 2; // 目标索引 (3-1)

    int result = quick_sort(arr, 0, n - 1, k_index);

    if (result != -1) {
        // k_index + 1 是为了让输出更自然地显示“第3小”
        printf("数组中第 %d 小的数是: %d\n", k_index + 1, result);
    }
    else {
        printf("没有找到第 %d 小的数。\n", k_index + 1);
    }

    return 0;
}
