//
// Created by sansan on 25-8-21.
// BFS 和 DFS 判断以邻接表存储的图中是否存在从i到j的路径
//

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
}VNode,AdjList[MaxVerterNum]; // 修正了 Vnode -> VNode

typedef struct {
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;

// 不想写了,好难啊
