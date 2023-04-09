/*
先前一种循环队列结构需要浪费一个空间，来判断当前循环队列是否为空，当然我们可以在不浪费这一个空间的前提下，增加一个结构成员来表示当前队列的长度
*/

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
    int length;
} CircleSequenceQuence;

// 循环队列的初始化
void InitCircleSequenceQueue(CircleSequenceQuence &CSQ)
{
    CSQ.front = 0;
    CSQ.rear = 0;
    CSQ.length = 0;
}

// 判断循环队列是否为空
bool CircleSequenceQueueIsEmpty(CircleSequenceQuence CSQ)
{
    if (CSQ.length == 0)
    {
        return true;
    }
    return false;
}

// 判断循环队列是否为满
bool CircleSequenceQueueIsFull(CircleSequenceQuence CSQ)
{
    if (CSQ.length == MaxSize)
    {
        return true;
    }
    return false;
}

// 进队
bool EnCircleSequenceQueue(CircleSequenceQuence &CSQ, ElemType value)
{
    if (CircleSequenceQueueIsFull(CSQ) == true)
    {
        return false;
    }
    CSQ.data[CSQ.rear] = value;
    CSQ.rear = (CSQ.rear + 1) % MaxSize;
    CSQ.length++;
    return true;
}

// 出队
bool DeCircleSequenceQueue(CircleSequenceQuence &CSQ, ElemType &value)
{
    if (CircleSequenceQueueIsEmpty(CSQ) == true)
    {
        return false;
    }
    value = CSQ.data[CSQ.front];
    CSQ.front = (CSQ.front + 1) % MaxSize;
    CSQ.length--;
    return true;
}

// 获取队头元素
bool GetHeadFromCircleSequenceQueue(CircleSequenceQuence CSQ, ElemType &value)
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
    CircleSequenceQuence CSQ;
    InitCircleSequenceQueue(CSQ);
    for (int i = 0; i < 5; i++)
    {
        EnCircleSequenceQueue(CSQ, i + 1);
    }
    printf("Current queue length = %d\n", CSQ.length);
    ElemType value;
    DeCircleSequenceQueue(CSQ, value);
    printf("Queue head value = %d\n", value);
    printf("Current queue length = %d\n", CSQ.length);
    DeCircleSequenceQueue(CSQ, value);
    printf("Queue head value = %d\n", value);
    printf("Current queue length = %d\n", CSQ.length);
    DeCircleSequenceQueue(CSQ, value);
    printf("Queue head value = %d\n", value);
    printf("Current queue length = %d\n", CSQ.length);
    DeCircleSequenceQueue(CSQ, value);
    printf("Queue head value = %d\n", value);
    printf("Current queue length = %d\n", CSQ.length);
    DeCircleSequenceQueue(CSQ, value);
    printf("Queue head value = %d\n", value);
    printf("Current queue length = %d\n", CSQ.length);
    return 0;
}