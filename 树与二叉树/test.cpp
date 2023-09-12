

typedef int KeyType;
typedef struct RedBlackTreeNode
{
    KeyType key_value;
    struct RedBlackTreeNode* parent_node;
    struct RedBlackTreeNode* left_child;
    struct RedBlackTreeNode* right_child;
    int node_color;
} RedBlackTreeNode, *RedBlackTree;
