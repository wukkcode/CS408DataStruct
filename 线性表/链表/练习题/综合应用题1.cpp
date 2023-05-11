/*
1. 设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点。
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkListNode
{
    ElemType data;
    struct LinkListNode* next;
} LinkListNode, *LinkList;

// 链表的初始化（不带头节点）
bool InitLinkList(LinkList &LL)
{
    LL = NULL;
    return true;
}

// 链表的判空操作（不带头节点）
bool LinkListIsEmpty(LinkList LL)
{
    if (LL == NULL)
    {
        return true;
    }
    return false;
}

// 单链表的遍历
bool TraverseLinkList(LinkList LL)
{
    if (LL == NULL)
    {
        return false;
    }
    while (LL != NULL)
    {
        printf("%-2d", LL->data);
        LL = LL->next;
    }
    return true;
}

// 头插法建立单链表（不带头结点）
bool InsertLinkListFromHead(LinkList &LL)
{
    LinkListNode* new_node;
    ElemType node_value;
    scanf("%d", &node_value);
    while (node_value != 9999)
    {
        new_node = (LinkListNode *)malloc(sizeof(LinkListNode));
        if (new_node == NULL)
        {
            return false;
        }
        new_node->data = node_value;
        new_node->next = NULL;
        if (LL == NULL)
        {
            LL = new_node;
        }
        else
        {
            new_node->next = LL;
            LL = new_node;
        }
        scanf("%d", &node_value);
    }
    return true;
}

// 尾插法建立单链表（不带头节点）
bool InsertLinkListFromTail(LinkList &LL)
{
    LinkListNode* new_node;
    LinkListNode* tail_node;
    ElemType node_value;
    scanf("%d", &node_value);
    while (node_value != 9999)
    {
        new_node = (LinkListNode *)malloc(sizeof(LinkListNode));
        if (new_node == NULL)
        {
            return false;
        }
        new_node->data = node_value;
        new_node->next = NULL;
        if (LL == NULL)
        {
            LL = new_node;
            tail_node = LL;
        }
        else
        {
            tail_node->next = new_node;
            tail_node = new_node;
        }
        scanf("%d", &node_value);
    }
    return true;
}

// 删除指定节点（顺序扫描到的第一个）
bool DeleteLinkList(LinkList &LL, ElemType node_value)
{
    if (LL == NULL)
    {
        return false;
    }
    LinkListNode* free_node;
    if (LL->data == node_value)
    {
        free_node = LL;
        LL = free_node->next;
        free(free_node);
    }
    else {
        LinkListNode *temp_node = LL;
        while (temp_node->next != NULL && temp_node->next->data != node_value)
        {
            temp_node = temp_node->next;
        }
        if (temp_node->next != NULL) {
            free_node = temp_node->next;
            temp_node->next = free_node->next;
            free(free_node);
        }
    }
    return true;
}

// 递归删除所有指定的节点
bool DeleteLinkListUsingRecursion(LinkList &LL, ElemType node_value)
{
    if (LL == NULL)
    {
        return false;
    }
    if (LL->data == node_value)
    {
        LinkListNode* free_node = LL;
        LL = free_node->next;
        free(free_node);
        DeleteLinkListUsingRecursion(LL, node_value);
    }
    DeleteLinkListUsingRecursion(LL->next, node_value);
    return true;
}

int main()
{
    LinkList LL;
//    InitLinkList(LL);
//    InsertLinkListFromHead(LL);
    InitLinkList(LL);
    InsertLinkListFromTail(LL);
    TraverseLinkList(LL);
    printf("\n");
//    DeleteLinkList(LL, 7);
//    TraverseLinkList(LL);
    DeleteLinkListUsingRecursion(LL, 1);
    TraverseLinkList(LL);
    printf("\n");
    return 0;
}