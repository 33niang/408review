/*
链表A和B元素递增有序
将A和B中的重复元素放到链表C里
不破坏A和B
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
	if ((*L) == NULL)
		return;
	lnode* s, * r = (*L);
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
void initlist(linklist* L) {
	(*L) = (lnode*)malloc(sizeof(lnode));
	if (*L == NULL)
		return;
	(*L)->next = NULL;
}

void quchong(linklist A, linklist B, linklist C) {//去重函数,不会取名字
	if (!(A || B))//防止A和B为空
		return;
	if (!(A->next || B->next))//防止A和B只有头结点
		return;
	lnode* pa = A->next, * prea = A;
	lnode* pb = B->next, * preb = B;
	lnode* rc = C;
	lnode* sc;
	while (pa && pb) {//只有pa和pb都没到末尾的时候才循环
		if (pa->data == pb->data) {
			sc = (lnode*)malloc(sizeof(lnode));
			if (!sc) return;
			sc->data = pa->data;
			rc->next = sc;
			rc = rc->next;
			pa = pa->next;
			pb = pb->next;
		}
		else if (pa->data > pb->data)
			pb = pb->next;
		else
			pa = pa->next;
	}
	rc->next = NULL;
}
int main()
{
	sqlist A = { {1,2,3,4,5,7,8,9,19},9 };
	sqlist B = { {5,7,8,9,10,15,16,19,25},9 };
	linklist La = NULL;
	linklist Lb = NULL;
	buildlist(&La, A);
	buildlist(&Lb, B);
	printf("La: ");
	disp(La);
	printf("Lb: ");
	disp(Lb);

	linklist Lc = NULL;
	initlist(&Lc);

	printf("分离后\n");
	printf("La: ");
	disp(La);
	printf("Lb: ");
	disp(Lb);
	quchong(La, Lb, Lc);
	printf("Lc: ");
	disp(Lc);
	
	return 0;
}