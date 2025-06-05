//ż�����ڵ㲻��ͷ������,�ڵ�ֵ������0
//���������������ͼ�
// a[i]+a[n-i-1],i��0��ʼ


#include<stdio.h>
#include<stdlib.h>

typedef struct lnode {
	int data;
	struct lnode* next;
}lnode,*linklist;

int a[] = { 1,25,6,78,4,45,6,75,87,94 };
int n = 10;

void buildlist(linklist* L) {
	(*L) = (lnode*)malloc(sizeof(lnode));
	if (!(*L))
		return;
	(*L)->data = a[0];
	lnode* r = (*L), * s;
	for (int i = 1; i < n; i++) {
		s = (lnode*)malloc(sizeof(lnode));
		if (!s)
			return;
		s->data = a[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

void disp(linklist L) {
	if (!L)
		return;
	lnode* p = L;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void reverse(linklist L) {
	//�����������reverse,��L����һ���ڵ����ͷ������
	//L������,L������������һ��ͷ���
	//���Բ���Ҫ����lnode*,ֱ���ô����L����
	if (!L || !L->next)
		return;
	lnode* p = L->next,*r=L;
	L->next = NULL;//����ԭ����
	while (p) {
		lnode* temp = p;
		p = p->next;
		temp->next = r->next;
		r->next = temp;
	}
}

int twins_num(linklist L) {
	if (!L || !L->next)
		return -1;
	lnode* slow = L, * fast = L->next;//�൱��Ĭ���߳�ȥһ��
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	reverse(slow);
	disp(L);
	lnode* front = L, *back = slow->next;
	int max=-1,temp;
	while (front&&back) {
		temp = front->data + back->data;
		if (temp > max)
			max = temp;
		front = front->next;
		back = back->next;
	}
	return max;

}

int main()
{
	linklist L = NULL;
	buildlist(&L);
	disp(L);
	printf("%d\n", twins_num(L));


	return 0;
}