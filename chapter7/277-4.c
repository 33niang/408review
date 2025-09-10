//
// Created by sansan on 25-9-10.
// 递归实现折半查找
//

#include<stdio.h>

#define MAX_SIZE 50

typedef struct ST {
    int a[MAX_SIZE];
    int length;
} ST;

// 默认s递增
int recursion_binary_search(ST s, int key, int low, int high) {
    if (low > high)
        return -1;
    int mid = low+(high - low) / 2; // 不用low+high是为了防止low和high过大时候溢出
    if (s.a[mid] == key)
        return mid;
    else if (s.a[mid] < key)
        return recursion_binary_search(s, key, mid + 1, high);
    else
        return recursion_binary_search(s, key, low, mid - 1);
}

int main() {
    ST s = {{0, 1, 2, 3, 4, 5, 6, 7, 8}, 9};
    int result=recursion_binary_search(s, 100,0,8);
    if (result==-1)
        printf("not found\n");
    else
        printf("第%d个位置\n",result);


    return 0;
}
