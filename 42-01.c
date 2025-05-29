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
//无头结点
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

//有头结点
void buildheadlist(linklist* L) {
	*L = (lnode*)malloc(sizeof(lnode));
	if (*L == NULL) {
		printf("分配失败\n");
		return;
	}
	(*L)->next = NULL;//头结点
	lnode* r = *L;//尾指针,指向头结点,不能为NULL
	for (int i = 0; i < n; i++) {
		lnode* s = (lnode*)malloc(sizeof(lnode));
		if (s == NULL) {//判断s分配内存是否成功
			printf("分配失败\n");
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
		printf("空表\n");
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
		printf("空表\n");
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