//
// Created by sansan on 25-8-31.
// DFS实现有向无环图拓扑排序
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxVerterNum 100

// --- 图的邻接表结构定义 ---
typedef char VertexType;

typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode {
    VertexType data;
    ArcNode *firstarc;
} VNode, AdjList[MaxVerterNum];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

// 用于打印路径的辅助函数
void print_path(ALGraph G, int path[], int path_len) {
    for (int i = 0; i < path_len; i++) {
        printf("%c", G.vertices[path[i]].data);
        if (i < path_len - 1) {
            printf(" -> ");
        }
    }
    printf("\n");
}

// 查找所有路径的DFS递归辅助函数
void find_all_paths_util(ALGraph G, int u, int j, bool visited[], int path[], int path_index) {
    // 1. 将当前节点加入路径，并标记为“在当前路径中”
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // 2. 如果当前节点是终点，则打印路径
    if (u == j) {
        print_path(G, path, path_index);
    } else {
        // 3. 如果不是终点，遍历其所有邻接点
        ArcNode *p = G.vertices[u].firstarc;
        while (p) {
            int v = p->adjvex;
            // 如果邻接点v不在当前路径中，则递归访问
            if (!visited[v]) {
                find_all_paths_util(G, v, j, visited, path, path_index);
            }
            p = p->nextarc;
        }
    }

    // 4. 回溯：将当前节点从路径中“移除”，并取消其访问标记
    // 这样，其他路径就可以再次访问这个节点了
    path_index--;
    visited[u] = false;
}

// 查找从i到j所有简单路径的外部接口函数
void find_all_simple_paths(ALGraph G, int i, int j) {
    if (i < 0 || i >= G.vexnum || j < 0 || j >= G.vexnum) {
        printf("顶点索引无效。\n");
        return;
    }

    // visited数组记录节点是否在当前递归栈（即当前路径）中
    bool visited[MaxVerterNum];
    // path数组用于存储当前路径
    int path[MaxVerterNum];
    int path_index = 0;

    // 初始化visited数组
    for (int k = 0; k < G.vexnum; k++) {
        visited[k] = false;
    }

    printf("从 %c 到 %c 的所有简单路径如下:\n", G.vertices[i].data, G.vertices[j].data);
    // 调用递归辅助函数开始搜索
    find_all_paths_util(G, i, j, visited, path, path_index);
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

        // 如果是无向图，添加反向边
        ArcNode *p2 = (ArcNode*)malloc(sizeof(ArcNode));
        p2->adjvex = v0_idx;
        p2->nextarc = G->vertices[v1_idx].firstarc;
        G->vertices[v1_idx].firstarc = p2;
    }
}


int main() {
    ALGraph G;
    VertexType vex[] = {'A', 'B', 'C', 'D', 'E'}; // 0, 1, 2, 3, 4
    // 创建一个有多个路径的图
    int arcs[][2] = {
        {0, 1}, {0, 2}, {0, 3},
        {1, 2}, {1, 4},
        {2, 3}, {2, 4},
        {3, 4}
    };
    CreateALGraph(&G, vex, arcs, 5, 8);

    int start_node = 0; // 顶点'A'
    int end_node = 4;   // 顶点'E'

    find_all_simple_paths(G, start_node, end_node);

    return 0;
}
