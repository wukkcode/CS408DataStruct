#include <stdio.h>
#include <stdlib.h>
#include "auxiliary_queue.h"

bool visit_status[MaxVertexNum];

int FindFirstNeighbor(AdjacencyListGraph ALQ, int current_vertex_index);
int FindNextNeighbor(AdjacencyListGraph ALQ, int current_vertex_index, int neighbor_vertex_index);

void VistVertex(int current_vertex_index);


void BreadthFirstSearch(AdjacencyListGraph ALG, int current_vertex_index, LinkListQueue LLQ)
{
    VistVertex(current_vertex_index);
    visit_status[current_vertex_index] = true;
    EnLinkListQueue(LLQ, current_vertex_index);
    while (LinkListQueueIsEmpty(LLQ) == false)
    {
        DeLinkListQueue(LLQ, current_vertex_index);
        for (int neighbor_vertex_index = FindFirstNeighbor(ALG, current_vertex_index); neighbor_vertex_index > -1; neighbor_vertex_index = FindNextNeighbor(ALG, current_vertex_index, neighbor_vertex_index))
        {
            if (visit_status[neighbor_vertex_index] == false)
            {
                VistVertex(neighbor_vertex_index);
                EnLinkListQueue(LLQ, neighbor_vertex_index);
                visit_status[neighbor_vertex_index] = true
            }
        }
    }
}

void BreadthFirstSearchTraverse(AdjacencyListGraph ALG)
{
    for (int i = 0; i < ALG.vertex_num; i++)
    {
        visit_status[i] = false;
    }
    LinkListQueue LLQ;
    InitLinkListQueue(LLQ);
    for (int current_vertex_index = 0; current_vertex_index < ALG.vertex_num; current_vertex_index++)
    {
        if (visit_status[current_vertex_index] == false)
        {
            BreadthFirstSearch(ALG, current_vertex_index, LLQ);
        }
    }
}