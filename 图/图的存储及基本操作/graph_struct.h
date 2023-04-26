#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 3

typedef char VertexType;
typedef char EdgeType;

// 边节点的结构
typedef struct ArcNode
{
    int vertex_node_index; // 边所指向节点的下标
    struct ArcNode* next; // 指向下一条边
    // int weight; // 边的权值
} ArcNode;

// 顶点结构
typedef struct VertexNode
{
    VertexType data; // 节点信息
    ArcNode* next; // 指向第一条边
} VertexNode, AdjacencyList[MaxVertexNum];

// 图的邻接表存储
typedef struct
{
    AdjacencyList vertex_nodes;
    int vertex_num;
    int arc_num;
} AdjacencyListGraph;

// 图的邻接矩阵存储结构
typedef struct
{
    VertexType vertex[MaxVertexNum];
    EdgeType edge[MaxVertexNum][MaxVertexNum];
    int vertex_num;
    int edge_num;
} AdjacencyMatrixGraph;