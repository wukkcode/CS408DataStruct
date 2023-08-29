#include <stdio.h>
#include <stdlib.h>
#include "auxiliary_queue.h"

bool visit_status[MaxVertexNum];

int FindFirstNeighbor(AdjacencyListGraph ALQ, int current_vertex_index);
int FindNextNeighbor(AdjacencyListGraph ALQ, int current_vertex_index, int neighbor_vertex_index);

void VistVertex(int current_vertex_index);

void DepthFirstSearch(AdjacencyListGraph ALG, int current_vertex_index)
{
    VistVertex(current_vertex_index);
    visit_status[current_vertex_index] = true;
    for (int neighbor_vertex_index = FindFirstNeighbor(ALG, current_vertex_index); neighbor_vertex_index > -1; neighbor_vertex_index = FindNextNeighbor(ALG, current_vertex_index, neighbor_vertex_index))
    {
        if (visit_status[neighbor_vertex_index] == false)
        {
            DepthFirstSearch(ALG, neighbor_vertex_index);
        }
    }
}

void DepthFirstSearchTraverse(AdjacencyListGraph ALG)
{
    for (int i = 0; i < ALG.vertex_num; i++)
    {
        visit_status[i] = false;
    }
    for (int current_vertex_index = 0; current_vertex_index < ALG.vertex_num; current_vertex_index++)
    {
        if (visit_status[current_vertex_index] == false)
        {
            DepthFirstSearch(ALG, current_vertex_index);
        }
    }
}

void DFSTraverse (Graph G)
{
    for(v=0;v<G.vexnum;++v)
    {
        visited[v] = false;
    }
    for (v=0; v<G.vexnum; ++v)
    {
        if(visited[v] == false)
        {
            DFS(G,v);
        }
    }
}


void DFS (Graph G, int v)
{
    visit (v);
    visited [v] = true;
    for(w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w))
    {
        if (! visited[w])
        {
            DFS(G,w);
        {
    }
}


// 算法思想
/*
和树的深度优先遍历（先序遍历）一样，先访问该节点，然后访问该节点的邻接顶点
*/

// 算法的性能分析
/*
1. 空间复杂度
DFS算法是一个递归算法，需要借助一个递归工作栈，最坏情况下递归工作栈的深度为 |V|，所以空间复杂度为 O(|V|)。
---
2. 时间复杂度
在每一个递归DFS函数中我们需要访问每一个顶点；还需要在for循环中探索所有的边（邻接顶点）
---
对于邻接矩阵存储的图：
共有 |V| 个顶点，查找每一个顶点的邻接顶点的时间复杂度为 O(|V|)，所以总的时间复杂度为 O(|V|^2)
---
对于邻接表所存储的图
查找找所有顶点的邻接点所需的时间为 O(|E|)，访问顶点所需的时间为 O(|V|)，此时，总的时间复杂度为 O(|V|+|E|)。
---  
*/