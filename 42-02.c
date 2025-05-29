/*
ɾ����ͷ��������е�Ψһ��Сֵ
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

//��ͷ���β�巨
void buildlist(linklist* L, sqlist a) {
	*L = (lnode*)malloc(sizeof(lnode));//ͷ���
	if (!*L)//�ж�ͷ����Ƿ����ɹ�
		return;
	lnode* s;
	lnode* r = *L;//βָ��
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
	if (!L||!L->next)//�ж�L�Ƿ�Ϊ��
		return;
	lnode* s = L->next;
	while (s != NULL) {
		printf("%d ", s->data);
		s = s->next;
	}
	printf("\n");
}

void deletemin(linklist* L) {
	if (!*L || !(*L)->next)//���������������
		return;
	//p��ѭ��ָ��,q���ݴ浱ǰ��Сֵָ��,r��ѭ��ָ���prev
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