/*
首先这里明确一点，栈的定义是是操作受限的线性表，即只能在一端进出，而单链表的首部操作可以很好的满足栈的要求
*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkStackNode
{
    ElemType data;
    struct LinkStackNode* next;
} LinkStackNode, *LinkStack;

// 初始化链栈
void InitLinkStack(LinkStack &LS)
{
   LS = NULL;
}

// 判断链栈是否为空
bool LinkStackIsEmpty(LinkStack LS)
{
    if (LS == NULL)
    {
        return true;
    }
    return false;
}

// 进栈
bool PushLinkStack(LinkStack &LS, ElemType node_value)
{
    LinkStackNode* pushed_node = (LinkStackNode *)malloc(sizeof(LinkStackNode));
    if (pushed_node == NULL)
    {
        return false;
    }
    pushed_node->data = node_value;
    pushed_node->next = NULL;
    pushed_node->next = LS;
    LS = pushed_node;
    return true;
}

// 出栈
bool PopLinkStack(LinkStack &LS, ElemType &node_value)
{
    if (LinkStackIsEmpty(LS) == true)
    {
        return false;
    }
    LinkStackNode* popped_node = (LinkStackNode *)malloc(sizeof(LinkStackNode));
    if (popped_node == NULL)
    {
        return false;
    }
    popped_node = LS;
    LS = popped_node->next;
    node_value = popped_node->data;
    free(popped_node);
    return true;
}

// 获取栈顶元素
bool GetTopElement(LinkStack LS, ElemType &node_value)
{
    if (LinkStackIsEmpty(LS) == true)
    {
        return false;
    }
    node_value = LS->data;
    return true;
}

int main()
{
    LinkStack LS;
    InitLinkStack(LS);
    for (int i = 0; i < 10; i++)
    {
        PushLinkStack(LS, i+1);
    }
    ElemType value;
    PopLinkStack(LS, value);
    printf("Popped value = %d\n", value);
    PopLinkStack(LS, value);
    printf("Popped value = %d\n", value);
    PopLinkStack(LS, value);
    printf("Popped value = %d\n", value);
    GetTopElement(LS, value);
    printf("Current top value = %d\n", value);
    return 0;
}