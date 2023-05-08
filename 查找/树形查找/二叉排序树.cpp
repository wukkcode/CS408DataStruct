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

    // 插入的是非根节点，要先找到合适的插入位置(从根节点开始遍历)
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
    return true;
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
    return true;
}

// 二叉排序树的查找（非递归版本）
BinaryTreeNode* SearchBinarySearchTree(BinaryTree BST, ElemType element_value)
{
    BinaryTreeNode* temp_node = BST;
    while (temp_node != NULL && temp_node->data != element_value)
    {
        if (element_value > temp_node->data)
        {
            temp_node = temp_node->right_child;
        }
        else
        {
            temp_node = temp_node->left_child;
        }
    }
    // 查找失败
    if (temp_node == NULL)
    {
        return NULL;
    }
    return temp_node;
}

// 二叉排序树的查找（递归版本）
BinaryTreeNode* SearchBinarySearchTreeUsingRecursion(BinaryTree BST, ElemType element_value)
{
    if (BST == NULL)
    {
        return NULL;
    }
    if (BST->data == element_value)
    {
        return BST;
    }
    if (element_value > BST->data)
    {
        return SearchBinarySearchTreeUsingRecursion(BST->right_child, element_value);
    }
    else
    {
        return SearchBinarySearchTreeUsingRecursion(BST->left_child, element_value);
    }
}

int main()
{
    BinaryTree BST = NULL;

    ElemType element_array[7] = {54, 20, 66, 40, 28, 79, 58};
    CreateBinarySearchTree(BST, element_array, 7);
    InOrderBinarySearchTree(BST);
    printf("\n");
    BinaryTreeNode* target_node = NULL;
    target_node = SearchBinarySearchTreeUsingRecursion(BST, 20);
    printf("\n");
    return 0;
}