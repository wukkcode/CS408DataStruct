#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LinkQueueNode
{
    ElemType data;
    struct LinkQueueNode* next;
} LinkQueueNode;

typedef struct
{
    LinkQueueNode* front;
    LinkQueueNode* rear;
} LinkQueue;

// 初始化链式队列
void InitLinkQueue(LinkQueue &LQ)
{
    LQ.front = LQ.rear = NULL;
}

// 判断队列是否为空
bool LinkQueueIsEmpty(LinkQueue LQ)
{
    if (LQ.front == NULL)
    {
        return true;
    }
    return false;
}

// 进队
bool EnLinkQueue(LinkQueue &LQ, ElemType value)
{
    LinkQueueNode* entered_node = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (entered_node == NULL)
    {
        return false;
    }
    entered_node->data = value;
    entered_node->next = NULL;
    if (LinkQueueIsEmpty(LQ) == true)
    {
        LQ.front = LQ.rear = entered_node;
    }
    else
    {
        LQ.rear->next = entered_node;
        LQ.rear = entered_node;
    }
    return true;
}

// 出队
bool DeLinkQueue(LinkQueue &LQ, ElemType &value)
{
    if (LinkQueueIsEmpty(LQ) == true)
    {
        return false;
    }
    LinkQueueNode* deleted_node = LQ.front;
    value = deleted_node->data;
    LQ.front = deleted_node->next;
    if (deleted_node == LQ.rear)
    {
        LQ.front = NULL;
        LQ.rear = NULL;
    }
    free(deleted_node);
    return true;
}

int main()
{
    LinkQueue LQ;
    InitLinkQueue(LQ);
    for (int i = 0; i < 5; i++)
    {
        EnLinkQueue(LQ, i+1);
    }
    ElemType value;
    DeLinkQueue(LQ, value);
    printf("value = %d\n", value);
    DeLinkQueue(LQ, value);
    printf("value = %d\n", value);
    DeLinkQueue(LQ, value);
    printf("value = %d\n", value);
    DeLinkQueue(LQ, value);
    printf("value = %d\n", value);
    DeLinkQueue(LQ, value);
    printf("value = %d\n", value);
    return 0;
}
