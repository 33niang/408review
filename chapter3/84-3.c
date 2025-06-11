//
// Created by sansan on 25-6-11.
// 用两个栈S1和S2模拟一个队列
//


//S1用来入队,S2用来出队


#include <stdio.h>

#define MAXSIZE 50

typedef struct stack {
    int data[MAXSIZE];
    int top;
}stack;

//入栈
int push(stack*s,int x) {
    if (s->top==MAXSIZE-1) {
        return 0;
    }
    s->data[++s->top]=x;
    return 1;
}

//出栈
int pop(stack *s,int *x) {
    if (s->top==-1)
        return 0;
    *x=s->data[s->top--];
    return 1;
}

//入队
int enter_squeue(stack *s1,stack *s2,int x) {
    if (s1->top==MAXSIZE-1) {
        if (s2->top!=-1)// s1满,s2不空,返回队满
            return 0;
        // s1满,s2空,先把s1搬到s2里,然后正常入栈s1
        int temp;
        while (s1->top!=-1) {
            pop(s1,&temp);
            push(s2,temp);
        }
    }
    //正常入栈s1
    push(s1,x);
    return 1;
}

// 出队
int out_squeue(stack *s1,stack *s2,int *x) {
    if (s2->top==-1) {// s2为空
        if (s1->top==-1) // s1 也为空,直接返回空
            return 0;
        //s1不为空
        int temp;// 把s1的值入栈s2
        while (s1->top!=-1) {
            pop(s1,&temp);
            push(s2,temp);
        }
    }
    pop(s2,x);
    return 1;
}
int main() {
    stack s1, s2;
    s1.top = -1;
    s2.top = -1;

    // 测试入队
    for (int i = 0; i < 10; i++) {
        if (enter_squeue(&s1, &s2, i)) {
            printf("入队: %d\n", i);
        } else {
            printf("入队失败: %d\n", i);
        }
    }

    // 测试出队
    int x;
    for (int i = 0; i < 10; i++) {
        if (out_squeue(&s1, &s2, &x)) {
            printf("出队: %d\n", x);
        } else {
            printf("出队失败\n");
        }
    }

    return 0;
}
