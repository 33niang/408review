/*
��˳���ɾ��Ψһ����Сֵ�����ҷ���ɾ����ֵ��
ɾ����λ�������һ��Ԫ�����
����Ϊ�գ����ش�����Ϣ
*/
 
#include<stdio.h>

#define MAXSIZE 50

typedef struct SqList {
	int a[MAXSIZE];
	int length;
}SqList;

int DeleteMin(SqList* L,int* e) {
    if (L == NULL || e == NULL) {
        printf("��ָ��\n");
        return 0;
    }
    if (L->length == 0) {
        printf("������\n");
        return 0;
    }
    int min = L->a[0];
    int flag = 0;
    int i = 0;
    for (i = 1; i < L->length; i++) {
        if (L->a[i] < min) {
            flag = i;
            min = L->a[i];
        }
    }
    *e = min;
    //�����һ��Ԫ�طŵ���Сֵ��λ����
    L->a[flag] = L->a[L->length - 1];
    L->length--;
    return 1;
}
int main()
{
	SqList L;
    L.a[0] = 2;
    L.a[1] = 3;
    L.a[2] = 5;
    L.a[3] = 7;
    L.a[4] = 1; 
    L.a[5] = 9;
    L.a[6] = 8;
    L.a[7] = 55;
	L.length = 8;

    int i = 0;
    printf("֮ǰ");
    for (i = 0; i < L.length; i++) {
        printf("%d ", L.a[i]);
    }
    printf("\n");
    int e=0;
    if (DeleteMin(&L, &e)) {

        printf("֮��");
        for (i = 0; i < L.length; i++) {
            printf("%d ", L.a[i]);
        }
        printf("\n");
        printf("��СֵΪ%d", e);
    }
    else {
        printf("error\n");
    }

    return 0;
}