#include <stdio.h>
#include <stdlib.h>
#include "auxiliary_queue.h"

bool visit_status[MaxVertexNum];

VertexNode* FindFirstNeighbor(AdjacencyListGraph ALQ, VertexNode *current_vertex);
VertexNode* FindNextNeighbor(AdjacencyListGraph ALQ, VertexNode *current_vertex, VertexNode* neighbor_vertex);

void VistVertex(VertexNode* current_vertex)
{
    printf("%c", current_vertex->data);
}

void BreadthFirstSearch(AdjacencyListGraph ALG, int vertex_index, LinkListQueue LLQ)
{
    VistVertex(&ALG.vertex_nodes[vertex_index]);
    visit_status[vertex_index] = true;
    EnLinkListQueue(LLQ, &ALG.vertex_nodes[vertex_index]);
    VertexNode *current_vertex = NULL;
    while (LinkListQueueIsEmpty(LLQ) == false)
    {
        DeLinkListQueue(LLQ, current_vertex);
        for (VertexNode *neighbor_vertex = FindFirstNeighbor(ALG, current_vertex); neighbor_vertex != NULL; neighbor_vertex = FindNextNeighbor(ALG, current_vertex, neighbor_vertex))
        {
            if (visit_status[neighbor_vertex->vertex_index] == false)
            {
                VistVertex(neighbor_vertex);
                visit_status[neighbor_vertex->vertex_index] = true;
                EnLinkListQueue(LLQ, neighbor_vertex);
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
    for (int vertex_index = 0; vertex_index < ALG.vertex_num; vertex_index++)
    {
        if (visit_status[vertex_index] == false)
        {
            BreadthFirstSearch(ALG, vertex_index, LLQ);
        }
    }
}