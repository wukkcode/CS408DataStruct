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

// 查找操作，查找根节点
/*
查找操作，从下往上，查找效率跟树高相关，最坏时间复杂度为O(n)
如果想要提高查找效率，则可降低树高进行查找（合并优化）
*/
ParentNotationNode FindInDisjointSet(ParentNotationNode disjoint_set[], int node_index)
{
    int root_index = node_index;
    // 找到根节点
    while (disjoint_set[root_index].parent_node_index >= 0)
    {
        root_index = disjoint_set[node_index].parent_node_index;
    }
    return disjoint_set[root_index];
}

// 优化查找操作，降低查找路径（这个可牛逼了）
ParentNotationNode OptimizeFind(ParentNotationNode disjoint_set[], int node_index)
{
    int root_index = node_index;
    // 找到根节点
    while (disjoint_set[root_index].parent_node_index >= 0)
    {
        root_index = disjoint_set[node_index].parent_node_index;
    }
    // 路径上的节点挨个连接到根节点
    while (root_index != node_index)
    {
        int temp_index = disjoint_set[node_index].parent_node_index;
        disjoint_set[node_index].parent_node_index = root_index;
        node_index = temp_index;
    }
    return disjoint_set[root_index];
}   

// 合并操作，将两个子树进行合并
/*
其时间复杂度为O(1)
*/
bool UnionDisjointSet(ParentNotationNode disjoint_set[], int root1_index, int root2_index)
{
    if (disjoint_set[root1_index].parent_node_index == disjoint_set[root2_index].parent_node_index)
    {
        return false;
    }
    disjoint_set[root2_index].parent_node_index = root1_index;
    return true;
}

// 优化合并操作，小树合并到大树
/*
其树高增长速度变慢，查找时间复杂度为O(log_2(n))
*/
bool OptimizeUnion(ParentNotationNode disjoint_set[], int root1_index, int root2_index)
{
    if (disjoint_set[root1_index].parent_node_index <= disjoint_set[root2_index].parent_node_index)
    {
        disjoint_set[root2_index].parent_node_index = root1_index;
        disjoint_set[root1_index].parent_node_index += root2_index;
    }
    else
    {
        disjoint_set[root1_index].parent_node_index = root2_index;
        disjoint_set[root2_index].parent_node_index += root1_index;
    }
    return true;
}