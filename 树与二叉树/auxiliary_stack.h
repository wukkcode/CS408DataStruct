#include <stdio.h>
#include <stdlib.h>


typedef char ElemType;

typedef struct BinaryTreeNode
{
    ElemType data;
    struct BinaryTreeNode* left_child;
    struct BinaryTreeNode* right_child;
} BinaryTreeNode, *BinaryTree;

typedef struct LinkStackNode
{
    BinaryTreeNode* data;
    struct LinkStackNode* next;
} LinkStackNode, *LinkStack;

// 初始化链栈(无头节点)
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
bool PushLinkStack(LinkStack &LS, BinaryTreeNode* btn)
{
    LinkStackNode* pushed_node = (LinkStackNode *)malloc(sizeof(LinkStackNode));
    if (pushed_node == NULL)
    {
        return false;
    }
    pushed_node->data = btn;
    pushed_node->next = LS;
    LS = pushed_node;
    return true;
}

// 出栈
bool PopLinkStack(LinkStack &LS, BinaryTreeNode* &btn)
{
    if (LinkStackIsEmpty(LS) == true)
    {
        return false;
    }
    LinkStackNode* popped_node = LS;
    btn = popped_node->data;
    LS = popped_node->next;
    free(popped_node);
    return true;
}
