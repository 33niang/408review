//
// Created by sansan on 25-6-9.
// 共享栈基本操作
// 进栈出栈
//

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50

typedef struct {
    int data[MAXSIZE];
    int top[2];
} stack1;

stack1 s;

int push(int i, int x) {
    //s为大栈,i号栈,x为进栈元素
    if (i != 1 && i != 0) {
        printf("检查输入的stack\n");
        return -1;
    }
    if (s.top[1] - s.top[0] == 1) {
        printf("stack_full\n");
        return -1;
    }
    if (i == 0)
        s.data[++s.top[0]] = x;
    else
        s.data[--s.top[1]] = x;
    return 1; //入栈成功
}

int pop(int i) {
    if (i != 0 && i != 1) {
        printf("stack_illegal\n");
        return -1;
    }
    if (i == 0) {
        if (s.top[0] == -1) {
            printf("stack0_null\n");
            return -1;
        }
        return s.data[s.top[0]--];
    } else {
        if (s.top[1] == MAXSIZE) {
            printf("stack1_null\n");
            return -1;
        }
        return s.data[s.top[1]++];
    }
}

int main() {
    //初始化stack
    s.top[0] = -1;
    s.top[1] = MAXSIZE;

    // 测试
    push(0, 1); printf("Push 0, 1: %d\n", s.top[0]);
    push(0, 2); printf("Push 0, 2: %d\n", s.top[0]);
    push(1, 3); printf("Push 1, 3: %d\n", s.top[1]);
    push(1, 4); printf("Push 1, 4: %d\n", s.top[1]);
    printf("Pop 0: %d\n", pop(0));
    printf("Pop 0: %d\n", pop(0));
    printf("Pop 1: %d\n", pop(1));
    printf("Pop 1: %d\n", pop(1));

    return 0;
}
