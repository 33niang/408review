/*
������ѭ��������,ͷָ��Ϊh1��h2
��h2���ӵ�h1֮��
��Ȼ����ѭ��
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
		printf("��\n");
		return;
	}
	lnode* p = L->next;
	while (p!=L) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	sqlist a = { {1,2,3,4,5},5 };
	sqlist b = { {6,7,8,9},4 };


	return 0;
}