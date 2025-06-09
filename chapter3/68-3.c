//
// Created by sansan on 25-6-9.
// 判断stack的入栈出栈序列是否合法
// I/O为入栈/出栈,判断序列是否合法
// stack的初态和终态均为空
//

#include<stdio.h>
#include<stdlib.h>

int is_ok(char a[]) {
    int num=0;
    int i=0;
    while (a[i]!='\0') {
        if (a[i]=='I')
            num++;
        else
            num--;
        if (num<0)
            return 0;
        i++;
    }
    if (num!=0)//栈没有空
        return 0;
    else
        return 1;
}

int main() {
    //char a[]="IOOIOIIO";
    char a[]="IOIIOIOO";
    if (is_ok((a)))
        printf("yes\n");
    else
        printf("no\n");


    return 0;
}


