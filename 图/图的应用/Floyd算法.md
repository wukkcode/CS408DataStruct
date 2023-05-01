# 算法思想
使用动态规划思想，将问题划分为多个阶段，当前阶段的处理都是基于前一个阶段
# 代码实现
```c
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100

typedef char VertexType;
typedef int EdgeType;

typedef struct
{
    VertexType vertex[MaxVertexNum];
    EdgeType edge[MaxVertexNum][MaxVertexNum];
    int vertex_num;
    int edge_num;
} AdjacencyMatrixGraph;

bool InitGraph(AdjacencyMatrixGraph &graph);

int main()
{
    AdjacencyMatrixGraph graph;
    InitGraph(graph);
    int distance_matrix[MaxVertexNum][MaxVertexNum]; // 表示多源最短路径
    int path_matrix[MaxVertexNum][MaxVertexNum]; // 中转点
    for (int row = 0; row < MaxVertexNum; row++)
    {
        for (int column = 0; column < MaxVertexNum; column++)
        {
            path_matrix[row][column] = -1;
            distance_matrix[row][column] = graph.edge[row][column];
        }
    }
    for (int transit_point  = 0; transit_point < MaxVertexNum; transit_point++)
    {
        for (int row = 0; row < MaxVertexNum; row++)
        {
            for (int column = 0; column < MaxVertexNum; column++)
            {
                if (distance_matrix[row][column] > distance_matrix[row][transit_point] + distance_matrix[transit_point][column])
                {
                    distance_matrix[row][column] = distance_matrix[row][transit_point] + distance_matrix[transit_point][column];
                    path_matrix[row][column] = transit_point;
                }
            }
        }
    }
    return 0;
}
```
# 时间复杂度