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
bool LinkListSearchByPos(LinkList LL, int pos , LinkNode* &target_node)
{
    // 判断链表是否为空
    if (LinkListIsEmpty(LL) == true)
    {
        return false;
    }

    // 判断查找位置是否合理(为了后序操作，可以查找第0个节点，即头节点)
    if (pos < 0)
    {
        return false;
    }
    LinkNode* current_node = LL;
    int count = 0;
    while (current_node != NULL && count < pos)
    {
        current_node = current_node->next;
        count++;
    }
    target_node = current_node;
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

// 在链表特定的位置插入节点
bool LinkListInsertedAtPos(LinkList LL, int pos, ElemType node_value)
{
    // 判断链表是否为空
    if (LinkListIsEmpty(LL) == true)
    {
        return false;
    }
    // 判断插入位置是否合理
    if (pos < 1)
    {
        return false;
    }
    // 找到要插入节点的前一个节点
    LinkNode* pre_node;
    LinkListSearchByPos(LL, pos-1, pre_node);
    LinkNode* inserted_node = (LinkNode *)malloc(sizeof(LinkNode));
    inserted_node->data = node_value;
    inserted_node->next = pre_node->next;
    pre_node->next = inserted_node;
    return true;
}

// 在特定的位置删除节点
bool LinkListDeleteAtPos(LinkList LL, int pos, ElemType &node_value)
{
    // 判断链表是否为空
    if (LinkListIsEmpty(LL) == true)
    {
        return false;
    }
    // 判断删除位置是否合理
    if (pos < 1)
    {
        return false;
    }
    // 找到被删除节点的前一个位置
    LinkNode* pre_node;
    LinkListSearchByPos(LL, pos - 1, pre_node);
    LinkNode* free_node = pre_node->next;
    pre_node->next = free_node->next;
    node_value = free_node->data;
    free(free_node);
    return true;
}

// 快速找到链表的中间节点，这个算法真的能给人带来很多感想，注意体会(考试常考)
bool QuickFindMidNode(LinkList LL, LinkNode* &target_node)
{
    // 判断链表是否为空
    if (LinkListIsEmpty(LL) == true)
    {
        return false;
    }
    // 用双指针法
    LinkNode* one_step_node = LL->next;
    LinkNode* two_steps_node = LL->next;
    while (two_steps_node != NULL)
    {
        two_steps_node = two_steps_node->next;
        if (two_steps_node == NULL)
        {
            break;
        }
        two_steps_node = two_steps_node->next;
        if (two_steps_node != NULL)
        {
            one_step_node = one_step_node->next;
        }
    }
    target_node = one_step_node;
    return true;
}

int main()
{
    LinkList LL;
    InitLinkList(LL);
//    LinkListInsertFromHead(LL);
    LinkListInsertFromTail(LL);
    TraverseLinkList(LL);
    LinkNode* target_node;
    LinkListSearchByPos(LL, 4, target_node);
    printf("node_value = %d\n", target_node->data);
    int pos = 0;
    LinkListSearchByValue(LL, 9, pos);
    printf("position = %d\n", pos);
    LinkListInsertedAtPos(LL, 1, 9);
    TraverseLinkList(LL);
    ElemType node_value;
    LinkListDeleteAtPos(LL, 1, node_value);
    printf("node value = %d\n", node_value);
    TraverseLinkList(LL);
    QuickFindMidNode(LL, target_node);
    printf("Mid node = %d\n", target_node->data);
    return 0;
}