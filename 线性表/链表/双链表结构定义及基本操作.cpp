#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// 双链表结构定义
typedef struct DoubleLinkNode
{
    ElemType data;
    DoubleLinkNode* next;
    DoubleLinkNode* prior;
} DoubleLinkNode, *DoubleLinkList;

// 初始化双链表
bool InitDoubleLinkList(DoubleLinkList &DLL)
{
    DLL = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode));
    if (DLL == NULL)
    {
        return false;
    }
    DLL->next == NULL;
    DLL->prior = NULL; // 单链表的头节点永远指向NULL
    return false;
}

// 判断双链表是否为空（同单链表）
bool DoubleLinkListIsEmpty(DoubleLinkList DLL)
{
    if (DLL->next == NULL)
    {
        return true;
    }
    return false;
}

/*
双链表节点结构相比单链表节点来说，只不过多了一个指向前面一个节点的指针，其他并没有什么操作
基本操作也就是比单链表基本操作多了一个修改和判断prior指针的操作
所以后序基本操作代码笔者只给出其一些核心代码，读者完整代码可自行设计（修改单链表的代码）
*/

// 双链表的遍历
bool TraverseDoubleLinkList(DoubleLinkList DLL)
{
    if (DoubleLinkListIsEmpty(DLL) == true)
    {
        return false;
    }
    DoubleLinkNode* current_node = DLL->next;
    while(current_node != NULL)
    {
        printf("%-2d", current_node->data);
        current_node = current_node->next;
    }
    return true;
}

// 双链表的查找
bool DoubleLinkListSearchByPos(DoubleLinkList DLL, int pos, DoubleLinkNode* &target_node)
{
    return true;
}

// 双链表的插入
bool DoubleLinkListInsertAtPos(DoubleLinkList DLL, int pos, ElemType node_value)
{
    // 找到要插入位置的前一个节点或者后一个节点（以前一个节点为例）
    DoubleLinkNode* pre_node;
    DoubleLinkListSearchByPos(DLL, pos-1, pre_node);
    DoubleLinkNode* inserted_node = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode));;
    if (inserted_node == NULL)
    {
        return false;
    }
    inserted_node->data = node_value;
    inserted_node->next = pre_node->next;
    if (pre_node->next != NULL) // 判断pre_node是不是尾部节点
    {
        pre_node->next->prior = inserted_node;
    }
    inserted_node->prior = pre_node;
    pre_node->next = inserted_node;
    return true;
}

// 双链表的删除
bool DoubleLinkListDeleteAtPos(DoubleLinkList DLL, int pos, ElemType *node_value)
{
    // 判断双链表是否为空
    if (DoubleLinkListIsEmpty(DLL) == true)
    {
        return false;
    }
    // 找到要删除位置的前一个节点或者后一个节点（以前一个节点为例）
    DoubleLinkNode* pre_node;
    DoubleLinkListSearchByPos(DLL, pos-1, pre_node);
    DoubleLinkNode* deleted_node = pre_node->next;
    if (deleted_node == NULL)
    {
        return false;
    }
    pre_node->next = deleted_node->next;
    if (deleted_node->next != NULL)
    {
        deleted_node->next->prior = pre_node;
    }
    free(deleted_node);
    return true;
}