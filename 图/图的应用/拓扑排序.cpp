#include "auxiliary_stack.h"
#define MaxVertexNum 3

typedef char VertexType;

// 边节点的结构
typedef struct ArcNode
{
    int vertex_node_index; // 边所指向节点的下标
    struct ArcNode* next_arc; // 指向下一条边
    // int weight; // 边的权值
} ArcNode;

// 顶点结构
typedef struct VertexNode
{
    VertexType data; // 节点信息
    ArcNode* first_arc; // 指向第一条边
} VertexNode, AdjacencyList[MaxVertexNum];

// 图的邻接表存储
typedef struct
{
    AdjacencyList vertex_nodes;
    int vertex_num;
    int arc_num;
} AdjacencyListGraph;

// 拓扑排序（基于邻接表）
bool TopologicalSorting(AdjacencyListGraph ALG, int vertex_in_degree[MaxVertexNum], int topological_sorting_sequence[MaxVertexNum])
{
    LinkStack LS;
    InitLinkStack(LS);
    int vertex_index;
    for (vertex_index = 0; vertex_index < MaxVertexNum; vertex_index++)
    {
        // 入度为0的节点入栈
        if (vertex_in_degree[vertex_index] == 0)
        {
            PushLinkStack(LS, vertex_index);
        }
    }
    int print_node_num = 0;
    while (LinkStackIsEmpty(LS) == false)
    {
        PopLinkStack(LS, vertex_index);
        topological_sorting_sequence[print_node_num++] = vertex_index;
        // 找到其当前顶点的所有邻接顶点，对其入度数组进行更改（删掉当前顶点的出边）
        for (ArcNode* adjacency_arc = ALG.vertex_nodes[vertex_index].first_arc; adjacency_arc; adjacency_arc = adjacency_arc->next_arc)
        {
            int next_vertex_index = adjacency_arc->vertex_node_index;
            if (--vertex_in_degree[next_vertex_index] == 0)
            {   
                PushLinkStack(LS, next_vertex_index);
            }
        }
    }
    if (print_node_num < ALG.vertex_num)
    {
        return false;
    }
    return true;
}


int main()
{
    AdjacencyListGraph ALG;
    int vertex_in_degree[MaxVertexNum]; // 存储各个顶点的入度信息
    int topological_sorting_sequence[MaxVertexNum];
    TopologicalSorting(ALG, vertex_in_degree, topological_sorting_sequence);
    return 0;
}