//
// Created by sansan on 25-10-3.
// 实现计数排序,比方有k个值比a[i]小,则将b[k]位置设置为a[i]
//

#include<stdio.h>

// 假设待排序所有值>=0
void count_sort(int a[],int b[],int n) {
    for (int i=0;i<n;i++) {
        int count=0;
        for (int j=0;j<n;j++) {
            if (a[j]<a[i])
                count++;
        }
        b[count]=a[i];
    }
}

int main() {
    int a[6]={3,5,7,2,4,9};
    int b[6];
    count_sort(a,b,6);
    for (int i=0;i<6;i++)
        printf("%d ",b[i]);

    return 0;
}
