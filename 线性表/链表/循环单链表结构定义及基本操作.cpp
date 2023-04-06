/*
相比普通单链表没有什么大的变化，只不过让尾部节点指向头节点
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LinkNode
{
    ElemType data;
    struct LinkNode* next;
} LinkNode, *LinkList;

bool InitCircleLinkList(LinkList &CLL)
{
    CLL = (LinkNode *)malloc(sizeof(LinkNode));
    if (CLL == NULL)
    {
        return false;
    }
    CLL->next = CLL;
    return true;
}

bool CircleLinkListIsEmpty(LinkList &CLL)
{
    if (CLL->next == CLL)
    {
        return true;
    }
    return false;
}

// 循环单链表的其他基本操作和普通单链表的基本操作类似，读者可自行修改写出