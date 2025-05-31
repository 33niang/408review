/*
带头结点单链表原地逆置,空间复杂度o(1)
*/

#include<stdio.h>
#include<stdlib.h>//负责malloc和free函数

typedef struct lnode {
	int data;
	struct lnode* next;
}lnode,*linklist;

typedef struct sqlist {
	int data[50];
	int length;
}sqlist;

//尾插法
void buildlist(linklist*L,sqlist a){
	*L = (lnode*)malloc(sizeof(lnode));//为头结点分配空间
	if (*L == NULL)//分配失败
		return;
	lnode* r=*L;//尾指针
	lnode* s;
	for (int i = 0; i < a.length; i++) {
		s = (lnode*)malloc(sizeof(lnode));
		if (s == NULL)//分配失败
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
	lnode* p = (*L)->next;//指向第一个元素 
	while (p) {
		lnode*s = p;//暂存需要free的节点
		p = p->next;
		free(s);
	}
	*L = NULL;
}

//头插法逆置
void list_reverse(linklist* L) {
	if ((*L) == NULL || (*L)->next == NULL)
		return;
	lnode* p = (*L)->next;//把p节点头插到L的后面
	lnode* r ;//指向p节点的下一个位置,防止断链
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