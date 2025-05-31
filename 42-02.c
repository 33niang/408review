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
	lnode* p = (*L)->next;//ѭ��ָ��
	lnode* q = p;//�ݴ浱ǰ��Сֵ
	lnode* r = *L;//��Сֵָ���ǰ��
	lnode* prev = *L;//prev��ѭ��ָ��p��ǰ��
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
	sqlist a = { { 5,4,3,2,1,2,3,4,5 },9 };
	linklist L=NULL;
	buildlist(&L,a);
	disp(L);
	deletemin(&L);
	disp(L);

	return 0;
}