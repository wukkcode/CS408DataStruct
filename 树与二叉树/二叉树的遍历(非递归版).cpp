#include "auxiliary_stack.h"
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

// 中序遍历（非递归版）
bool InOrderBinaryTree(BinaryTree BT)
{
    if (BT == NULL)
    {
        return false;
    }
    LinkStack LS;
    InitLinkStack(LS);
    BinaryTreeNode* current_tree_node = BT;
    while (current_tree_node != NULL || LinkStackIsEmpty(LS) != true)
    {
        if (current_tree_node != NULL)
        {
            PushLinkStack(LS, current_tree_node);
            current_tree_node = current_tree_node->left_child;
        }
        else
        {
            PopLinkStack(LS, current_tree_node);
            printf("%-2c", current_tree_node->data);
            current_tree_node = current_tree_node->right_child;
        }
    }
    return true;
}

// 先序遍历（非递归版）
bool PreOrderBinaryTree(BinaryTree BT)
{
    if (BT == NULL)
    {
        return false;
    }
    LinkStack LS;
    InitLinkStack(LS);
    BinaryTreeNode* current_tree_node = BT;
    while (current_tree_node != NULL || LinkStackIsEmpty(LS) != true)
    {
        if (current_tree_node != NULL)
        {
            printf("%-2c", current_tree_node->data);
            PushLinkStack(LS, current_tree_node);
            current_tree_node = current_tree_node->left_child;
        }
        else
        {
            PopLinkStack(LS, current_tree_node);
            current_tree_node = current_tree_node->right_child;
        }
    }
    return true;
}

// 后序遍历（非递归版）
// 参考：https://zhuanlan.zhihu.com/p/80578741?utm_id=0
bool PostOrderBinaryTree(BinaryTree BT)
{
    if (BT == NULL)
    {
        return false;
    }
    LinkStack LS;
    InitLinkStack(LS);
    BinaryTreeNode* current_tree_node = BT;
    BinaryTreeNode* pre_tree_node = NULL;
    while (current_tree_node != NULL || LinkStackIsEmpty(LS) != true)
    {
        while (current_tree_node != NULL)
        {
            PushLinkStack(LS, current_tree_node);
            current_tree_node = current_tree_node->left_child;
        }
        if (LinkStackIsEmpty(LS) != true)
        {
            PopLinkStack(LS, current_tree_node);
            if (current_tree_node->right_child == NULL || pre_tree_node == current_tree_node->right_child)
            {
                printf("%-2c", current_tree_node->data);
                pre_tree_node = current_tree_node;
                current_tree_node = NULL;
            }
            else
            {
                PushLinkStack(LS, current_tree_node);
                current_tree_node = current_tree_node->right_child;
            }
        }
    }
    return true;
}

// 层序遍历
bool LevelOrderBinaryTree(BinaryTree BT)
{
    if (BT == NULL)
    {
        return false;
    }
    LinkListQueue LLQ;
    InitLinkListQueue(LLQ);
    BinaryTreeNode* current_tree_node;
    EnLinkListQueue(LLQ, BT);
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
    InOrderBinaryTree(BT);
    printf("\n");
    PreOrderBinaryTree(BT);
    printf("\n");
    PostOrderBinaryTree(BT);
    printf("\n");
    LevelOrderBinaryTree(BT);
}