#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BinaryTreeNode
{
    ElemType data;
    struct BinaryTreeNode* left_child;
    struct BinaryTreeNode* right_child;
} BinaryTreeNode, *BinaryTree;

typedef struct LinkNode
{
    BinaryTreeNode* data;
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
bool EnLinkListQueue(LinkListQueue &LLQ, BinaryTreeNode* btn)
{
    LinkNode* new_node = (LinkNode *)malloc(sizeof(LinkNode));
    if (new_node == NULL)
    {
        return false;
    }
    new_node->data = btn;
    new_node->next = NULL;
    LLQ.rear->next = new_node;
    LLQ.rear = new_node;
    return true;
}

// 出队列
bool DeLinkListQueue(LinkListQueue &LLQ, BinaryTreeNode* &btn)
{
    // 判断队列是否为空
    if (LinkListQueueIsEmpty(LLQ) == true)
    {
        return false;
    }
    LinkNode* free_node = LLQ.front->next;
    btn = free_node->data;
    LLQ.front->next = free_node->next;
    if (free_node == LLQ.rear)
    {
        LLQ.rear = LLQ.front;
    }
    free(free_node);
    return true;
}