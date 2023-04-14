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
bool FindLeftChildNode(SequenceBinaryTree SBT,int node_index, int number, SBTNode &SBTN)
{
    // 判断完全二叉树是否有左孩子
    if (2 * node_index > number)
    {
        return false;
    }
    SBTN = SBT[node_index * 2];
    return true;
}

// 找节点的右孩子
bool FindRightChildNode(SequenceBinaryTree SBT,int node_index, int number, SBTNode &SBTN)
{
    // 判断完全二叉树是否有右孩子
    if (2 * node_index + 1 > number)
    {
        return false;
    }
    SBTN = SBT[node_index * 2 + 1];
    return true;
}

// 找节点的父节点
bool FindFatherNode(SequenceBinaryTree SBT, int node_index, int number, SBTNode &SBTN)
{
    // 判断节点node_index合不合理
    if (node_index == 1 || node_index > number)
    {
        return false;
    }
    SBTN = SBT[node_index / 2];
    return true;
}

// 判断节点是否是叶子节点/分支节点
bool SBTNodeIsLeafNode(SequenceBinaryTree SBT, int node_index, int number)
{
    if (node_index > number / 2)
    {
        return true; // 是叶子节点
    }
    return false; // 不是叶子节点
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

    return 0;
}
