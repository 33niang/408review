//
// Created by sansan on 25-9-28.
// 单链表的简单选择排序
// 此方案为交换data方案,交换整个节点的方案在主要排序那个文件里
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sqlist {
    char data[1000];
    int length;
} sqlist;

typedef struct lnode {
    char data;
    struct lnode *next;
} lnode, *linklist;

void buildlist(linklist *l, sqlist a) {
    *l = (lnode *) malloc(sizeof(lnode));
    if (*l == NULL)
        return;
    (*l)->next = NULL;
    lnode *s, *r = *l;
    for (int i = 0; i < a.length; i++) {
        s = (lnode *) malloc(sizeof(lnode));
        if (s == NULL)
            return;
        s->data = a.data[i];
        s->next = r->next;
        r->next = s;
        r=r->next;
    }
    r->next = NULL;
}

void select_sort_linklist(linklist *l) {
    if (*l == NULL || (*l)->next == NULL)
        return;
    lnode *p = (*l)->next; // h指针到第一个元素的位置
    lnode *min;
    lnode *s; // 表示内层循环的指针
    char temp; // 暂存交换的元素

    while (p->next != NULL) {
        min = p; // 先假定最小值为第一个元素
        s = p;
        while (s != NULL) {
            if (s->data < min->data)
                min = s;
            s = s->next;
        }
        if (p!= min){ // min指针移动过,不为第一个元素则交换data值
            temp=p->data;
            p->data=min->data;
            min->data=temp;
        }
        p = p->next; // 第一个元素有序,从第二个开始排
    }
}

// 辅助函数：打印链表中的所有元素
void print_list(linklist l) {
    // 跳过头结点，从第一个实际元素开始打印
    lnode *p = l->next;
    if (p == NULL) {
        printf("链表为空!\n");
        return;
    }
    while (p != NULL) {
        printf("%c -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// 辅助函数：释放链表所有节点的内存
void free_list(linklist *l) {
    lnode *p = *l;
    lnode *temp;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
    *l = NULL;
}

int main() {
    // 1. 定义测试数据
    char test_data[] = {'z', 'x', 'a', 'c', 'b', 'w'};
    int len = sizeof(test_data) / sizeof(test_data[0]);

    // 2. 直接在栈上创建 sqlist 变量，不再需要 malloc
    sqlist a;

    // 安全检查：确保测试数据不会溢出固定大小的数组
    if (len > sizeof(a.data)) {
        printf("错误：测试数据长度超过了 sqlist 的容量。\n");
        return 1;
    }

    a.length = len;
    memcpy(a.data, test_data, len * sizeof(char));

    // 3. 创建链表 (注意这里传递的是 a，而不是指针 a 的解引用 *a)
    linklist L = NULL;
    buildlist(&L, a);

    // 4. 打印排序前的链表
    printf("原始链表: ");
    print_list(L);

    // 5. 调用选择排序函数
    select_sort_linklist(&L);

    // 6. 打印排序后的链表
    printf("排序后链表: ");
    print_list(L);

    // 7. 释放内存 (不再需要 free(a))
    free_list(&L); // 仍然需要释放链表节点的内存

    return 0;
}
