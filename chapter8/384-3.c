//
// Created by sansan on 25-10-3.
// 一个无序关键序列k,k2.......kn
// 将kn放在元素排序后的正确位置上,
// 要求比较元素此树不超过n
//

#include<stdio.h>

void search_kn_postion(int a[],int n) {
    int pos=0;
    for (int i=0;i<n-1;i++)
        if (a[i]<a[n-1])
            pos++;

    int temp;
    temp=a[n-1];
    a[n-1]=a[pos];
    a[pos]=temp;
    return;
}

int main() {



    return 0;
}
