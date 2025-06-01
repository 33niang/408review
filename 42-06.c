/*
��һ�����������ż��ֳ���������
ԭ�طֿ�
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
		printf("��\n");
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

//����һ������ֱ����ra��rbָ��L�ĵ�1�͵�2��Ԫ��,Ȼ��ra=ra->next->next,rbͬ��

void separate(linklist L, linklist* A, linklist* B) {

	int flag = 0;
	lnode* p = L->next;
	lnode* ra = (*A), * rb = (*B);//ra��rbָ��A��B�����һ��Ԫ��,ra��rb����һ��Ԫ����NULL
	while (p) {
		if (flag % 2 == 0) {//flag��0,2,4��������if
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
	printf("A����:");
	disp(A);
	printf("B����:");
	disp(B);
	separate(L, &A, &B);
	printf("A����:");
	disp(A);
	printf("B����:");
	disp(B);

	return 0;
}