#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct BinaryTreeNode
{
    ElemType data;
    struct BinaryTreeNode* left_child;
    struct BinaryTreeNode* right_child;
} BinaryTreeNode, *BinaryTree;

// 二叉排序树插入（非递归）
bool InsertBinarySearchTree(BinaryTree &BST, ElemType element_value)
{
    // 新节点申请空间
    BinaryTreeNode* new_node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    if (new_node == NULL)
    {
        return false;
    }
    new_node->data = element_value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    // 插入的是根节点
    if (BST == NULL)
    {
        BST = new_node;
        return true;
    }

    // 插入的是非根节点，要先找到合适的插入位置
    BinaryTreeNode* inserted_pos = BST;
    BinaryTreeNode* inserted_pos_parent;
    while (inserted_pos != NULL)
    {
        inserted_pos_parent = inserted_pos;
        if (element_value == inserted_pos->data)
        {
            return false;
        }
        else if (element_value > inserted_pos->data)
        {
            inserted_pos = inserted_pos->right_child;
        }
        else
        {
            inserted_pos = inserted_pos->left_child;
        }
    }
    // 判断插入左孩子还是右孩子
    if (element_value > inserted_pos_parent->data)
    {
        inserted_pos_parent->right_child = new_node;
    }
    else
    {
        inserted_pos_parent->left_child = new_node;
    }
    return true;
}

// 二叉排序树的插入（递归）
bool InsertBinarySearchTreeUsingRecursion(BinaryTree &BST, ElemType element_value)
{
    if (BST == NULL)
    {
        BST = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        if (BST == NULL)
        {
            return false;
        }
        BST->data = element_value;
        BST->left_child = NULL;
        BST->right_child = NULL;
    }
    else if (element_value == BST->data)
    {
        return false;
    }
    else if (element_value < BST->data)
    {
        return InsertBinarySearchTreeUsingRecursion(BST->left_child, element_value);
    }
    else
    {
        return InsertBinarySearchTreeUsingRecursion(BST->right_child, element_value);
    }
}

// 创建二叉排序树（调用插入操作）
bool CreateBinarySearchTree(BinaryTree &BST, ElemType *element_array, int length)
{
    for (int i = 0; i < length; i++)
    {
        InsertBinarySearchTree(BST, element_array[i]);
    }
    return true;
}

// 中序遍历（有序）
bool InOrderBinarySearchTree(BinaryTree BST)
{
    if (BST == NULL)
    {
        return false;
    }
    InOrderBinarySearchTree(BST->left_child);
    printf("%-4d", BST->data);
    InOrderBinarySearchTree(BST->right_child);
}

// 二叉排序树的查找
bool SearchBinarySearchTree(BinaryTree BST, ElemType element_value, BinaryTreeNode* &target_node ,BinaryTreeNode* &parent_node)
{
    target_node = BST;
    while (target_node != NULL && target_node->data != element_value)
    {
        parent_node = target_node;
        if (element_value > target_node->data)
        {
            target_node = target_node->right_child;
        }
        else
        {
            target_node = target_node->left_child;
        }
    }
    if (target_node == NULL)
    {
        return false;
    }
    return true;
}

int main()
{
    BinaryTree BST = NULL;

    ElemType element_array[7] = {54, 20, 66, 40, 28, 79, 58};
    CreateBinarySearchTree(BST, element_array, 7);
    InOrderBinarySearchTree(BST);
    printf("\n");
    BinaryTreeNode* target_node = NULL;
    BinaryTreeNode* parent_node = NULL;
    SearchBinarySearchTree(BST, 54, target_node, parent_node);
    if (target_node == NULL)
    {
        printf("Search is failed!");
    }
    else
    {
        printf("Search is successful!");
    }
    return 0;
}