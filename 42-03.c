/*
��ͷ��㵥����ԭ������,�ռ临�Ӷ�o(1)
*/

#include<stdio.h>
#include<stdlib.h>//����malloc��free����

typedef struct lnode {
	int data;
	struct lnode* next;
}lnode,*linklist;

typedef struct sqlist {
	int data[50];
	int length;
}sqlist;

//β�巨
void buildlist(linklist*L,sqlist a){
	*L = (lnode*)malloc(sizeof(lnode));//Ϊͷ������ռ�
	if (*L == NULL)//����ʧ��
		return;
	lnode* r=*L;//βָ��
	lnode* s;
	for (int i = 0; i < a.length; i++) {
		s = (lnode*)malloc(sizeof(lnode));
		if (s == NULL)//����ʧ��
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

void freelist(linklist* L) {
	if (*L == NULL)
		return;
	lnode* p = (*L)->next;//ָ���һ��Ԫ�� 
	while (p) {
		lnode*s = p;//�ݴ���Ҫfree�Ľڵ�
		p = p->next;
		free(s);
	}
	*L = NULL;
}

//ͷ�巨����
void list_reverse(linklist* L) {
	if ((*L) == NULL || (*L)->next == NULL)
		return;
	lnode* p = (*L)->next;//��p�ڵ�ͷ�嵽L�ĺ���
	lnode* r ;//ָ��p�ڵ����һ��λ��,��ֹ����
	(*L)->next = NULL;
	while (p) {
		r = p->next;
		p->next = (*L)->next;
		(*L)->next = p;
		p = r;
	}
}

int main()
{
	sqlist s = { {1,2,3,4},4 };
	linklist L = NULL;
	buildlist(&L,s);
	disp(L);
	list_reverse(&L);
	disp(L);

	return 0;
}