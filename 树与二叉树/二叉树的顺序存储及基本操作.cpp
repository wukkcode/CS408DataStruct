/*
下面的判断二叉树节点是否存左孩子、右孩子、父节点都是基于完全二叉树。而对于普通的二叉树的
顺序存储是这样的判断条件是无法适用的，而要采用某一个节点的status才能判断
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MaxSize 50

typedef int ElemType;
typedef struct
{
    ElemType data;
    bool empty_status;
} SBTNode,SequenceBinaryTree[MaxSize+1];

// 初始化顺序存储的二叉树
void InitSequenceBinaryTree(SequenceBinaryTree &SBT)
{
    for (int i = 1; i <= MaxSize; i++)
    {
        SBT[i].empty_status = true;
    }
}

// 找节点的左孩子
int FindLeftChildNode(SequenceBinaryTree SBT,int node_index, int node_number)
{
    // 判断完全二叉树是否有左孩子
    if (node_index * 2 > node_number || node_index < 1)
    {
        return -1;
    }
    return node_index * 2;
}

// 找节点的右孩子
int FindRightChildNode(SequenceBinaryTree SBT,int node_index, int node_number)
{
    // 判断完全二叉树是否有右孩子
    if (2 * node_index + 1 > node_number || node_index < 1)
    {
        return -1;
    }
    return node_index * 2 + 1;
}

// 找节点的父节点
bool FindFatherNode(SequenceBinaryTree SBT, int node_index, int node_number)
{
    // 判断节点node_index合不合理
    if (node_index <= 1 || node_index > node_number)
    {
        return -1;
    }
    return node_index / 2;
}

// 判断节点是否是叶子节点/分支节点
bool SBTNodeIsLeafNode(SequenceBinaryTree SBT, int node_index, int node_number)
{
    if (node_index > node_number / 2)
    {
        return true; // 是叶子节点
    }
    return false; // 不是叶子节点
}

// 先序遍历
bool PreOrderBinaryTree(SequenceBinaryTree SBT, int current_node_index, int node_number)
{
    if (current_node_index >= 1 && current_node_index <= node_number)
    {
        printf("%d ", SBT[current_node_index].data);
        PreOrderBinaryTree(SBT, FindLeftChildNode(SBT, current_node_index, node_number), node_number);
        PreOrderBinaryTree(SBT, FindRightChildNode(SBT, current_node_index, node_number), node_number);
        return true;
    }
    return false;
}

// 中序遍历
bool InOrderBinaryTree(SequenceBinaryTree SBT, int current_node_index, int node_number)
{
    if (current_node_index >= 1 && current_node_index <= node_number)
    {
        InOrderBinaryTree(SBT, FindLeftChildNode(SBT, current_node_index, node_number), node_number);
        printf("%d ", SBT[current_node_index].data);
        InOrderBinaryTree(SBT, FindRightChildNode(SBT, current_node_index, node_number), node_number);
        return true;
    }
    return false;
}

// 后序遍历
bool PostOrderBinaryTree(SequenceBinaryTree SBT, int current_node_index, int node_number)
{
    if (current_node_index >= 1 && current_node_index <= node_number)
    {
        PostOrderBinaryTree(SBT, FindLeftChildNode(SBT, current_node_index, node_number), node_number);
        PostOrderBinaryTree(SBT, FindRightChildNode(SBT, current_node_index, node_number), node_number);
        printf("%d ", SBT[current_node_index].data);
        return true;
    }
    return false;
}

int main()
{
    SequenceBinaryTree SBT;
    InitSequenceBinaryTree(SBT);
    for (int i = 1; i <= 12; i++)
    {
        SBT[i].data = i;
        SBT[i].empty_status = false;
    }
    PreOrderBinaryTree(SBT, 1, 12);
    printf("\n");
    InOrderBinaryTree(SBT, 1, 12);
    printf("\n");
    PostOrderBinaryTree(SBT, 1, 12);
    return 0;
}