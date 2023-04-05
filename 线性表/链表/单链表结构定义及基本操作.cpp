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

// 按位置查找
bool LinkListSearchByPos(LinkList LL, int pos ,ElemType &node_value)
{
    // 判断链表是否为空
    if (LinkListIsEmpty(LL) == true)
    {
        return false;
    }

    // 判断查找位置是否合理
    if (pos < 1)
    {
        return false;
    }
    LinkNode* current_node = LL->next;
    int count = 1;
    while (current_node != NULL && count < pos)
    {
        current_node = current_node->next;
        count++;
    }
    node_value = current_node->data;
    return true;
}

// 按值查找
bool LinkListSearchByValue(LinkList LL, ElemType node_value, int &pos)
{
    if (LinkListIsEmpty(LL) == true)
    {
        printf("Linklist is empty!\n");
        return false;
    }
    LinkNode* current_node = LL->next;
    int count = 1;
    while (current_node != NULL && current_node->data != node_value)
    {
        current_node = current_node->next;
        count++;
    }
    if (current_node == NULL)
    {
        printf("No such a node!\n");
        return false;
    }
    pos = count;
    return true;
}

int main()
{
    LinkList LL;
    InitLinkList(LL);
//    LinkListInsertFromHead(LL);
    LinkListInsertFromTail(LL);
    TraverseLinkList(LL);
    ElemType node_value;
    LinkListSearchByPos(LL, 4, node_value);
    printf("node_value = %d\n", node_value);
    int pos;
    LinkListSearchByValue(LL, 9, pos);
    printf("position = %d\n", pos);
    return 0;
}