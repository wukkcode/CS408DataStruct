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
        // 访问当前节点所有的邻居节点，然后进队；如果当前节点没有邻居节点了，则退出for循环，执行出队操作
        for (int neighbor_vertex_index = FindFirstNeighbor(ALG, current_vertex_index); neighbor_vertex_index > -1; neighbor_vertex_index = FindNextNeighbor(ALG, current_vertex_index, neighbor_vertex_index))
        {
            if (visit_status[neighbor_vertex_index] == false)
            {
                VistVertex(neighbor_vertex_index);
                EnLinkListQueue(LLQ, neighbor_vertex_index);
                visit_status[neighbor_vertex_index] = true;
            }
        }
    }
}

// 检测有没有剩余没有访问的节点（非连通图）
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

// 算法思想
/*
和树的广度优先遍历一样，要通过当前节点找到与其相连的所有节点
*/

// 算法的性能分析
/*
1. 空间复杂度
主要来自我们构建的辅助队列，在最坏情况下，其他所有顶点都需要入队，所以空间复杂度为O(|V|)
在程序实现我们需要注意的是入队发生在for循环中找当前节点的邻接顶点的时候；出队发生在当前节点已经全部找到邻接顶点了，需要找队列中的下一个顶点的邻接顶点
---
2. 时间复杂度
在一个BFS函数中我们需要访问每一个顶点；还需要在for循环中探索所有的边（邻接顶点）
---
对于邻接矩阵存储的图：
两层循环，第一层循环while的时间复杂度是 \rm O(|V|)，主要是顶点节点的入队和出队；
第二层循环for的时间复杂度是 \rm O(|V|)，主要任务是找当前节点的邻接节点，即要遍历邻接矩阵的一行（列），时间复杂度为 \rm O(|V|)，
所以总的时间复杂度为 \rm O(|V|^2) 
---
对于邻接表所存储的图
访问|V|个顶点需要O(|V|)的时间
查找每个顶点的邻接点都需要遍历该顶点的边链表，总共有2|E|个边节点（双倍边节点存储），而对于无向图如果要遍历
所有顶点的邻接点则共需要查找2|E|次，所以查找所有的邻接点的时间复杂度为O(|E|)
所以总的时间复杂度为O(|V| + |E|)
---
思考：如果一个图没有边，时间复杂度该怎么分析？
调用|V|次BFS()函数，每个BFS函数中均访问一次顶点，但不会进入查找邻接顶点的循环
所以时间复杂度为O(|V|)  
*/