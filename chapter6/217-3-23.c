//
// Created by sansan on 25-8-21.
// DFS非递归算法,邻接表存储
//

#include<stdio.h>
#include<stdlib.h>


#define MaxVerterNum 100
typedef char VertexType;
typedef int EdgeType;

typedef struct ArcNode {
    int adjvex;
    struct ArcNode*nextarc;
    // InfoType info;
}ArcNode;

typedef struct VNode {
    VertexType data;
    ArcNode*firstarc;
}VNode,AdjList[MaxVerterNum]; 

typedef struct {
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;

void CreateALGraph(ALGraph*G,VertexType v[],int arcs[][2],int Vexnum,int arcNum) {
    int i;
    G->vexnum=Vexnum;
    G->arcnum=arcNum;
    for (i=0;i<G->vexnum;i++) {
        G->vertices[i].data=v[i];
        G->vertices[i].firstarc=NULL; 
    }

    for (i=0;i<G->arcnum;i++) {
        int v0_idx=arcs[i][0]; 
        int v1_idx=arcs[i][1]; 
        // 头插加入v0->v1的边
        ArcNode *p1=(ArcNode*)malloc(sizeof(ArcNode));
        p1->adjvex=v1_idx;
        p1->nextarc=G->vertices[v0_idx].firstarc;
        G->vertices[v0_idx].firstarc=p1;
        // 头插加入一条v1->v0的边
        ArcNode *p2=(ArcNode*)malloc(sizeof(ArcNode));
        p2->adjvex=v0_idx;
        p2->nextarc=G->vertices[v1_idx].firstarc;
        G->vertices[v1_idx].firstarc=p2;
    }
}

void PrintALGraph(ALGraph G) {
    printf("邻接表:\n");
    for (int i=0;i<G.vexnum;i++) {
        printf("顶点%c-> ",G.vertices[i].data);
        ArcNode *p=G.vertices[i].firstarc;
        while (p) {
            // 修正了 G.vertices[i].data -> G.vertices[p->adjvex].data
            printf("%d(%c) ",p->adjvex,G.vertices[p->adjvex].data);
            p=p->nextarc;
        }
        printf("\n");
    }
}

#define STACK_SIZE 100
typedef struct {
    int data[STACK_SIZE];
    int top;
} Stack;

void InitStack(Stack *s) {
    s->top = -1;
}

int IsEmpty(Stack s) {
    return s.top == -1;
}

void Push(Stack *s, int value) {
    if (s->top < STACK_SIZE - 1) {
        s->data[++s->top] = value;
    }
}

int Pop(Stack *s) {
    if (!IsEmpty(*s)) {
        return s->data[s->top--];
    }
    return -1; 
}

// 从顶点v开始的非递归DFS遍历
void stack_DFS_ALG(ALGraph G, int v) {
    Stack s;
    InitStack(&s);

    int visited[MaxVerterNum];
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = 0; // 0 表示未访问
    }

    printf("非递归DFS遍历顺序: ");

    // 将起始顶点入栈
    Push(&s, v);

    while (!IsEmpty(s)) {
        int k = Pop(&s); // 弹出一个顶点

        // 只有当顶点未被访问时才处理
        if (!visited[k]) {
            printf("%c ", G.vertices[k].data); // 访问顶点
            visited[k] = 1;

            // 查找k的所有邻接点, 并将它们逆序入栈
            // 这样可以保证遍历顺序和递归版类似
            ArcNode *p = G.vertices[k].firstarc;
            Stack temp_stack; // 使用临时栈来倒序
            InitStack(&temp_stack);

            while (p) {
                if (!visited[p->adjvex]) {
                    Push(&temp_stack, p->adjvex);
                }
                p = p->nextarc;
            }
            // 将临时栈的元素压回主栈
            while(!IsEmpty(temp_stack)){
                Push(&s, Pop(&temp_stack));
            }
        }
    }
    printf("\n");
}

int main() {
    ALGraph G;
    VertexType vex[] = {'a', 'b', 'c', 'd', 'e'};
    int arcs[][2] = {
        {0, 1}, // a-b
        {1, 2}, // b-c
        {1, 3}, // b-d
        {2, 4} // c-e
    };
    CreateALGraph(&G, vex, arcs, 5, 4);
    PrintALGraph(G);

    // 从顶点 0 ('a') 开始进行非递归DFS
    stack_DFS_ALG(G, 0);

    return 0;
}
