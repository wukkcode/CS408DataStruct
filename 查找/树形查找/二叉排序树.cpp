#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int KeyType;
typedef struct BinaryTreeNode
{
    KeyType key_value;
    ElemType data;
    struct BinaryTreeNode* left_child;
    struct BinaryTreeNode* right_child;
} BinaryTreeNode, *BinaryTree;

// 二叉排序树插入（非递归）
bool InsertBinarySearchTree(BinaryTree &BST, KeyType key_value)
{
    // 新节点申请空间
    BinaryTreeNode* new_node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    if (new_node == NULL)
    {
        return false;
    }
    new_node->key_value = key_value;
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
        if (key_value == inserted_pos->key_value)
        {
            return false;
        }
        else if (key_value > inserted_pos->key_value)
        {
            inserted_pos = inserted_pos->right_child;
        }
        else
        {
            inserted_pos = inserted_pos->left_child;
        }
    }
    // 判断插入左孩子还是右孩子
    if (key_value > inserted_pos_parent->key_value)
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
bool InsertBinarySearchTreeUsingRecursion(BinaryTree &BST, KeyType key_value)
{
    if (BST == NULL)
    {
        BST = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        if (BST == NULL)
        {
            return false;
        }
        BST->key_value = key_value;
        BST->left_child = NULL;
        BST->right_child = NULL;
    }
    else if (key_value == BST->key_value)
    {
        return false;
    }
    else if (key_value < BST->key_value)
    {
        return InsertBinarySearchTreeUsingRecursion(BST->left_child, key_value);
    }
    else
    {
        return InsertBinarySearchTreeUsingRecursion(BST->right_child, key_value);
    }
    return true;
}

// 创建二叉排序树（调用插入操作）
bool CreateBinarySearchTree(BinaryTree &BST, KeyType *element_array, int length)
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
    printf("%-4d", BST->key_value);
    InOrderBinarySearchTree(BST->right_child);
    return true;
}

// 二叉排序树的查找（非递归版本）
BinaryTreeNode* SearchBinarySearchTree(BinaryTree BST, KeyType key_value)
{
    while (BST != NULL && temp_node->key_value != key_value)
    {
        if (key_value > BST->key_value)
        {
            BST = BST->right_child;
        }
        else
        {
            BST = BST->left_child;
        }
    }
    return BST;
}

// 二叉排序树的查找（递归版本）
BinaryTreeNode* SearchBinarySearchTreeUsingRecursion(BinaryTree BST, KeyType key_value)
{
    if (BST == NULL) // 是一棵空树或者直到查找NULL也没有找到，也就是查找失败
    {
        return NULL;
    }
    if (BST->key_value == key_value)
    {
        return BST;
    }
    else if (key_value > BST->key_value)
    {
        return SearchBinarySearchTreeUsingRecursion(BST->right_child, key_value);
    }
    else
    {
        return SearchBinarySearchTreeUsingRecursion(BST->left_child, key_value);
    }
}

int main()
{
    BinaryTree BST = NULL;

    KeyType element_array[7] = {54, 20, 66, 40, 28, 79, 58};
    CreateBinarySearchTree(BST, element_array, 7);
    InOrderBinarySearchTree(BST);
    printf("\n");
    BinaryTreeNode* target_node = NULL;
    target_node = SearchBinarySearchTreeUsingRecursion(BST, 20);
    printf("\n");
    return 0;
}