/*
��ͷ����ѭ��˫����,�ṹΪdata,freq,pre,next
ÿ��locate(L,x)ʱ,��Ӧ��freq+1
����������������ʹ�������Ƶ�ȵݼ�
Ƶ��һ���ĸ������ʵĽڵ����ǰ
��locate��������ֵΪx��ָ��
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct sqlist {
	int data[50];
	int length;
}sqlist;

typedef struct lnode {
	int data;
	int freq;
	struct lnode* pre;
	struct lnode* next;
}lnode, * linklist;

void buildlist(linklist* L, sqlist a) {//����ѭ��˫����
	*L = (lnode*)malloc(sizeof(lnode));
	if (!(*L))
		return;
	lnode* s, * r = (*L);

	for (int i = 0; i < a.length; i++) {
		s = (lnode*)malloc(sizeof(lnode));
		if (!s)
			return;
		s->data = a.data[i];
		s->freq = 0;
		r->next = s;
		s->pre = r;
		r = r->next;
	}
	r->next = NULL;
	(*L)->pre = NULL;
}

void disp(linklist L) {
    if (!L) return;
    lnode* p = L->next;
    while (p) {
        //printf("%d(freq:%d) ", p->data, p->freq);
		printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


lnode* locate(linklist L, int x) {
	if (!L)
		return NULL;
	if (L->next == NULL) {
		return NULL;
	}
	lnode* p = L->next;//������������x�ж�
	lnode* s = L;//ͷ���,�ҵ�p֮���ͷ�������������
	while (p) {
		if (p->data == x) {
			p->freq++;
			if (p->next) {//�ж�β�ڵ�
				p->next->pre = p->pre;
			}
			p->pre->next = p->next;
			while (s->next&&p->freq < s -> next->freq) //Ѱ�Ҳ���λ��
				s = s->next;
			p->next = s->next;//��x��Ӧ�Ľڵ�嵽��Ӧ��λ��
			p->pre = s;
			if(s->next)
				s->next->pre = p;
			s->next = p;
			return p;	
		}
		p = p->next;
	}
	return NULL;
	return NULL;
}
int main() {
	sqlist a = { {1,2,3,4,5,6,7,8,9},9 }; // �����ֵͬ����
	linklist L = NULL;
	buildlist(&L, a);

	printf("��ʼ: ");
	disp(L); 

	printf("���ҵ�һ��3��: ");
	locate(L, 3);
	disp(L); 

	printf("���ҵڶ���3��: ");
	locate(L, 3);
	disp(L); 

	printf("����5��: ");
	locate(L, 5);
	disp(L); 

	printf("����5��: ");
	locate(L, 5);
	disp(L);

	printf("����5��: ");
	locate(L, 5);
	disp(L);

	printf("����5��: ");
	locate(L, 5);
	disp(L);

	printf("��10��9��:");
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	locate(L, 9);
	disp(L);

	printf("��һ��Ԫ�ص�Ƶ��:%d\n", L->next->freq);
	return 0;
}