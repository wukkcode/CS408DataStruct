#include "auxiliary_queue.h"

// 通过层序遍历构建二叉树
bool CreateBinaryTreeByLevelOrder(BinaryTree &BT, ElemType tree_node_value, LinkListQueue &LLQ)
{
    BinaryTreeNode* new_tree_node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    if (new_tree_node == NULL)
    {
        return false;
    }
    new_tree_node->data = tree_node_value;
    new_tree_node->left_child = NULL;
    new_tree_node->right_child = NULL;
    EnLinkListQueue(LLQ, new_tree_node);
    static LinkNode* current_node;
    if (BT == NULL)
    {
        BT = new_tree_node;
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

// 先序遍历二叉树（深度优先遍历）
bool PreOrderBinaryTree(BinaryTree BT)
{
    if (BT == NULL)
    {
        return false;
    }
    printf("%-2c", BT->data);
    PreOrderBinaryTree(BT->left_child);
    PreOrderBinaryTree(BT->right_child);
    return true;
}

// 中序遍历二叉树
bool InOrderBinaryTree(BinaryTree BT)
{
    if (BT == NULL)
    {
        return false;
    }
    InOrderBinaryTree(BT->left_child);
    printf("%-2c", BT->data);
    InOrderBinaryTree(BT->right_child);
    return true;
}

// 后序遍历二叉树
bool PostOrderBinaryTree(BinaryTree BT)
{
    if (BT == NULL)
    {
        return false;
    }
    PostOrderBinaryTree(BT->left_child);
    PostOrderBinaryTree(BT->right_child);
    printf("%-2c", BT->data);
    return true;
}

// 层序遍历二叉树（广度优先遍历）
bool LevelOrderBinaryTree(BinaryTree BT)
{
    if (BT == NULL)
    {
        return false;
    }
    // 需要一个辅助队列
    LinkListQueue LLQ;
    InitLinkListQueue(LLQ);
    EnLinkListQueue(LLQ, BT);
    BinaryTreeNode* current_node;
    while (LinkListQueueIsEmpty(LLQ) != true)
    {
        DeLinkListQueue(LLQ, current_node);
        printf("%-2c", current_node->data);
        if (current_node->left_child != NULL)
        {
            EnLinkListQueue(LLQ, current_node->left_child);
        }
        if (current_node->right_child != NULL)
        {
            EnLinkListQueue(LLQ, current_node->right_child);
        }
    }
    return true;
}

int main()
{
    LinkListQueue LLQ;
    InitLinkListQueue(LLQ);
    BinaryTreeNode btn;
    BinaryTree BT = NULL;
    ElemType value;
    scanf("%c", &value);
    while (value != '\n')
    {
        CreateBinaryTreeByLevelOrder(BT, value, LLQ);
        scanf("%c", &value);
    }
    printf("Level order sequence is:");
    LevelOrderBinaryTree(BT);
    printf("\n");
    printf("Pre order sequence is:");
    PreOrderBinaryTree(BT);
    printf("\n");
    printf("In order sequence is:");
    InOrderBinaryTree(BT);
    printf("\n");
    printf("Post order sequence is:");
    PostOrderBinaryTree(BT);
    printf("\n");
    return 0;
}