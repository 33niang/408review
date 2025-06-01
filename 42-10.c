/*
两个整数序列A和B
判断序列B是否为序列A的连续子序列
默认B短A长
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
	r->next = NULL;
}

void disp(linklist L) {
	if (L == NULL)
		return;
	if (L->next == NULL) {
		printf("空\n");
		return;
	}
	lnode* p = L->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int is_son(linklist L1, linklist L2) {
	if (L1 == NULL || L2 == NULL)
		return 0;
	if (L1->next == NULL || L2->next == NULL)
		return 0;
	lnode* p1 = L1->next;
	lnode* p2 = L2->next;
	while (p1 != NULL) {
		lnode* temp_p1 = p1;
		lnode* temp_p2 = p2;
		while (temp_p1 && temp_p2 && temp_p1->data == temp_p2->data) {
			temp_p1 = temp_p1->next;
			temp_p2 = temp_p2->next;
		}
		if (temp_p2 == NULL)
			return 1;
		p1 = p1->next;
	}
	return 0;
}
int main()
{
	sqlist a = { {1,2,3,4,5,6,7,3,4,5,7},11 };
	sqlist b = { {3,4,5,7},4 };
	linklist L1 = NULL;
	linklist L2 = NULL;
	buildlist(&L1, a);
	buildlist(&L2, b);
	disp(L1);
	disp(L2);
	printf("%d\n", is_son(L1, L2));


	return 0;
}