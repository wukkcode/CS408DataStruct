#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10

typedef int ElemType;
typedef struct StaticLinkList
{
    ElemType data;
    int next;
} StaticLinkList[MaxSize];

bool InitStaticLinkList(StaticLinkList SLL)
{
    // 头节点指针域设置为-1来表示静态链表为空
    SLL[0].next = -1;

    // 将其他指针域设置成特殊值，以便后序操作
    for (int i = 1; i < MaxSize; i++)
    {
        SLL[i].next = -2;
    }
    return true;
}

int main()
{
    
}

