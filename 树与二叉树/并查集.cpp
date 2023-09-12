/*
并查集就是一种集合，通常我们用森林的双亲表示作为并查集的存储结构
*/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

// 用双亲表示法很容易找到父节点
typedef char ElemType;
typedef struct 
{
    ElemType data;
    int parent_node_index;
} ParentNotationNode;

// 初始化并查集（一个节点一个集合）
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

int FindInDisjointSetRoot(ParentNotationNode disjoint_set[], int node_index)
{
    // 找到根节点
    int root_index = node_index;
    while (disjoint_set[root_index].parent_node_index >= 0)
    {
        root_index = disjoint_set[root_index].parent_node_index;
    }
    return root_index;
}

// 优化查找操作，降低查找路径（这个可牛逼了）
/*
时间复杂度可以到O(α(n))
*/

int OptimizeFind(ParentNotationNode disjoint_set[], int node_index)
{
    int root_index = node_index;
    // 找到根节点
    while (disjoint_set[root_index].parent_node_index >= 0)
    {
        root_index = disjoint_set[root_index].parent_node_index;
    }
    // 路径上的节点挨个指向根节点
    while (root_index != node_index)
    {
        int temp_index = disjoint_set[node_index].parent_node_index;
        disjoint_set[node_index].parent_node_index = root_index;
        node_index = temp_index;
    }
    return root_index;
}   

// 合并操作，将两个子树进行合并
/*
其时间复杂度为O(1)
*/

// 这里给定的参数是两个根节点的数组下标
bool UnionDisjointSet(ParentNotationNode disjoint_set[], int root1_index, int root2_index)
{
    // 两个元素同属于一个集合（树）/两个集合的根相同
    if (root1_index == root2_index)
    {
        return false;
    }
    disjoint_set[root2_index].parent_node_index = root1_index;
    return true;
}

// 任意给定两个元素的下标，然后将两个元素所在的集合进行合并
bool UnionDisjointSet(ParentNotationNode disjoint_set[], int node1_index, int node2_index)
{
    int root1_index = FindInDisjointSetRoot(disjoint_set, node1_index);
    int root2_index = FindInDisjointSetRoot(disjoint_set, node2_index);
    UnionDisjointSet(disjoint_set, root1_index, root2_index);
}

// 优化合并操作，小树合并到大树，让树高尽可能的低
/*
其树高增长速度变慢，查找Find()时间复杂度为O(log_2(n))
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