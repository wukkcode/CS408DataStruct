#include "auxiliary_queue.h"

BinaryTreeNode* pre_tool_node = NULL;
BinaryTreeNode* final_pre_node = NULL;
ElemType tree_node_value;

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


void FindPreNode(BinaryTree BT)
{
    if (BT->data != tree_node_value)
    {
        pre_tool_node = BT;
    }
    else
    {
        final_pre_node = pre_tool_node;
        return;
    }
}

// 先序遍历二叉树（深度优先遍历）
bool PreOrderBinaryTree(BinaryTree BT)
{
    if (BT == NULL)
    {
        return false;
    }
    printf("%-2c", BT->data);
    FindPreNode(BT);
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
    FindPreNode(BT);
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
    FindPreNode(BT);
    return true;
}

int main()
{
    LinkListQueue LLQ;
    InitLinkListQueue(LLQ);
    BinaryTree BT = NULL;
    ElemType value;
    tree_node_value = 'e';
    scanf("%c", &value);
    while (value != '\n')
    {
        CreateBinaryTreeByLevelOrder(BT, value, LLQ);
        scanf("%c", &value);
    }
    printf("Pre order sequence is:");
    PreOrderBinaryTree(BT);
    printf("\n");
    printf("The pre node of 'e' is '%c' node in pre sequence!\n", final_pre_node->data);
    pre_tool_node = NULL;
    printf("In order sequence is:");
    InOrderBinaryTree(BT);
    printf("\n");
    printf("The pre node of 'e' is '%c' node in mid sequence!\n", final_pre_node->data);
    pre_tool_node = NULL;
    printf("Post order sequence is:");
    PostOrderBinaryTree(BT);
    printf("\n");
    printf("The pre node of 'e' is '%c' node in post sequence!\n", final_pre_node->data);
}