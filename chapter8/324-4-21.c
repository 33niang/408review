//
// Created by sansan on 25-9-26.
// 修改快速排序,每次选词pivot是随机选择
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a,int *b) {
    int temp=*b;
    *b=*a;
    *a=temp;
}
int partition(int a[],int low,int high) {
    int root=low+rand()%(high-low+1);
    swap(&a[low],&a[root]);
    int i=low;
    int pivot=a[low];
    for (int j=low+1;j<=high;j++) {
        if (a[j]<pivot) {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[low],&a[i]);
    return i;
}

void quicksort(int a[],int low,int high) {
    if (low<high) {
        int pivot_pos=partition(a,low,high);
        quicksort(a,low,pivot_pos-1);
        quicksort(a,pivot_pos+1,high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 初始化随机数生成器
    srand((unsigned int)time(NULL));

    quicksort(arr, 0, n - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

