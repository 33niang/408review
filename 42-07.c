/*
��������������ɾ���ظ�Ԫ��
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

void buildlist(linklist* L,sqlist a) {
	(*L) = (lnode*)malloc(sizeof(lnode));
	if ((*L) == NULL)
		return;
	lnode* s, * r = (*L);
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

void deleterepeat(linklist L) {
	if (!L)//����ʧ��
		return;
	if (L->next == NULL)//û��Ԫ��
		return;
	if (L->next->next == NULL)//ֻ��һ��Ԫ��
		return;
	lnode* p = L->next->next;
	lnode* pre = L->next;
	while (p) {
		if (p->data == pre->data) {
			lnode* s = p;
			pre->next = p->next;//��ֹ����
			p = p->next;//����ظ�,p��,pre����
			free(s);
		}
		else {
			pre = pre->next;
			p = p->next;
		}
	}
}
int main()
{
	linklist L = NULL;
	sqlist a = { {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,9},16 };
	buildlist(&L,a);
	disp(L);
	deleterepeat(L);
	disp(L);

	return 0;

}