#include <stdio.h>
#include <stdlib.h>
#include "auxiliary_queue.h"

bool visit_status[MaxVertexNum];
int distance[MaxVertexNum];
int pre_path[MaxVertexNum];

int FindFirstNeighbor(AdjacencyListGraph ALQ, int current_vertex_index);
int FindNextNeighbor(AdjacencyListGraph ALQ, int current_vertex_index, int neighbor_vertex_index);

void VistVertex(int current_vertex_index);

/*
使用BFS,我们可以求解一个满足上述定义的非带权图(或者说权值都一样)的单源最短路径问题,这是由广度优
先搜索总是按照距离由近到远来遍历图中每个顶点的性质决定的。

其核心思想就是，BFS保证从起点出发经过最少的边到达目标顶点的路径就是最短路径
*/
void CalculateMinDistanceWithBFS(AdjacencyListGraph ALG, int current_vertex_index)
{
    // 初始化
    for (int i = 0; i < ALG.vertex_num; i++)
    {   
        visit_status[i] = false;
        distance[i] = -1;
        pre_path[i] = -1;
    }
    LinkListQueue LLQ;
    InitLinkListQueue(LLQ);
    distance[current_vertex_index] = 0;
    pre_path[current_vertex_index] = current_vertex_index;
    visit_status[current_vertex_index] = true;
    EnLinkListQueue(LLQ, current_vertex_index);
    while (LinkListQueueIsEmpty(LLQ) == false)
    {
        DeLinkListQueue(LLQ, current_vertex_index);
        for (int neighbor_vertex_index = FindFirstNeighbor(ALG, current_vertex_index); neighbor_vertex_index > -1; neighbor_vertex_index = (ALG, current_vertex_index, neighbor_vertex_index))
        {
            if (visit_status[neighbor_vertex_index] == false)
            {
                distance[neighbor_vertex_index] = distance[current_vertex_index] + 1;
                pre_path[neighbor_vertex_index] = current_vertex_index;
                visit_status[neighbor_vertex_index] = true;
                EnLinkListQueue(LLQ, neighbor_vertex_index);
            }
        }
    }
}