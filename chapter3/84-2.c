//
// Created by sansan on 25-6-11.
// 队列Q,栈S
// 将队列逆置
//

#include<stdio.h>

#define MAXSIZE 50

typedef struct stack {
    int data[MAXSIZE];
    int top;
} stack;

typedef struct queue {
    int data[MAXSIZE];
    int front, rear;
} SqQueue;

void enter_s(SqQueue *s, int x) {
    if ((s->rear + 1) % MAXSIZE == s->front) {
        //判断队列满
        printf("queue_full\n");
        return;
    }
    s->data[s->rear] = x;
    s->rear = (s->rear + 1)%MAXSIZE;
    return;
}

void out_s(SqQueue *s, int *x) {
    if (s->front == s->rear) {//队空特判
        printf("queue_null\n");
        return;
    }
    *x=s->data[s->front];
    s->front=(s->front+1)%MAXSIZE;
    return;
}

// 入栈
void enter_stack(stack *s,int x) {
    if (s->top==MAXSIZE-1) {
        printf("stack_full\n");
        return;
    }
    s->data[++s->top]=x;
    return ;
}

// 出栈
void out_stack(stack*s,int *x) {
    if (s->top==-1) {
        printf("stack_null\n");
        return;
    }
    *x=s->data[s->top--];
    return;
}

int main() {
    SqQueue s;
    s.front = s.rear = 0;

    stack s1;
    s1.top = -1;

    int i=0;
    for (i=0;i<20;i++)//入队
        enter_s(&s,i);
    while (s.rear!=s.front) {//把队里的元素放到stack里
        int temp;
        out_s(&s,&temp);
        enter_stack(&s1,temp);
    }

    while (s1.top!=-1) {//把stack的元素出栈进s
        int temp;
        out_stack(&s1,&temp);
        enter_s(&s,temp);
    }

    while (s.rear!=s.front) {
        int temp;
        out_s(&s,&temp);
        printf("%d ",temp);
    }

    return 0;
}
