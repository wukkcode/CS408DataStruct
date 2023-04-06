/*
相比普通双链表没有什么大的变化，只不过让尾部节点next指针指向头节点，头节点prior指针指向尾部节点
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DoubleLinkNode
{
    ElemType data;
    struct DoubleLinkNode* next;
    struct DoubleLinkNode* prior;
} DoubleLinkNode, *DoubleLinkList;

bool InitDoubleCircleLinkList(DoubleLinkList &DCLL)
{
    DCLL = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode));
    if (DCLL == NULL)
    {
        return false;
    }
    DCLL->next = DCLL;
    DCLL->prior = DCLL;
    return true;
}

bool CircleDoubleLinkListIsEmpty(DoubleLinkList &DCLL)
{
    if (DCLL->next == DCLL)
    {
        return true;
    }
    return false;
}

// 循双链表的其他基本操作和普通双链表的基本操作类似，读者可自行修改写出