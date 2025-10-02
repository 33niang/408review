//
// Created by sansan on 25-10-1.
// 数组a[],其中元素存储在下标1~n+m的位置
// 前m个元素递增有序,后n个元素递增有序
// 使得整个顺序表有序
//

#include<stdio.h>

void sort_sqlist(int a[],int m,int n) {
    int i=1;
    int j=m+1;
    int k=1;
    int b[m+n+1];
    for (i=1;i<=m+n;i++)
        b[i]=a[i];
    i=1;
    while (i<=(m)&&j<=(m+n)) {
        if (b[i]<b[j])
            a[k++]=b[i++];
        else if (b[i]==b[j])
            a[k++]=b[i++];
        else
            a[k++]=b[j++];
    }
    while (i<=m)
        a[k++]=b[i++];
    while (j<=m+n)
        a[k++]=b[j++];
}

int main() {
    int a[8]={-1,1,3,5,7,2,4,9};
    int m=4;
    int n=3;
    sort_sqlist(a,m,n);
    for (int i=0;i<8;i++)
        printf("%d ",a[i]);
    return 0;
}
