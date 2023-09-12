#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int ElemType;
typedef struct BinaryTreeNode
{
    KeyType key_value;
    ElemType data;
    struct BinaryTreeNode* left_child;
    struct BinaryTreeNode* right_child;
} BinaryTreeNode, *BinaryTree;

// 二叉排序树插入（非递归）
bool InsertBinarySearchTree(BinaryTree &BST, KeyType key_vale)
{
    // 新节点申请空间
    BinaryTreeNode* new_node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    if (new_node == NULL)
    {
        return false;
    }
    new_node->data = key_vale;
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
        if (key_vale == inserted_pos->data)
        {
            return false;
        }
        else if (key_vale > inserted_pos->data)
        {
            inserted_pos = inserted_pos->right_child;
        }
        else
        {
            inserted_pos = inserted_pos->left_child;
        }
    }
    // 判断插入左孩子还是右孩子
    if (key_vale > inserted_pos_parent->data)
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
bool InsertBinarySearchTreeUsingRecursion(BinaryTree &BST, KeyType key_vale)
{
    if (BST == NULL)
    {
        BST = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        if (BST == NULL)
        {
            return false;
        }
        BST->data = key_vale;
        BST->left_child = NULL;
        BST->right_child = NULL;
    }
    else if (key_vale == BST->data)
    {
        return false;
    }
    else if (key_vale < BST->data)
    {
        return InsertBinarySearchTreeUsingRecursion(BST->left_child, key_vale);
    }
    else
    {
        return InsertBinarySearchTreeUsingRecursion(BST->right_child, key_vale);
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
    printf("%-4d", BST->data);
    InOrderBinarySearchTree(BST->right_child);
    return true;
}

// 二叉排序树的删除
bool DeleteBinarySearchTree(BinaryTree &BST, KeyType key_vale)
{
    if (BST == NULL)
    {
        return false;
    }
    // 要删除的节点在右子树
    if (key_vale > BST->key_value)
    {
        DeleteBinarySearchTree(BST->right_child, key_vale);
    }
    // 要删除的节点在左子树
    else if (key_vale < BST->key_value)
    {
        DeleteBinarySearchTree(BST->left_child, key_vale);
    }
    // 找到要删除的节点了
    else
    {
        // 删除之后要进行补充（右子树为空，则要将其左孩子移上来）
        if (BST->right_child == NULL)
        {
            BinaryTreeNode* temp_node = BST;
            BST = BST->left_child;
            free(temp_node);
        }
        else if (BST->left_child == NULL)
        {
            BinaryTreeNode* temp_node = BST;
            BST = BST->right_child;
            free(temp_node);
        }
        else // 左右子树均不为空，则要选择左子树的最右边节点；或者右子树的最左边节点
        {
            // 这里我们选择左子树的最右边节点
            BinaryTreeNode* temp_node = BST->left_child;
            while (temp_node->right_child != NULL)
            {
                temp_node = temp_node->right_child;
            }
            BST->data = temp_node->data;
            DeleteBinarySearchTree(BST->left_child, temp_node->key_value);
        }
    }
    return true;
}

int main()
{
    BinaryTree BST = NULL;

    KeyType element_array[7] = {54, 20, 66, 40, 28, 79, 58};
    CreateBinarySearchTree(BST, element_array, 7);
    InOrderBinarySearchTree(BST);
    printf("\n");
    DeleteBinarySearchTree(BST, 28);
    InOrderBinarySearchTree(BST);
    printf("\n");
    DeleteBinarySearchTree(BST, 54);
    InOrderBinarySearchTree(BST);
    printf("\n");
    return 0;
}