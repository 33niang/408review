/*
删除带头结点链表中的唯一最小值
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50

typedef struct SqList {
	int data[MAXSIZE];
	int length;
}sqlist;

typedef struct lnode {
	int data;
	struct lnode* next;
}lnode, * linklist;

//带头结点尾插法
void buildlist(linklist* L, sqlist a) {
	*L = (lnode*)malloc(sizeof(lnode));//头结点
	if (!*L)//判断头结点是否分配成功
		return;
	lnode* s;
	lnode* r = *L;//尾指针
	for (int i = 0; i < a.length; i++) {
		s = (lnode*)malloc(sizeof(lnode));
		if (!s)
			return;
		s->data = a.data[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

void disp(linklist L) {
	if (!L||!L->next)//判断L是否为空
		return;
	lnode* s = L->next;
	while (s != NULL) {
		printf("%d ", s->data);
		s = s->next;
	}
	printf("\n");
}

void deletemin(linklist* L) {
	if (!*L || !(*L)->next)//空链表或者无数据
		return;
	//p是循环指针,q是暂存当前最小值指针,r是循环指针的prev
	lnode* p = (*L)->next;
	lnode* q = p;
	lnode* r = *L;
	lnode* prev = *L;
	int min=p->data;
	while (p) {
		if (p->data < min) {
			min = p->data;
			q = p;
			r = prev;
		}
		prev = p;
		p = p->next;
	}
	r->next = q->next;
	free(q);

}
int main() {
	sqlist a = { { 1,2,3,4,5 },5 };
	linklist L=NULL;
	buildlist(&L,a);
	disp(L);
	deletemin(&L);
	disp(L);
}