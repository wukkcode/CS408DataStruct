#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LinkNode
{
    ElemType data;
    struct LinkNode* next;
} LinkNode, *LinkList;

// 初始化单链表
bool InitLinkList(LinkList &LL)
{
    LL = (LinkNode *)malloc(sizeof(LinkNode));
    if (LL == NULL)
    {
        return false;
    }
    LL->next = NULL;
    return true;
}

// 判断单链表是否为空
bool LinkListIsEmpty(LinkList LL)
{
    if (LL->next == NULL)
    {
        return true;
    }
    return false;
}

// 单链表的遍历
bool TraverseLinkList(LinkList LL)
{
    if (LinkListIsEmpty(LL) == true)
    {
        return false;
    }
    LinkNode* current_node = LL->next;
    while (current_node != NULL)
    {
        printf("%-2d", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
    return true;
}

// 头插法建单链表
bool LinkListInsertFromHead(LinkList LL)
{
    LinkNode* inserted_node;
    ElemType node_value;
    scanf("%d", &node_value);
    while (node_value != 9999)
    {
        inserted_node = (LinkNode *)malloc(sizeof(LinkNode));
        if (inserted_node == NULL)
        {
            return false;
        }
        inserted_node->data = node_value;
        inserted_node->next = LL->next;
        LL->next = inserted_node;
        scanf("%d", &node_value);
    }
    return true;
}

// 尾插法建立单链表
bool LinkListInsertFromTail(LinkList LL)
{
    LinkNode* tail_node = LL;
    LinkNode* inserted_node;
    ElemType node_value;
    scanf("%d", &node_value);
    while (node_value != 9999)
    {
        inserted_node = (LinkNode *)malloc(sizeof(LinkNode));
        if (inserted_node == NULL)
        {
            return false;
        }
        inserted_node->data = node_value;
        inserted_node->next = NULL;
        tail_node->next = inserted_node;
        tail_node = inserted_node;
        scanf("%d", &node_value);
    }
    return true;
}


int main()
{
    LinkList LL;
    InitLinkList(LL);
//    LinkListInsertFromHead(LL);
    LinkListInsertFromTail(LL);
    TraverseLinkList(LL);
    return 0;
}