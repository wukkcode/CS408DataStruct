#include <stdio.h>
#include <stdlib.h>
#include "auxiliary_queue.h"

bool visit_status[MaxVertexNum];
int distiance[MaxVertexNum];

int FindFirstNeighbor(AdjacencyListGraph ALQ, int current_vertex_index);
int FindNextNeighbor(AdjacencyListGraph ALQ, int current_vertex_index, int neighbor_vertex_index);

void VistVertex(int current_vertex_index);

/*
使用BFS,我们可以求解一个满足上述定义的非带权图的单源最短路径问题,这是由广度优
先搜索总是按照距离由近到远来遍历图中每个顶点的性质决定的。
*/
void CalculateMinDistanceWithBFS(AdjacencyListGraph ALG, int current_vertex_index)
{
    for (int i = 0; i < ALG.vertex_num; i++)
    {   
        distiance[i] = -1;
        visit_status[i] = false;
    }
    LinkListQueue LLQ;
    InitLinkListQueue(LLQ);
    distiance[current_vertex_index] = 0;
    visit_status[current_vertex_index] = true;
    EnLinkListQueue(LLQ, current_vertex_index);
    while (LinkListQueueIsEmpty(LLQ) == false)
    {
        DeLinkListQueue(LLQ, current_vertex_index);
        for (int neighbor_vertex_index = FindFirstNeighbor(ALG, current_vertex_index); neighbor_vertex_index > -1; neighbor_vertex_index = (ALG, current_vertex_index, neighbor_vertex_index))
        {
            if (visit_status[neighbor_vertex_index] == false)
            {
                visit_status[neighbor_vertex_index] = true;
                distiance[neighbor_vertex_index] = distiance[current_vertex_index] + 1;
                EnLinkListQueue(LLQ, neighbor_vertex_index);
            }
        }
    }
}