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
Floyd算法是典型的空间换时间的算法
## 空间复杂度
Floyd算法需要两个状态矩阵来暂存程序执行过程中的信息，所以时间空间复杂度为$O(2|V|^2) = O(|V|^2)$
## 时间复杂度
每一次循环都会增加一个新的中转点（在前一个阶段的基础上），共有|V|-1个中转点，时间复杂度为$O(|V|)$

在增加了新的中转点之后，需要更改`distance[][]`和`path[][]`矩阵的值，修改两个矩阵的时间复杂度为$O(2|V|^2) = O(|V|^2)$

所以总的时间复杂度为$O(|V|^3)$

# 注意
Floyd算法适合负权值无环图

前面的Dijstra算法可通过$O(|V|^2)$，找到一个顶点到其余顶点的最短路径，则对每一个顶点都执行一次Dijstra算法，可以找到各个顶点间的最短路径，其时间复杂度为$O(|V|^2)$
