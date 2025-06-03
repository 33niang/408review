//
// Created by sansan on 25-6-3.
//单链表保存m个整数,|data|<=n
//节点为{data,link}
//要求时间尽可能高效
//只保留第一次出现的节点,并且如果后面出现的节点与第一次出现的节点绝对值相同,则删掉
//例如:head -> 21 -> -15 -> -15 -> -7 -> 15 -> NULL
//结果:head -> 21 -> -15 -> -7 -> NULL
//

#include<stdio.h>
#include<stdlib.h>

//创建辅助数组,大小为n+1
//链表里有值就在数组对应位置置1
//之后遇到绝对值相同的节点检查数组,若为1则丢弃

typedef struct sqlist {
    int* data;
    int length;
} sqlist;

typedef struct lnode {
    int data;
    struct lnode* link;
} lnode, * linklist;

int n = 1000; //全局变量n

void buildlist(linklist* L, int a[], int length) {
    (*L) = (lnode*)malloc(sizeof(lnode));
    if (*L == NULL)
        return;
    lnode* s, * r = *L;
    for (int i = 0; i < length; i++) {
        s = (lnode*)malloc(sizeof(lnode));
        if (!s)
            return;
        s->data = a[i];
        r->link = s;
        r = r->link;
    }
    r->link = NULL;
}

void disp(linklist L) {
    if (!L || !L->link)
        return;
    lnode* p = L->link;
    while (p) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n");
}

void saveabsvalue(linklist L, sqlist a) {
    if (!L || !L->link)
        return;

    //把数组全部置0
    for (int i = 0; i < n + 1; i++)
        a.data[i] = 0;
    lnode* p = L->link;
    lnode* pre = L;
    while (p) {
        if (a.data[abs(p->data)]) {//若数组里面已有记录则进入删除分支
            lnode* temp = p;
            p = p->link;
            pre->link = p;
            free(temp);
        }
        else {//数组里没有记录,代表是第一次扫描到当前值,应该正常后移
            a.data[abs(p->data)] = 1;
            pre = pre->link;
            p = p->link;
        }
    }
}

int main() {
    sqlist a;
    //初始化数组a
    a.data = (int*)malloc(sizeof(int) * (n + 1));
    a.length = n + 1;
    int b[] = { 1, -9, 2, -8, 3, -7, 4, -6, 5, -5, 6, -4, 7, -3, 8, -2, 9, -1 };
    int b_size = sizeof(b) / sizeof(b[0]);

    linklist L = NULL;

    buildlist(&L, b, b_size);
    disp(L);

    //以上链表构建完成
    saveabsvalue(L, a);

    disp(L);//一次过,牛逼


    return 0;
}
