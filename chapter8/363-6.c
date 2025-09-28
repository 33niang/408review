//
// Created by sansan on 25-9-29.
// 判断一个数据序列是否为小根堆
//

#include <stdio.h>
#include <string.h> // 为了使用 memcpy

typedef struct sqlist {
    int data[100];
    int length;
}sqlist;

// 数组下标为0的地方不填入值,从1开始计数
int Is_Min_Heap(sqlist l) {
    if (l.length==0)
        return 0;
    if (l.length==1)
        return 1;
    for (int i=1;i<=l.length/2;i++) {
        if ((i*2+1)<=l.length) {
            if (l.data[i]>l.data[2*i]||l.data[i]>l.data[2*i+1])
                return 0;
        }
        else
            if (l.data[i]>l.data[2*i])
                return 0;

        }
    return 1;
}

int main() {
    // --- Test Case 1: This is a min heap ---
    sqlist heap_yes;
    int data1[] = {0, 10, 20, 15, 30, 40, 18}; // data[0] is unused
    heap_yes.length = sizeof(data1) / sizeof(data1[0]) - 1; // length is 6
    memcpy(heap_yes.data, data1, sizeof(data1));

    if (Is_Min_Heap(heap_yes)) {
        printf("Sequence 1 is a min heap.\n");
    } else {
        printf("Sequence 1 is NOT a min heap.\n");
    }

    // --- Test Case 2: This is NOT a min heap ---
    // Parent node 25 > right child 20, violates the property
    sqlist heap_no;
    int data2[] = {0, 10, 25, 15, 30, 20}; // data[0] is unused
    heap_no.length = sizeof(data2) / sizeof(data2[0]) - 1; // length is 5
    memcpy(heap_no.data, data2, sizeof(data2));

    if (Is_Min_Heap(heap_no)) {
        printf("Sequence 2 is a min heap.\n");
    } else {
        printf("Sequence 2 is NOT a min heap.\n");
    }

    // --- Test Case 3: A heap with only one element ---
    sqlist heap_one;
    int data3[] = {0, 100};
    heap_one.length = 1;
    memcpy(heap_one.data, data3, sizeof(data3));
    if (Is_Min_Heap(heap_one)) {
        printf("Sequence 3 is a min heap.\n");
    } else {
        printf("Sequence 3 is NOT a min heap.\n");
    }

    return 0;
}
