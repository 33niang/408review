//
// Created by sansan on 25-6-10.
// 使用tag判断循环队列empty & full
//

#include<stdio.h>

#define MAXSIZE 10

typedef struct {
    int data[MAXSIZE];
    int front;
    int rear;
    int tag; // tag==1表示上次是插入,tag==0上次是删除
} SqQueue;

int enter_s(SqQueue *s, int x) {
    //进队,并返回成功
    if (s->front == s->rear && s->tag == 1) {
        printf("队满\n");
        return 0;
    }
    s->data[s->rear] = x;
    s->rear = (s->rear + 1) % MAXSIZE;
    s->tag = 1;
    //printf("%d ",x);
    return 1;
}

int out_s(SqQueue *s, int *x) {
    if (s->front == s->rear && s->tag == 0) {
        printf("队空\n");
        return 0;
    }
    *x=s->data[s->front];

    s->front=(s->front+1)%MAXSIZE;
    s->tag=0;
    return 1;
}


int main() {
    SqQueue s;
    s.front = s.rear = 0;
    s.tag = 0;

    // 测试入队
    for (int i = 0; i < 11; i++) {
        if (enter_s(&s, i)) {
            printf("入队: %d\n", i);
        }
    }

    // 测试出队
    int x;
    for (int i = 0; i < 11; i++) {
        if (out_s(&s, &x)) {
            printf("出队: %d\n", x);
        }
    }

    return 0;
}
