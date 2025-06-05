//偶数个节点不带头单链表,节点值均大于0
//求该链表最大孪生和即
// a[i]+a[n-i-1],i从0开始


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
	//仅针对这道题的reverse,对L的下一个节点进行头插逆置
	//L本身不动,L在这里类似于一个头结点
	//所以不需要返回lnode*,直接用传入的L就行
	if (!L || !L->next)
		return;
	lnode* p = L->next,*r=L;
	L->next = NULL;//分离原链表
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
	lnode* slow = L, * fast = L->next;//相当于默认走出去一步
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