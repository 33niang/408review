/*
带头结点非循环双链表,结构为data,freq,pre,next
每当locate(L,x)时,对应的freq+1
并且重新排列链表使得其访问频度递减
频度一样的更近访问的节点更靠前
且locate函数返回值为x的指针
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct sqlist {
	int data[50];
	int length;
}sqlist;

typedef struct lnode {
	int data;
	int freq;
	struct lnode* pre;
	struct lnode* next;
}lnode, * linklist;

void buildlist(linklist* L, sqlist a) {//创建循环双链表
	*L = (lnode*)malloc(sizeof(lnode));
	if (!(*L))
		return;
	lnode* s, * r = (*L);

	for (int i = 0; i < a.length; i++) {
		s = (lnode*)malloc(sizeof(lnode));
		if (!s)
			return;
		s->data = a.data[i];
		s->freq = 0;
		r->next = s;
		s->pre = r;
		r = r->next;
	}
	r->next = NULL;
	(*L)->pre = NULL;
}

void disp(linklist L) {
    if (!L) return;
    lnode* p = L->next;
    while (p) {
        //printf("%d(freq:%d) ", p->data, p->freq);
		printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


lnode* locate(linklist L, int x) {
	if (!L)
		return NULL;
	if (L->next == NULL) {
		return NULL;
	}
	lnode* p = L->next;//用来向后遍历和x判断
	lnode* s = L;//头结点,找到p之后从头结点向后遍历插入
	while (p) {
		if (p->data == x) {
			p->freq++;
			if (p->next) {//判断尾节点
				p->next->pre = p->pre;
			}
			p->pre->next = p->next;
			while (s->next&&p->freq < s -> next->freq) //寻找插入位置
				s = s->next;
			p->next = s->next;//把x对应的节点插到对应的位置
			p->pre = s;
			if(s->next)
				s->next->pre = p;
			s->next = p;
			return p;	
		}
		p = p->next;
	}
	return NULL;
	return NULL;
}
int main() {
	sqlist a = { {1,2,3,4,5,6,7,8,9},9 }; // 多个相同值测试
	linklist L = NULL;
	buildlist(&L, a);

	printf("初始: ");
	disp(L); 

	printf("查找第一个3后: ");
	locate(L, 3);
	disp(L); 

	printf("查找第二个3后: ");
	locate(L, 3);
	disp(L); 

	printf("查找5后: ");
	locate(L, 5);
	disp(L); 

	printf("查找5后: ");
	locate(L, 5);
	disp(L);

	printf("查找5后: ");
	locate(L, 5);
	disp(L);

	printf("查找5后: ");
	locate(L, 5);
	disp(L);

	printf("查10遍9后:");
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	disp(L);

	printf("第一个元素的频次:%d\n", L->next->freq);
	return 0;
}