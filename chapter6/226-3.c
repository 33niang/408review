//
// Created by sansan on 25-8-21.
// 设计一个算法判断一个无向图G是否为一棵树
//

#include<stdio.h>
#include<stdlib.h>

// 邻接矩阵
#define MaxVerteNum 100
typedef char VertexType;
typedef int EdgeType;

typedef struct {
    VertexType vex[MaxVerteNum]; // 顶点表
    EdgeType edge[MaxVerteNum][MaxVerteNum]; // 边表
    int vexnum, arcnum; // 实际的顶点数和边数
} MGraph;

// 邻接表
typedef struct ArcNode {
    // 边表节点
    int adjvex;
    struct ArcNode *nextarc;
    // InfoType info = 1; // 权值,先不用管
} ArcNode;

typedef struct VNode {
    VertexType data;
    ArcNode *firstarc;
} VNode, AdjList[MaxVerteNum];

typedef struct {
    AdjList vertices;
    int vexmum, arcnum;
} ALGraph;

// arcs是边集,是一个行数不确定,但是列数只有2的数组
void CreateMGraph(MGraph *G, VertexType v[], int arcs[][2], int vexNum, int arcNum) {
    int i, j;
    // 将图修改为实际大小
    G->vexnum = vexNum;
    G->arcnum = arcNum;
    // 初始所有的边为0
    for (i = 0; i < G->vexnum; i++)
        for (j = 0; j < vexNum; j++)
            G->edge[i][j] = 0;
    // 创建顶点表
    for (i = 0; i < G->vexnum; i++)
        G->vex[i] = v[i];

    for (i = 0; i < G->arcnum; i++) {
        int v1_idx = arcs[i][0];
        int v2_idx = arcs[i][1];
        G->edge[v1_idx][v2_idx] = 1; // 无向图对称摆
        G->edge[v2_idx][v1_idx] = 1;
    }
}

// 打印邻接矩阵
void PrintMGraph(MGraph G) {
    printf("顶点列表:\n");
    printf("  ");
    for (int i = 0; i < G.vexnum; i++)
        printf("%c ", G.vex[i]);
    printf("\n");
    // printf("邻接矩阵:\n");
    for (int i = 0; i < G.vexnum; i++) {
        printf("%c ", G.vex[i]);
        for (int j = 0; j < G.vexnum; j++)
            printf("%d ", G.edge[i][j]);
        printf("\n");
    }
}

// 邻接表
void CreateALGraph(ALGraph *G, VertexType v[], int arcs[][2], int vexNum, int arcNum) {
    int i;
    G->vexmum = vexNum;
    G->arcnum = arcNum;
    // 初始化邻接表
    for (i = 0; i < G->vexmum; i++) {
        G->vertices[i].data = v[i];
        G->vertices[i].firstarc = NULL;
    }
    for (i = 0; i < G->arcnum; i++) {
        int v1_idx = arcs[i][0];
        int v2_idx = arcs[i][1];
        // 头插法加入一条v1->v2的边
        ArcNode *p1 = (ArcNode *) malloc(sizeof(ArcNode));
        p1->adjvex = v2_idx;
        p1->nextarc = G->vertices[v1_idx].firstarc;
        G->vertices[v1_idx].firstarc = p1;
        // 头插法加入一条v2->v1的边
        ArcNode *p2 = (ArcNode *) malloc(sizeof(ArcNode));
        p2->adjvex = v1_idx;
        p2->nextarc = G->vertices[v2_idx].firstarc;
        G->vertices[v2_idx].firstarc = p2;
    }
}

void PrintALGraph(ALGraph G) {
    printf("邻接表\n");
    for (int i = 0; i < G.vexmum; i++) {
        printf("顶点%c-> ", G.vertices[i].data);
        ArcNode *p = G.vertices[i].firstarc;
        while (p) {
            printf("%d(%c) ", p->adjvex, G.vertices[p->adjvex].data);
            p = p->nextarc;
        }
        printf("\n");
    }
}

// DFS 邻接矩阵 vex为开始节点的下标
void DFS_M(MGraph G, int vex_idx, int visited[]) {
    visited[vex_idx] = 1; // 当前节点已访问
    for (int i = 0; i < G.vexnum; i++)
        if (G.edge[vex_idx][i] == 1 && visited[i] == 0) // 寻找当前节点相连的第一个未被访问的节点
            DFS_M(G, i, visited);
}

int is_tree_M_DFS(MGraph G) {
    if (G.arcnum != G.vexnum - 1)
        return 0; // 边数不对,直接判负
    int visited[G.vexnum];
    int i;
    for (i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    // 从第vex_idx个节点开始遍历
    int vex_idx = 1;
    DFS_M(G, vex_idx, visited);
    for (i = 0; i < G.vexnum; i++)
        if (visited[i] == 0)
            return 0;
    return 1;
}

int main() {
    MGraph G1;
    VertexType vex[] = {'a', 'b', 'c', 'd', 'e'};
    int arcs[][2] = {
        {0, 1}, // a-b
        {1, 2}, // b-c
        {1, 3}, // b-d
        {2, 4} // c-e
    };
    CreateMGraph(&G1, vex, arcs, 5, 4);
    PrintMGraph(G1);

    ALGraph G2;
    CreateALGraph(&G2, vex, arcs, 5, 4);
    PrintALGraph(G2);

    if (is_tree_M_DFS(G1)) {
        printf("图G1是一棵树\n");
    } else {
        printf("图G1不是一棵树\n");
    }
    MGraph G3;
    int arcs3[][2] = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 0}
    };
    CreateMGraph(&G3, vex, arcs3, 5, 5);
    if (is_tree_M_DFS(G3)) {
        printf("图G3是一棵树\n");
    } else {
        printf("图G3不是一棵树\n");
    }
    return 0;
}
