//
// Created by sansan on 25-9-25.
// 正反交替的冒泡排序
//

#include<stdio.h>

// 对low和high之间的数组进行一次排序,reverse为从左往右或者从右往左
void low_to_high_sort(int a[],int low,int high,int reverse) {
    if (low>=high)
        return;
    int temp;
    // reverse = 1 从左往右升序
    if (reverse) {
        for (;low<high;low++) {
            if (a[low]>a[low+1]) {
                temp=a[low];
                a[low]=a[low+1];
                a[low+1]=temp;
            }
        }
    }
    // reverse = 0 从右往左降序
    else {
        for (;low<high;high--) {
            if (a[high]<a[high-1]) {
                temp=a[high];
                a[high]=a[high-1];
                a[high-1]=temp;
            }
        }
    }
}
void alternating_bubble_sort(int a[],int n) {
    int i;
    int low=0,high=n-1;
    while (low<high) {
        low_to_high_sort(a,low,high,1);
        high-=1;
        low_to_high_sort(a,low,high,0);
        low+=1;

    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void cocktail_shaker_sort(int a[], int n) {
    int low=0,high=n-1;
    int temp;
    int flag=1; // 标识是否进行过交换
    while (low<high&&flag) {
        flag=0;
        for (int i=low;i<high;i++) {
            if (a[i]>a[i+1]) {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                flag= 1;
            }
        }
    }
    high--;
    for (int i=high;i>low;i--) {
        if (a[i]<a[i-1]) {
            temp=a[i];
            a[i]=a[i-1];
            a[i-1]=temp;
            flag=1;
        }
    }
    low++;
}

int main() {
    int arr[] = {6, 2, 8, 4, 10, 9, 1, 3, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    print_array(arr,n);
    cocktail_shaker_sort(arr,n);
    // alternating_bubble_sort(arr,n);
    print_array(arr,n);


    return 0;
}
