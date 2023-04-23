/*
并查集就是一种集合，通常我们用森林的双亲表示作为并查集的存储结构
*/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef char ElemType;
typedef struct 
{
    ElemType data;
    int parent_node_index;
} ParentNotationNode;

// 初始化并查集
void InitDisjointSet(ParentNotationNode disjoint_set[])
{
    for (int i = 0; i < MaxSize; i++)
    {
        disjoint_set[i].parent_node_index = -1;
    }
}

// 查找操作
