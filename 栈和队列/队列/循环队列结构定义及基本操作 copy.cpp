#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef int ElemType;
//循环队列结构实现方式1：牺牲一个存储单元来区分队空还是队满
typedef struct
{
    ElemType data[MaxSize];
    int front;
    int rear;
} CircleSequenceQueue;

// 循环队列的初始化
void InitCircleSequenceQueue(CircleSequenceQueue &CSQ)
{
    CSQ.front = 0;
    CSQ.rear = 0;
}

// 判断循环队列是否为空
bool CircleSequenceQueueIsEmpty(CircleSequenceQueue CSQ)
{
    if (CSQ.front == CSQ.rear)
    {
        return true;
    }
    return false;
}

// 判断循环队列是否为满
bool CircleSequenceQueueIsFull(CircleSequenceQueue CSQ)
{
    if ((CSQ.rear + 1) % MaxSize == CSQ.front)
    {
        return true;
    }
    return false;
}

// 计算循环队列的长度
int GetLengthOfCircleSequenceQueue(CircleSequenceQueue CSQ)
{
    if (CircleSequenceQueueIsEmpty(CSQ) == true)
    {
        return 0;
    }
    return (CSQ.rear-CSQ.front+MaxSize) % MaxSize;
}

// 进队
bool EnCircleSequenceQueue(CircleSequenceQueue &CSQ, ElemType value)
{
    if (CircleSequenceQueueIsFull(CSQ) == true)
    {
        return false;
    }
    CSQ.data[CSQ.rear] = value;
    CSQ.rear = (CSQ.rear + 1) % MaxSize;
    return true;
}

// 出队
bool DeCircleSequenceQueue(CircleSequenceQueue &CSQ, ElemType &value)
{
    if (CircleSequenceQueueIsEmpty(CSQ) == true)
    {
        return false;
    }
    value = CSQ.data[CSQ.front];
    CSQ.front = (CSQ.front + 1) % MaxSize;
    return true;
}

// 获取队头元素
bool GetHeadFromCircleSequenceQueue(CircleSequenceQueue CSQ, ElemType &value)
{
    if (CircleSequenceQueueIsEmpty(CSQ) == true)
    {
        return false;
    }
    value = CSQ.data[CSQ.front];
    return true;
}

int main()
{
    CircleSequenceQueue CSQ;
    InitCircleSequenceQueue(CSQ);
    for (int i = 0; i < 5; i++)
    {
        EnCircleSequenceQueue(CSQ, i + 1);
    }
    int length = GetLengthOfCircleSequenceQueue(CSQ);
    printf("CSQ's length = %d", length);
    ElemType value;
    DeCircleSequenceQueue(CSQ, value);
    printf("Queue head value = %d\n", value);
    return 0;
}