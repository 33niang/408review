/*
有两个循环单链表,头指针为h1和h2
把h2链接到h1之后
依然保持循环
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct sqlist {
	int data[50];
	int length;
}sqlist;

typedef struct lnode {
	int data;
	struct lnode* next;
}lnode, * linklist;

void buildlist(linklist* L, sqlist a) {
	(*L) = (lnode*)malloc(sizeof(lnode));
	if (!(*L))
		return;
	lnode* r = (*L), * s;
	for (int i = 0; i < a.length; i++) {
		s = (lnode*)malloc(sizeof(lnode));
		if (!s)
			return;
		s->data = a.data[i];
		r->next = s;
		r = r->next;
	}
	r->next = (*L);
}

void disp(linklist L) {
	if (L == NULL)
		return;
	if (L->next == L) {
		printf("空\n");
		return;
	}
	lnode* p = L->next;
	while (p!=L) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//不修改h1和h2的指向
void merge(linklist h1, linklist h2) {
	if (!h1 || !h2)
		return;
	if (h1->next==h1 || h2->next==h2)
		return;
	lnode* p1 = h1;
	while (p1->next != h1)
		p1 = p1->next;
	p1->next = h2->next;
	lnode* p2 = h2;
	while (p2->next != h2)
		p2 = p2->next;
	p2->next = h1;
}
int main()
{
	sqlist a = { {1,2,3,4,5},5 };
	sqlist b = { {6,7,8,9},4 };
	linklist h1 = NULL, h2 = NULL;
	buildlist(&h1, a);
	disp(h1);
	buildlist(&h2, b);
	disp(h2);
	merge(h1, h2);
	disp(h1);


	return 0;
}