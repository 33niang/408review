/*
删除单链表L中所有值为x的节点
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct lnode {
	int data;
	struct lnode* next;
}*linklist,lnode;

int a[4] = { 1,2,3,4 };
int n = 4;

//递归实现
void buildlist(linklist* L) {//创建无头结点的链表
	*L = NULL;
	lnode* r = NULL;//尾指针
	for (int i = 0; i < n; i++) {
		lnode* s = (lnode*)malloc(sizeof(lnode));
		s->data = a[i];
		s->next = NULL;
		if (*L == NULL) {//如果此时头结点刚初始化，那么就把s赋给头结点
			*L = s;
			r = s;
		}
		else {
			//如果此时链表中已经有了元素
			// 那就将尾指针指向新申请的s节点
			//并且将尾指针的位置移向s
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
		return;//空链表
	lnode* p = *L;
	if (p->data == x) {
		*L = p->next;
		free(p);
		deletex(L, x);
	}
	else {
		deletex(&((*L)->next), x);//当前节点非x，递归处理下个节点
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

	return 0;
}