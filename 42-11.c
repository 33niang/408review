/*
判断带头结点循环双链表是否对称
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct sqlist {
	int data[50];
	int length;
}sqlist;

typedef struct lnode {
	int data;
	struct lnode* pre;
	struct lnode* next;
}lnode,*linklist;

void buildlist(linklist *L,sqlist a) {//创建循环双链表
	*L = (lnode*)malloc(sizeof(lnode));
	if (!(*L))
		return;
	lnode* s, * r = (*L);

	for (int i = 0; i < a.length; i++) {
		s = (lnode*)malloc(sizeof(lnode));
		if (!s)
			return;
		s->data = a.data[i];
		r->next = s;
		s->pre = r;
		r = r->next;
	}
	r->next = *L;
	(*L)->pre = r;
}
void disp(linklist L) {
	if (L->next == L) {
		printf("空\n");
		return;

	}
	lnode* p = L->next;
	while (p != L) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int is_loop(linklist L) {
	if (!L)
		return 0;
	if (L->next == L)
		return 1;
	lnode* p = L->next;
	lnode* r = L->pre;
	while (p->data==r->data) {
		if (p == L){
			return 1;
		}
		p = p->next;
		r = r->pre;
	}
	return 0;
}
int main()
{
	sqlist a = { {1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1},17 };
	linklist L = NULL;

	buildlist(&L, a);
	disp(L);

	printf("%d\n", is_loop(L));
	return 0;
}