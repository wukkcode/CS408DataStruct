#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100

typedef char ElemType;
typedef char VertexType;

// 边节点的结构
typedef struct ArcNode
{
    int vertex_node_index; // 边所指向节点的下标
    struct ArcNode* next; // 指向下一条边
    // int weight; // 边的权值
} ArcNode;

// 顶点结构
typedef struct VertexNode
{
    VertexType data; // 节点信息
    ArcNode* next; // 指向第一条边
    int vertex_index; // 顶点在数组中的下标
} VertexNode, AdjacencyList[MaxVertexNum];

// 图的邻接表存储
typedef struct
{
    AdjacencyList vertex_nodes;
    int vertex_num;
    int arc_num;
} AdjacencyListGraph;

typedef struct LinkNode
{
    VertexNode* data;
    struct LinkNode* next;
} LinkNode, *LinkList;

typedef struct
{
    LinkNode* front;
    LinkNode* rear;
} LinkListQueue;

// 初始化链队
bool InitLinkListQueue(LinkListQueue &LLQ)
{
    LinkNode* head_node = (LinkNode *)malloc(sizeof(LinkNode));
    if (head_node == NULL)
    {
        return false;
    }
    head_node->next = NULL;
    LLQ.front = LLQ.rear = head_node;
    return true;
}

// 判断链队是否为空
bool LinkListQueueIsEmpty(LinkListQueue LLQ)
{
    if (LLQ.front == LLQ.rear)
    {
        return true;
    }
    return false;
}

// 进队列
bool EnLinkListQueue(LinkListQueue &LLQ, VertexNode* vt)
{
    LinkNode* new_node = (LinkNode *)malloc(sizeof(LinkNode));
    if (new_node == NULL)
    {
        return false;
    }
    new_node->data = vt;
    new_node->next = NULL;
    LLQ.rear->next = new_node;
    LLQ.rear = new_node;
    return true;
}

// 出队列
bool DeLinkListQueue(LinkListQueue &LLQ, VertexNode* &vt)
{
    // 判断队列是否为空
    if (LinkListQueueIsEmpty(LLQ) == true)
    {
        return false;
    }
    LinkNode* free_node = LLQ.front->next;
    vt = free_node->data;
    LLQ.front->next = free_node->next;
    if (free_node == LLQ.rear)
    {
        LLQ.rear = LLQ.front;
    }
    free(free_node);
    return true;
}