#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MaxSize 50

typedef int ElemType;
typedef struct
{
    ElemType data;
    bool empty_status;
} SequenceBinaryTree[MaxSize+1];

// 初始化顺序存储的二叉树
void InitSequenceBinaryTree(SequenceBinaryTree &SBT)
{
    for (int i = 1; i <= MaxSize; i++)
    {
        SBT[i].empty_status = true;
    }
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
