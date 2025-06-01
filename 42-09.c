/*
A和B两个链表
元素递增排序
求A和B的交集并且放到A里面
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
	for(int i=0;i<a.length;i++){
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
	if (L->next == NULL){
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

void deletelist(linklist L) {
	if (!L)
		return;
	if (L->next == NULL)
		return;
	lnode* p = L->next;
	while (p) {
		lnode* temp = p;
		p = p->next;
		free(temp);
	}
	L->next = NULL;
}
void Findintersection(linklist A, linklist B) {
	if (!A|| !B)
		return;
	if (!(A->next) || !(B->next)) {
		deletelist(A);
		return;
	}
	lnode* pa = A->next;
	lnode* pb = B->next;
	lnode* r = A;
	lnode* s;
	while (pa && pb) {
		if (pa->data == pb->data) {
			r->next = pa;
			r = r->next;
			pa = pa->next;
			pb = pb->next;
		}
		else if (pa->data < pb->data) {
			s = pa;
			s = pa;
			pa = pa->next;
			free(s);
		}
		else {
			pb = pb->next;
		}
	}
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

	printf("处理后\n");
	Findintersection(La, Lb);
	disp(La);
	disp(Lb);


}