//
// Created by sansan on 25-6-9.
// 判断链表是否为中心对称
//

#include<stdio.h>
#include<stdlib.h>

typedef struct lnode {
    char data;
    struct lnode*next;
}lnode,*linklist;

//char s1[5]={'a','b','c','d','e'};
char s1[5]={'a','b','c','b','a'};
int n=5;
void buildlist(linklist *L) {//写的简陋一点,判断啥的懒得写了
    *L=(lnode*)malloc(sizeof(lnode));
    lnode*s,*r=*L;
    for (int i=0;i<n;i++) {
        s=(lnode*)malloc(sizeof(lnode));
        s->data=s1[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}

void disp(linklist L) {
    lnode*p=L->next;
    while (p) {
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}

int is_symmetry(linklist L,int n) {
    char str[n/2];
    lnode*p=L->next;//遍历整个链表
    int i;
    for (i=0;i<n/2;i++) {
        str[i]=p->data;
        p=p->next;
    }
    i--;//stack顶指针指向前一半的最后一个位置
    if (n%2)//奇数特判,让stack和sqlist对称
        p=p->next;
    while (p&&p->data==str[i]) {
        i--;
        p=p->next;
    }
    if (i==-1)
        return 1;
    return 0;

}

int main() {
    linklist L=NULL;
    buildlist(&L);
    disp(L);
    if (is_symmetry(L,n))
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}
