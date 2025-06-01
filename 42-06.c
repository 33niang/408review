/*
将一个链表里的奇偶项分成两个链表
原地分开
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
}lnode,*linklist;

	



void buildlist(linklist* L, sqlist a) {
	(*L) = (lnode*)malloc(sizeof(lnode));
	if (*L == NULL)
		return;
	lnode* s, * r = *L;
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

void initlinklist(linklist* L) {
	(*L) = (lnode*)malloc(sizeof(lnode));
	if (*L == NULL)
		return;
	(*L)->next = NULL;
}

//还有一个方法直接让ra和rb指向L的第1和第2个元素,然后ra=ra->next->next,rb同理

void separate(linklist L, linklist* A, linklist* B) {

	int flag = 0;
	lnode* p = L->next;
	lnode* ra = (*A), * rb = (*B);//ra和rb指向A和B的最后一个元素,ra和rb的下一个元素是NULL
	while (p) {
		if (flag % 2 == 0) {//flag第0,2,4会进入这个if
			ra->next = p;
			ra = ra->next;
		}
		else {
			rb->next = p;
			rb = rb->next;
		}

		p = p->next;
		flag++;
	}
	ra->next = NULL;
	rb->next = NULL;
	L->next = NULL;
}
int main() 
{
	sqlist a = { {1,2,3,4,5,6,7,8,9,0},10 };
	linklist L = NULL;
	buildlist(&L, a);
	disp(L);
	linklist A = NULL, B = NULL;
	initlinklist(&A);
	initlinklist(&B);
	printf("A链表:");
	disp(A);
	printf("B链表:");
	disp(B);
	separate(L, &A, &B);
	printf("A链表:");
	disp(A);
	printf("B链表:");
	disp(B);

	return 0;
}