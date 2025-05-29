/*
ɾ��������L������ֵΪx�Ľڵ�
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct lnode {
	int data;
	struct lnode* next;
}*linklist,lnode;

int a[4] = { 1,2,3,4 };
int n = 4;

//�ݹ�ʵ��
//��ͷ���
void buildlist(linklist* L) {//������ͷ��������
	*L = NULL;
	lnode* r = NULL;//βָ��
	for (int i = 0; i < n; i++) {
		lnode* s = (lnode*)malloc(sizeof(lnode));
		s->data = a[i];
		s->next = NULL;
		if (*L == NULL) {//�����ʱͷ���ճ�ʼ������ô�Ͱ�s����ͷ���
			*L = s;
			r = s;
		}
		else {
			//�����ʱ�������Ѿ�����Ԫ��
			// �Ǿͽ�βָ��ָ���������s�ڵ�
			//���ҽ�βָ���λ������s
			r->next = s;
			r = s;
		}
	}
}

void disp(linklist L) {
	lnode* s = L;
	if (!s) {
		printf("empty\n");
		return;
	}
	while (s) {
		printf("%d ", s->data);
		s = s->next;
	}
	printf("\n");
}

void deletex(linklist* L, int x) {
	if (*L == NULL)
		return;//������
	lnode* p = *L;
	if (p->data == x) {
		*L = p->next;
		free(p);
		deletex(L, x);
	}
	else {
		deletex(&((*L)->next), x);//��ǰ�ڵ��x���ݹ鴦���¸��ڵ�
	}
}

void freelist(linklist* L) {
	lnode* p = *L;
	while (p) {
		lnode* temp = p;
		p = p->next;
		free(temp);
	}
	*L = NULL;
}

//��ͷ���
void buildheadlist(linklist* L) {
	*L = (lnode*)malloc(sizeof(lnode));
	if (*L == NULL) {
		printf("����ʧ��\n");
		return;
	}
	(*L)->next = NULL;//ͷ���
	lnode* r = *L;//βָ��,ָ��ͷ���,����ΪNULL
	for (int i = 0; i < n; i++) {
		lnode* s = (lnode*)malloc(sizeof(lnode));
		if (s == NULL) {//�ж�s�����ڴ��Ƿ�ɹ�
			printf("����ʧ��\n");
			return;
		}
		s->data = a[i];
		s->next = NULL;
		r->next = s;
		r = s;
	}
}

void dispheadlist(linklist L) {
	if (L == NULL || L->next == NULL) {
		printf("�ձ�\n");
		return;
	}
	lnode* s = L->next;
	while (s) {
		printf("%d ", s->data);
		s = s->next;
	}
	printf("\n");
}

void deletex_headlist(linklist* L, int x) {
	if (*L == NULL || (*L)->next == NULL) {
		printf("�ձ�\n");
		return;
	}
	lnode* p = (*L)->next;
	lnode* prev = *L;
	if (p->data == x) {
		prev->next = p->next;
		free(p);
		deletex_headlist(L, x);
	}
	else {
		deletex_headlist(&(prev->next), x);
	}
}

void free_headlist(linklist* L) {
	if (*L == NULL)
		return;
	lnode* p = *L;
	while (p) {
		lnode* temp = p;
		p = p->next;
		free(temp);
	}
	*L = NULL;
}
int main()
{
	
	linklist L = NULL;
	buildlist(&L);
	printf("original\n");
	disp(L);
	deletex(&L, 2);
	printf("after\n");
	disp(L);
	freelist(&L);
	
	printf("--------------\n");
	linklist L2 = NULL;
	buildheadlist(&L2);
	dispheadlist(L2);
	deletex_headlist(&L2,2);
	dispheadlist(L2);
	free_headlist(&L2);
	

	return 0;
}