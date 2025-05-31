/*
Ѱ����������Ĺ����ڵ�
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

void buildlist(linklist* L,sqlist a) {
	(*L) = (lnode*)malloc(sizeof(lnode));
	if (*L == NULL)
		return;
	(*L)->next = NULL;
	lnode* s, * r = *L;
	for (int i = 0; i < a.length; i++) {
		s = (lnode*)malloc(sizeof(lnode));
		if (s == NULL)
			return;
		s->data = a.data[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

void disp(linklist L) {
	if (L == NULL||L->next==NULL)
		return;
	lnode* p = L->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

lnode* search(linklist L,int n) {//Ѱ��ָ������L��ֵΪn�Ľڵ��ָ��,Ĭ��nΨһ
	if (L == NULL) {
		printf("����ʧ��\n");
			return NULL;
	}
	lnode* p = L->next;
	while (p) {
		if (p->data == n) {
			break;
		}
		p = p->next;
	}
	return p;
}
void buildlist_b(linklist* M, sqlist b, linklist L,int n) {//����һ��M����,���ҽ�M��������LֵΪ5��Ԫ��֮��
	(*M) = (lnode*)malloc(sizeof(lnode));
	if (*M == NULL)
		return;
	lnode* s, * r = *M;
	for (int i = 0; i < b.length; i++) {
		s = (lnode*)malloc(sizeof(lnode));
		if (s == NULL)
			return;
		s->data = b.data[i];
		r->next = s;
		r = r->next;
	}
	r->next = search(L, n);
}

lnode* search_public_lnode(linklist L, linklist M) {
	if (L == NULL || L->next == NULL)//��ֹ������
		return NULL;
	if (M == NULL || M->next == NULL)
		return NULL;

	int length1=0, length2=0;
	lnode* p1 = L->next;
	lnode* p2 = M->next;
	while (p1 != NULL) {
		length1++;
		p1 = p1->next;
	}
	while (p2 != NULL) {
		length2++;
		p2 = p2->next;
	}
	int flag = 0;//����Ƿ��ҵ������ڵ�,0Ϊδ�ҵ�,1Ϊ�ҵ�
	int length = abs(length2 - length1);
	p1 = L->next;
	p2 = M->next;
	if (length1 <= length2) {//L��M��,�ƶ�M��ָ��
		while (length--) {//�ƶ�p2ָ��
			p2 = p2->next;
		}
		
		while (p1) {
			if (p2 == p1) {
				flag = 1;
				break;
			}
			else {
				p1 = p1->next;
				p2 = p2->next;
			}
		}
	}
	else {//L��M��,�ƶ�Lָ��
		while (length--) {//�ƶ�p1ָ��
			p1 = p1->next;
		}
		while (p1) {
			if (p1 == p2) {
				flag = 1;
				break;
			}
			else {
				p1 = p1->next;
				p2 = p2->next;
			}
		}
	}
	if (flag) {
		return p1;
	}
	return NULL;
}
int main()
{
	sqlist a = { {1,2,3,4,5,6,7,8,9},9 };
	linklist L = NULL;
	buildlist(&L,a);
	printf("��L\n");
	disp(L);

	sqlist b = { {44,55},2 };
	linklist M = NULL;
	buildlist_b(&M, b, L,5);//Ѱ��nΪ5�Ľڵ㲢�����ӵ�M����
	printf("��M\n");
	disp(M);

	lnode*result =search_public_lnode(L, M);
	if (result)
		printf("�����ڵ�ֵΪ%d\n", result->data);

	return 0;
}