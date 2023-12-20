#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 4

typedef char VertexType;
typedef int EdgeType;

typedef struct
{
    VertexType vertex[MaxVertexNum]; // 顶点信息
    EdgeType edge[MaxVertexNum][MaxVertexNum]; // 边的信息
    int vertex_num;
    int edge_num;
} AdjacencyMatrixGraph;

int main()
{
    AdjacencyMatrixGraph graph;
    graph.vertex_num = 4;
    graph.edge_num = 0;
    for (int i = 0; i < graph.vertex_num; i++)
    {
        graph.vertex[i] = 'a' + i;
        for (int j = 0; j < graph.vertex_num; j++)
        {
            if (i == j)
            {
                graph.edge[i][j] = 0;
            }
            else
            {
                graph.edge[i][j] = 1;
                graph.edge_num++; // 最终结构为无向图的总度数
            }
        }
    }
    graph.edge_num /= 2; // 无向图边数等于总度数除以2
    return 0;
}
