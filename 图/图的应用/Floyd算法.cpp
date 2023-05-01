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

bool FloydAlgoritm(AdjacencyMatrixGraph graph, int distance_matrix[MaxVertexNum][MaxVertexNum], int path_matrix[MaxVertexNum][MaxVertexNum])
{
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
    return true;
}

// 通过path_matrix[]递归查找最短路径
bool GetShortestPath(int path_matrix[MaxVertexNum][MaxVertexNum], int start_index, int end_index)
{
    if (path_matrix[start_index][end_index] != -1)
    {        
        GetShortestPath(path_matrix, start_index, path_matrix[start_index][end_index]);
        printf("%-2d", start_index);
        GetShortestPath(path_matrix, path_matrix[start_index][end_index], end_index);
    }
}

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
}
