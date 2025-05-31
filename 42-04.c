/*
��ͷ�����������
ɾ���ڸ�����Χs,t֮���Ԫ��
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct lnode {
	int data;
	struct lnode* next;
}lnode,*linklist;

typedef struct sqlist {
	int data[50];
	int length;
}sqlist;

void buildlist(linklist *L,sqlist a){
	*L = (lnode*)malloc(sizeof(lnode));
	if ((*L) == NULL)//ͷ������ʧ��
		return;
	(*L)->next = NULL;//����δ������Ϊ
	lnode* s, * r = *L;
	for (int i = 0; i < a.length; i++) {
		s = (lnode*)malloc(sizeof(lnode));
		if (s == NULL)//s����ʧ��
			return;
		s->data = a.data[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

void disp(linklist L) {
	if (L == NULL || L->next == NULL)
		return;
	lnode* p = L->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void delete(linklist *L,int s,int t){
	if (*L == NULL)//��ֹp=(*L)->next��ɱ���
		return;
	if (s > t)//sΪ������,tΪ������
		return;
	lnode* p = (*L)->next;
	lnode* pre = (*L);
	while (p) {
		if (s <= p->data && p->data <= t) {
			lnode* temp = p;
			pre->next = p->next;
			p = p->next;
			free(temp);
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}
int main() 
{
	sqlist a = { {1,2,3,4,5,6,7,8,9,0},10 };
	linklist L = NULL;
	int s = 3, t = 6;

	buildlist(&L, a);
	disp(L);
	delete(&L,s,t);
	disp(L);
	return 0;
}