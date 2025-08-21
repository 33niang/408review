//
// Created by sansan on 25-8-21.
// BFS 和 DFS 判断以邻接表存储的图中是否存在从i到j的路径
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // 为了使用 bool 类型

#define MaxVerterNum 100
typedef char VertexType;
typedef int EdgeType;

// --- 图的邻接表结构定义 ---
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
    // InfoType info;
} ArcNode;

typedef struct VNode {
    VertexType data;
    ArcNode *firstarc;
} VNode, AdjList[MaxVerterNum];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

// --- 辅助队列结构定义 (BFS使用) ---
typedef struct {
    int data[MaxVerterNum];
    int front, rear;
} Queue;

void InitQueue(Queue *q) {
    q->front = q->rear = 0;
}

bool IsQueueEmpty(Queue q) {
    return q.front == q.rear;
}

void EnQueue(Queue *q, int x) {
    if ((q->rear + 1) % MaxVerterNum == q->front) {
        return; // 队列满
    }
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MaxVerterNum;
}

int DeQueue(Queue *q) {
    if (IsQueueEmpty(*q)) {
        return -1; // 队列空
    }
    int x = q->data[q->front];
    q->front = (q->front + 1) % MaxVerterNum;
    return x;
}

// --- DFS 递归辅助函数 ---
// 真正的递归逻辑在这里
void DFS_Path(ALGraph G, int i, int j, bool *found, bool visited[]) {
    visited[i] = true;

    if (i == j) {
        *found = true;
        return;
    }

    // 如果已找到路径，后续的递归直接返回，提高效率
    if (*found) {
        return;
    }

    ArcNode *p = G.vertices[i].firstarc;
    while (p) {
        if (!visited[p->adjvex]) {
            DFS_Path(G, p->adjvex, j, found, visited);
        }
        p = p->nextarc;
    }
}

// --- 判断i到j是否存在路径 (DFS版本) ---
// 这是外部调用的接口函数，负责初始化
bool exist_path_DFS(ALGraph G, int i, int j) {
    if (i < 0 || i >= G.vexnum || j < 0 || j >= G.vexnum) {
        return false; // 顶点无效
    }
    bool visited[MaxVerterNum];
    for (int k = 0; k < G.vexnum; k++) {
        visited[k] = false;
    }

    bool found = false;
    DFS_Path(G, i, j, &found, visited);
    return found;
}


// --- 判断i到j是否存在路径 (BFS版本) ---
bool exist_path_BFS(ALGraph G, int i, int j) {
    if (i < 0 || i >= G.vexnum || j < 0 || j >= G.vexnum) {
        return false; // 顶点无效
    }
    if (i == j) {
        return true;
    }

    bool visited[MaxVerterNum];
    for (int k = 0; k < G.vexnum; k++) {
        visited[k] = false;
    }

    Queue q;
    InitQueue(&q);

    EnQueue(&q, i);
    visited[i] = true;

    while (!IsQueueEmpty(q)) {
        int u = DeQueue(&q); // 取出队头元素
        ArcNode *p = G.vertices[u].firstarc;
        while (p) {
            int w = p->adjvex;
            // 如果找到目标顶点j，说明路径存在
            if (w == j) {
                return true;
            }
            // 如果邻接点w未被访问，则访问并入队
            if (!visited[w]) {
                visited[w] = true;
                EnQueue(&q, w);
            }
            p = p->nextarc;
        }
    }

    // 如果队列为空还没找到，说明路径不存在
    return false;
}

// 创建图的函数 (用于测试)
void CreateALGraph(ALGraph *G, VertexType v[], int arcs[][2], int vexNum, int arcNum) {
    G->vexnum = vexNum;
    G->arcnum = arcNum;
    for (int i = 0; i < G->vexnum; i++) {
        G->vertices[i].data = v[i];
        G->vertices[i].firstarc = NULL;
    }
    for (int i = 0; i < G->arcnum; i++) {
        int v0_idx = arcs[i][0];
        int v1_idx = arcs[i][1];
        ArcNode *p1 = (ArcNode*)malloc(sizeof(ArcNode));
        p1->adjvex = v1_idx;
        p1->nextarc = G->vertices[v0_idx].firstarc;
        G->vertices[v0_idx].firstarc = p1;

        ArcNode *p2 = (ArcNode*)malloc(sizeof(ArcNode));
        p2->adjvex = v0_idx;
        p2->nextarc = G->vertices[v1_idx].firstarc;
        G->vertices[v1_idx].firstarc = p2;
    }
}


int main() {
    ALGraph G;
    VertexType vex[] = {'a', 'b', 'c', 'd', 'e'};
    int arcs[][2] = {
        {0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}
    };
    CreateALGraph(&G, vex, arcs, 5, 5);

    int start_node = 0; // 顶点a
    int end_node = 4;   // 顶点e

    printf("--- 使用DFS查找路径 ---\n");
    if (exist_path_DFS(G, start_node, end_node)) {
        printf("存在从 %c 到 %c 的路径。\n", vex[start_node], vex[end_node]);
    } else {
        printf("不存在从 %c 到 %c 的路径。\n", vex[start_node], vex[end_node]);
    }

    printf("\n--- 使用BFS查找路径 ---\n");
    if (exist_path_BFS(G, start_node, end_node)) {
        printf("存在从 %c 到 %c 的路径。\n", vex[start_node], vex[end_node]);
    } else {
        printf("不存在从 %c 到 %c 的路径。\n", vex[start_node], vex[end_node]);
    }

    // 测试一个不存在的路径
    start_node = 1; // 顶点b
    end_node = 5;   // 无效顶点
    printf("\n--- 测试无效路径 ---\n");
    if (exist_path_DFS(G, start_node, end_node)) {
        printf("存在从 %c 到 无效顶点 的路径。\n", vex[start_node]);
    } else {
        printf("不存在从 %c 到 无效顶点 的路径。\n", vex[start_node]);
    }

    return 0;
}
