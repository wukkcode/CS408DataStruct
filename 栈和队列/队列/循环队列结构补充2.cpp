/*
先前一种循环队列结构需要浪费一个空间，来判断当前循环队列是否为空，当然我们可以在不浪费这一个空间的前提下，增加一个tag数据成员来区分队空还是队列满
进队的时候tag=1，出队的时候tag=0
只有进队才能导致队列满，只有出队才能导致队列空
*/

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef int ElemType;
//循环队列结构实现方式3：添加额外成员变量tag
typedef struct
{
    ElemType data[MaxSize];
    int front;
    int rear;
    bool tag;
} CircleSequenceQuence;

// 循环队列的初始化
void InitCircleSequenceQueue(CircleSequenceQuence &CSQ)
{
    CSQ.front = 0;
    CSQ.rear = 0;
    CSQ.tag = false;
}

// 判断循环队列是否为空
bool CircleSequenceQueueIsEmpty(CircleSequenceQuence CSQ)
{
    if (CSQ.front == CSQ.rear && CSQ.tag == false)
    {
        return true;
    }
    return false;
}

// 判断循环队列是否为满
bool CircleSequenceQueueIsFull(CircleSequenceQuence CSQ)
{
    if (CSQ.front == CSQ.rear && CSQ.tag == true)
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
    CSQ.tag = true;
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
    CSQ.tag = false;
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
    printf("Current queue tag = %d\n", CSQ.tag);
    ElemType value;
    DeCircleSequenceQueue(CSQ, value);
    printf("Queue head value = %d\n", value);
    DeCircleSequenceQueue(CSQ, value);
    printf("Queue head value = %d\n", value);
    DeCircleSequenceQueue(CSQ, value);
    printf("Queue head value = %d\n", value);
    DeCircleSequenceQueue(CSQ, value);
    printf("Queue head value = %d\n", value);
    DeCircleSequenceQueue(CSQ, value);
    printf("Queue head value = %d\n", value);
    printf("Current queue tag = %d\n", CSQ.tag);
    return 0;
}