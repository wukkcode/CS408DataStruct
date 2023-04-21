#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef char ElemType;

// 双亲表示法（纯顺序存储）
/*
优点：查找父节点非常容易，所以非常适合“并查集”这种需要经常查找父节点的结构
缺点：查找孩子节点需要从头开始遍历（找特定的下标）
森林也可用于双亲表示法存储
*/
typedef struct
{
    ElemType data;
    int parent_index;
} ParentNotionNode;

typedef struct
{
    ParentNotionNode nodes[MaxSize];
    int number; // 节点数量
} ParentNotationTree;

// 孩子表示法（链式存储+顺序存储）
/*
优点：查找孩子节点非常容易，所以非常适合“服务流程树”这种需要经常查找孩子节点的结构
缺点：查找孩子节点需要从头开始遍历（找特定的下标）
森林也可用于孩子表示法存储
*/
typedef struct NextNode
{
    int child_index;
    struct NextNode* next; // 某节点的孩子节点连接成一个链 
} NextNode;

typedef struct 
{
    ElemType data;
    NextNode* first_child;
}ChildNotationNode;

typedef struct
{
    ChildNotationNode nodes[MaxSize];
    int number; // 节点的数量
    int root_index; // 根的位置（数组下标）
};

// 孩子兄弟表示法（纯链式存储）
/*
优点：类似于二叉树的链式存储，所以可以很方便的实现树转换为二叉树
森林也可用于孩子兄弟表示法存储
*/
typedef struct ChildrBrotherNotaionNode
{
    ElemType data;
    struct ChildBrotherNotationNode* first_child;
    struct ChildBrotherNotationNode* next_brother;
}ChildBrotherNotationNode, *ChildBrotherNotationTree;
