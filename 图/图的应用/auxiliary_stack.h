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
bool PushLinkStack(LinkStack &LS, int &vertex_index);

// 出栈
bool PopLinkStack(LinkStack &LS, int vertex_index);
