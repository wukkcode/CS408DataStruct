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


// 算法思想
/*
和树的深度度优先遍历一样，先访问该节点，然后访问该节点的邻接顶点
*/

// 算法的性能分析
/*
1. 空间复杂度
在深度优先中我们要使用递归，所以空间复杂度主要来自于递归工作栈，最坏情况下递归工作栈的深度为
|V|，所以空间复杂度为O(|V|)
---
2. 时间复杂度
在每一个递归DFS函数中我们需要访问每一个顶点；还需要在for循环中探索所有的边（邻接顶点）
---
对于邻接矩阵存储的图：
访问|V|个顶点需要O(|V|)的时间
查找每个顶点的邻接点都需要O(|V|)（遍历邻接矩阵的某一行/某一列），有|V|个顶点
则访问邻接顶点需要O(|V|^2)
所以总的时间复杂度为O(|V| + |V|^2) = O(|V|^2)
---
对于邻接表所存储的图
访问|V|个顶点需要O(|V|)的时间
查找每个顶点的邻接点都需要遍历该顶点的边链表，总共有2|E|个边节点（双倍边节点存储），而对于无向图如果要遍历
所有顶点的邻接点则需要查找2|E|次，所以查找所有的邻接点的时间复杂度为O(|E|)
所以总的时间复杂度为O(|V| + |E|)
---  
*/