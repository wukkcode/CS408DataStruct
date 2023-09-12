#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct ThreadBinaryTreeNode
{
    ElemType data;
    struct ThreadBinaryTreeNode* left_child;
    struct ThreadBinaryTreeNode* right_child;
    int left_tag;
    int right_tag;
} ThreadBinaryTreeNode, *ThreadBinaryTree;

typedef struct LinkNode
{
    ThreadBinaryTreeNode* data;
    struct LinkNode* next;
} LinkNode, *LinkList;

typedef struct
{
    LinkNode* front;
    LinkNode* rear;
} LinkListQueue;

// 初始化链队
bool InitLinkListQueue(LinkListQueue &LLQ)
{
    LinkNode* head_node = (LinkNode *)malloc(sizeof(LinkNode));
    if (head_node == NULL)
    {
        return false;
    }
    head_node->next = NULL;
    LLQ.front = LLQ.rear = head_node;
    return true;
}

// 判断链队是否为空
bool LinkListQueueIsEmpty(LinkListQueue LLQ)
{
    if (LLQ.front == LLQ.rear)
    {
        return true;
    }
    return false;
}

// 进队列
bool EnLinkListQueue(LinkListQueue &LLQ, ThreadBinaryTreeNode* tbtn)
{
    LinkNode* new_node = (LinkNode *)malloc(sizeof(LinkNode));
    if (new_node == NULL)
    {
        return false;
    }
    new_node->data = tbtn;
    new_node->next = NULL;
    LLQ.rear->next = new_node;
    LLQ.rear = new_node;
    return true;
}

// 出队列
bool DeLinkListQueue(LinkListQueue &LLQ, ThreadBinaryTreeNode* &tbtn)
{
    // 判断队列是否为空
    if (LinkListQueueIsEmpty(LLQ) == true)
    {
        return false;
    }
    LinkNode* free_node = LLQ.front->next;
    tbtn = free_node->data;
    LLQ.front->next = free_node->next;
    if (free_node == LLQ.rear)
    {
        LLQ.rear = LLQ.front;
    }
    free(free_node);
    return true;
}

// 创建线索二叉树（中序遍历）
bool CreateThreadBinaryTreeByLevelOrder(ThreadBinaryTree &TBT, LinkListQueue &LLQ, ElemType tree_node_value)
{
    ThreadBinaryTreeNode* new_tree_node = (ThreadBinaryTreeNode *)malloc(sizeof(ThreadBinaryTreeNode));
    if (new_tree_node == NULL)
    {
        return false;
    }
    new_tree_node->data = tree_node_value;
    new_tree_node->left_child = NULL;
    new_tree_node->right_child = NULL;
    new_tree_node->left_tag = 0;
    new_tree_node->right_tag = 0;
    EnLinkListQueue(LLQ, new_tree_node);
    static LinkNode* current_node;
    if (TBT == NULL)
    {
        TBT = new_tree_node;
        current_node = LLQ.front->next;
    }
    else
    {
        if (current_node->data->left_child == NULL)
        {
            current_node->data->left_child = new_tree_node;
        }
        else if (current_node->data->right_child == NULL)
        {
            current_node->data->right_child = new_tree_node;
            current_node = current_node->next;
        }
    }
    return true;
}

// 层序遍历
bool LevelThreadBinaryTree(ThreadBinaryTree TBT)
{
    if (TBT == NULL)
    {
        return false;
    }
    LinkListQueue LLQ;
    InitLinkListQueue(LLQ);
    EnLinkListQueue(LLQ, TBT);
    ThreadBinaryTreeNode* current_tree_node;
    while (LinkListQueueIsEmpty(LLQ) != true)
    {
        DeLinkListQueue(LLQ, current_tree_node);
        printf("%-2c", current_tree_node->data);
        if (current_tree_node->left_child != NULL)
        {
            EnLinkListQueue(LLQ, current_tree_node->left_child);
        }
        if (current_tree_node->right_child != NULL)
        {
            EnLinkListQueue(LLQ, current_tree_node->right_child);
        }
    }
    return true;
}

// 通过中序遍历将二叉树线索化
bool InThreading(ThreadBinaryTreeNode* &current_node, ThreadBinaryTreeNode* &pre_tree_node)
{
    if (current_node == NULL)
    {
        return false;
    }
    InThreading(current_node->left_child, pre_tree_node);
    // 当前节点找前驱进行线索化
    if (current_node->left_child == NULL)
    {
        current_node->left_child = pre_tree_node;
        current_node->left_tag = 1;
    }
    // pre_tree_node找后继（当前节点）进行线索化
    if (pre_tree_node != NULL && pre_tree_node->right_child == NULL) 
    {
        pre_tree_node->right_child = current_node;
        pre_tree_node->right_tag = 1;
    }
    pre_tree_node = current_node;
    InThreading(current_node->right_child, pre_tree_node);
    return true;
}

bool CreateInOrderThreadBinaryTree(ThreadBinaryTree TBT)
{
    if (TBT == NULL)
    {
        return false;
    }
    ThreadBinaryTreeNode* pre_tree_node = NULL;
    InThreading(TBT, pre_tree_node);
    if (pre_tree_node->right_child == NULL)
    {
        pre_tree_node->right_tag = 1;
    }
    return true;
}

// 中序遍历线索二叉树(找后继)
// 1. 找中序遍历中第一个被遍历的节点
ThreadBinaryTreeNode* FindFirstTreeNode(ThreadBinaryTreeNode* current_tree_node)
{
    while (current_tree_node->left_tag == 0)
    {
        current_tree_node = current_tree_node->left_child;
    }
    return current_tree_node;
}
// 2. 找当前节点的下一个后继节点
ThreadBinaryTreeNode* FindNextTreeNode(ThreadBinaryTreeNode* current_tree_node)
{
    if (current_tree_node->right_tag == 0)
    {
        return FindFirstTreeNode(current_tree_node->right_child); 
    }
    else
    {
        return current_tree_node->right_child; // 返回线索
    }
}

bool InOrderThreadBinaryTree(ThreadBinaryTree TBT)
{
    if (TBT == NULL)
    {
        return false;
    }
    for (ThreadBinaryTreeNode* current_tree_node = FindFirstTreeNode(TBT); current_tree_node != NULL; current_tree_node = FindNextTreeNode(current_tree_node))
    {
        printf("%-2c", current_tree_node->data);
    }
    return true;
}

// （逆向）中序遍历线索二叉树（找前驱）

// 1. 找中序遍历中最后一个被遍历的节点
ThreadBinaryTreeNode* FindLastTreeNode(ThreadBinaryTreeNode* current_tree_node)
{
    while (current_tree_node->right_tag == 0)
    {
        current_tree_node = current_tree_node->right_child;
    }
    return current_tree_node;
}

// 2. 找当前节点的上一个节点
ThreadBinaryTreeNode* FindPreTreeNode(ThreadBinaryTreeNode* current_tree_node)
{
    if (current_tree_node->left_tag == 0)
    {
        return FindLastTreeNode(current_tree_node->left_child);
    }
    else
    {
        return current_tree_node->left_child;
    }
}

bool ReverseInOrderThreadTree(ThreadBinaryTree TBT)
{
    if (TBT == NULL)
    {
        return false;
    }
    for (ThreadBinaryTreeNode* current_tree_node = FindLastTreeNode(TBT); current_tree_node != NULL; current_tree_node = FindPreTreeNode(current_tree_node))
    {
        printf("%-2c", current_tree_node->data);
    }
}

// 通过先序遍历将二叉树线索化，可能会发生爱的魔力转圈圈问题（读者画个只有左子树的二叉树树进行理解）
bool PreThreading(ThreadBinaryTreeNode* &current_node, ThreadBinaryTreeNode* &pre_tree_node)
{
    if (current_node == NULL)
    {
        return false;
    }
    if (current_node->left_child == NULL)
    {
        current_node->left_child = pre_tree_node;
        current_node->left_tag = 1;
    }
    if (pre_tree_node != NULL && pre_tree_node->right_child == NULL)
    {
        pre_tree_node->right_child = current_node;
        pre_tree_node->right_tag = 1;
    }
    pre_tree_node = current_node;
    if (current_node->left_tag == 0)
    {
        PreThreading(current_node->left_child, pre_tree_node);
    }

    PreThreading(current_node->right_child, pre_tree_node);

}

bool CreatePreOrderThreadBinaryTree(ThreadBinaryTree TBT)
{
    if (TBT == NULL)
    {
        return false;
    }
    ThreadBinaryTreeNode* pre_tree_node = NULL;
    PreThreading(TBT, pre_tree_node);
    pre_tree_node->right_child = NULL;
    pre_tree_node->right_tag = 1;
    return true;
}

// 通过后序遍历将二叉树线索化
bool PostThreading(ThreadBinaryTreeNode* &current_node, ThreadBinaryTreeNode* &pre_tree_node)
{
    if (current_node == NULL)
    {
        return false;
    }
    PostThreading(current_node->left_child, pre_tree_node);
    PostThreading(current_node->right_child, pre_tree_node);
    if (current_node->left_child == NULL)
    {
        current_node->left_child = pre_tree_node;
        current_node->left_tag = 1;
    }
    if (pre_tree_node != NULL && pre_tree_node->right_child == NULL)
    {
        pre_tree_node->right_child = current_node;
        pre_tree_node->right_tag = 1;
    }
    pre_tree_node = current_node;
    return true;
}

bool CreatePostOrderThreadBinaryTree(ThreadBinaryTree TBT)
{
    if (TBT == NULL)
    {
        return false;
    }
    ThreadBinaryTreeNode* pre_tree_node = NULL;
    PostThreading(TBT, pre_tree_node);
    if (pre_tree_node->right_child == NULL)
    {
        pre_tree_node->right_tag = 1;
    }
    return true;
}

int main()
{
    LinkListQueue LLQ;
    InitLinkListQueue(LLQ);
    ThreadBinaryTree TBT = NULL;
    ElemType tree_node_value;
    scanf("%c", &tree_node_value);
    while (tree_node_value != '\n')
    {
        CreateThreadBinaryTreeByLevelOrder(TBT, LLQ, tree_node_value);
        scanf("%c", &tree_node_value);
    }
    printf("Level order is:");
    LevelThreadBinaryTree(TBT);
    printf("\n");
    printf("Start InOrder Threaded!!!\n");
    CreateInOrderThreadBinaryTree(TBT);
    printf("In order is:");
    InOrderThreadBinaryTree(TBT);
    printf("\n");
    printf("Reverse in order is:");
    ReverseInOrderThreadTree(TBT);
    printf("\n");
//    printf("Start PreOrder Threaded!!!\n");
//    ThreadedBinaryTreeByPreOrderFinalProcess(TBT);
//    printf("Start PostOrder Threaded!!!\n");
//    ThreadedBinaryTreeByPostOrderFinalProcess(TBT);
    return 0;
}