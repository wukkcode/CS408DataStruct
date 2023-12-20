// // #define MaxSize 100
// // #define MinINT -99999
// // typedef struct BinaryTreeNode
// // {
// // 	int data;
// // 	int weight;
// // 	BinaryTreeNode *left_node;
// // 	BinaryTreeNode *right_node;
// // } BinaryTreeNode, *BinaryTree;

// // typedef struct LinkNode
// // {
// //     BinaryTreeNode* data;
// //     struct LinkNode* next;
// // } LinkNode, *LinkList;

// // typedef struct
// // {
// //     LinkNode* front;
// //     LinkNode* rear;
// // } LinkListQueue;

// // bool InitLinkListQueue(LinkListQueue &LLQ);
// // bool LinkListQueueIsEmpty(LinkListQueue LLQ);
// // bool EnLinkListQueue(LinkListQueue &LLQ, BinaryTreeNode* btn);
// // bool DeLinkListQueue(LinkListQueue &LLQ, BinaryTreeNode* &btn);


// // // 方法1：参数传递

// // int height = 0;
// // int CalculateHeightOfBinaryTree(BinaryTree BT, int level)
// // {
// // 	if (BT == NULL)
// // 	{
// // 		return 0;
// // 	}
// // 	if (level > height)
// // 	{
// // 		height = level;
// // 	}
// // 	CalculateHeightOfBinaryTree(BT->left_node, level + 1);
// // 	CalculateHeightOfBinaryTree(BT->right_node, level + 1);
// // }

// // // 方法2：函数返回值
// // // 使用后序遍历计算二叉树中的高度

// // int CalculateHeightOfBinaryTree(BinaryTree BT)
// // {
// // 	if (BT == NULL)
// // 	{
// // 		return 0;
// // 	}
// // 	int left_height = CalculateHeightOfBinaryTree(BT->left_node);
// // 	int right_height = CalculateHeightOfBinaryTree(BT->right_node);
// // 	return left_height >= right_height ? left_height+1 : right_height+1;
// // }



// // // 计算二叉树的宽度
// // bool CalculateLevelWidthOfBinaryTree(BinaryTree BT, int level)
// // {
// // 	if (BT == NULL)
// // 	{
// // 		return false;
// // 	}
// // 	level_width[level]++;
// // 	CalculateHeightOfBinaryTree(BT->left_node, level+1);
// // 	CalculateHeightOfBinaryTree(BT->right_node, level+1);
// // 	return true;
// // }	

// // int CalculateWidthOfBinaryTree(BinaryTree BT)
// // {
// // 	int level_width[MaxSize];
// // 	for (int i = 0; i < MaxSize; i++)
// // 	{
// // 		level_width[i] = 0;
// // 	}
// // 	CalculateLevelWidthOfBinaryTree(BT, 0);
// // 	int height = level_width[0];
// // 	for (int i = 0; i < MaxSize; i++)
// // 	{
// // 		if (height < level_width[i])
// // 		{
// // 			height = level_width[i];
// // 		}
// // 	}
// // 	return height;
// // }

// // // 求WPL

// // int wpl = 0;
// // bool CalculateWPLOfBinaryTree(BinaryTree BT, int level)
// // {
// // 	if (BT == NULL)
// // 	{
// // 		return false;
// // 	}
// // 	if (BT->left_node == NULL && BT->right_node == NULL)
// // 	{
// // 		wpl += BT->weight * level;
// // 	}
// // 	CalculateHeightOfBinaryTree(BT->left_node, level+1);
// // 	CalculateHeightOfBinaryTree(BT->right_node, level+1);
// // 	return true;
// // }

// 判断二叉树是否是一个二叉排序树

bool IsBST = true;
int temp = MinINT;
bool JudgeBST(BinaryTree BT)
{
	if (BT == NULL)
	{
		return false;
	}
	JudgeBST(BT->left_node);
	if (BT->data >= temp)
	{
		temp = BT->data;
	}
	else
	{
		IsBST = false;
	}
	JudgeBST(BT->right_node);
	return true;
}

// // // 判断二叉树是否平衡
// // bool IsBalance = true;
// // int JudgeAVL(BinaryTree BT)
// // {
// // 	if (BT == NULL)
// // 	{
// // 		return 0;
// // 	}
// // 	int left_height = JudgeAVL(BT->left_node);
// // 	int right_height = JudgeAVL(BT->right_node);
// // 	if (left_height - right_height > 1 || left_height - right_height < -1)
// // 	{
// // 		IsBalance = false;
// // 	}
// // 	return left_height >= right_height ? left_height + 1 : right_height + 1;
// // }

// 判断是否是完全二叉树

bool flag = false; // 首次出现叶子节点或者右孩子为空的节点
bool IsComplete = true;
void JudgeCBT(BinaryTreeNode *node)
{
	// 出现叶子节点
	if (node->left_node == NULL && node->right_node == NULL)
	{
		flag = true;
	}
	// 出现有右孩子无左孩子的节点
	if (node->left_node == NULL && node->right_node != NULL)
	{
		IsComplete = false;
	}
	// 出现有左孩子无右孩子的节点
	if (node->left_node != NULL && node->right_node == NULL)
	{
		if (flag = true)
		{
			IsComplete = false;
		}
		flag = true;
	}
	// 出现双孩子节点
	if (node->left_node != NULL && node->right_node != NULL)
	{
		if (flag == true)
		{
			IsComplete = false;
		}
	}
}

// // // 层序遍历
// // bool LevelOrder(BinaryTree BT)
// // {
// // 	if (BT == NULL)
// // 	{
// // 		return false;
// // 	}
// // 	LinkListQueue LLQ;
// // 	BinaryTreeNode *current_node;
// // 	InitLinkListQueue(LLQ);
// // 	EnLinkListQueue(LLQ, BT);
// // 	while (LinkListQueueIsEmpty(LLQ) != true)
// // 	{
// // 		DeLinkListQueue(LLQ, current_node);
// // 		JudgeBST(current_node);
// // 		if (current_node -> left_node != NULL)
// // 		{
// // 			EnLinkListQueue(LLQ, current_node->left_node);
// // 		}
// // 		if (current_node -> right_node != NULL)
// // 		{
// // 			EnLinkListQueue(LLQ, current_node->right_node);
// // 		}
// // 	}
// // 	return true;
// // }

// // typedef struct LinkNode
// // {
// // 	int data;
// // 	struct LinkNode *next;
// // } LinkNode, *LinkList;

// // // 链表原地逆置
// // LinkList ReverseLinkList(LinkList LL)
// // {
// // 	LinkNode *p, *r;
// // 	p = LL->next;
// // 	LL->next = NULL;
// // 	while (p != NULL)
// // 	{
// // 		r = p->next;
// // 		p->next = LL->next;
// // 		LL->next = p;
// // 		p = r;
// // 	}
// // 	return LL;
// // }

// // // 链表找中间节点
// // LinkNode* FindMidNode(LinkList LL)
// // {
// // 	LinkNode *step1, *step2;
// // 	step1 = step2 = LL;
// // 	while (step2->next != NULL)
// // 	{
// // 		step1 = step1->next;
// // 		step2 = step2->next;
// // 		if (step2->next != NULL)
// // 		{
// // 			step2 = step2->next;
// // 		}
// // 	}
// // 	return step1;
// // }


// // void ChangeLinkList(LinkList LL)
// // {
// // 	// 找到中间节点
// // 	LinkNode *mid_node = FindMidNode(LL);
// // 	// 后半段链表原地逆置
// // 	ReverseLinkList(mid_node);
// // 	LinkNode *flag_node1 = LL->next;
// // 	LinkNode *flag_node2 = mid_node->next;
// // 	LinkNode *flag_node3;
// // 	mid_node->next = NULL;
// // 	while (flag_node2 != NULL)
// // 	{
// // 		flag_node3 = flag_node2->next;
// // 		flag_node2->next = flag_node1->next;
// // 		flag_node1->next = flag_node2;
// // 		flag_node1 = flag_node2->next;
// // 		flag_node2 = flag_node3;
// // 	}
// // }



// // void ChangeLinkList(LinkList LL)
// // {
// // 	// 找中间节点
// // 	LinkNode *mid, *last;
// // 	mid = last = LL;
// // 	while(last->next != NULL)
// // 	{
// // 		mid = mid->next;
// // 		last = last->next;
// // 		if (last->next != NULL)
// // 		{
// // 			last = last->next;
// // 		}
// // 	}
// // 	// 后半段链表原地逆置
// // 	LinkNode *temp1 = mid->next;
// // 	LinkNode *temp2;
// // 	mid->next = NULL;
// // 	while(temp1 != NULL)
// // 	{
// // 		temp2 = temp1->next;
// // 		temp1->next = mid->next;
// // 		mid->next = temp1;
// // 		temp1 = temp2;
// // 	}
// // 	// 完成插入过程
// // 	LinkNode *flag1, *flag2, *flag3;
// // 	flag1 = LL->next;
// // 	flag2 = mid->next;
// // 	mid->next = NULL;
// // 	while(flag2 != NULL)
// // 	{
// // 		flag3 = flag2->next;
// // 		flag2->next = flag1->next;
// // 		flag1->next = flag2;
// // 		flag1 = flag2->next;
// // 		flag2 = flag3;
// // 	}
// // }



// // int FindMinNumber(int A[], int n)
// // {
// // 	int Flag[n];
// // 	int i;
// // 	for(i = 0; i < n; i++)
// // 	{
// // 		Flag[i] = 0;
// // 	}
// // 	for(i = 0; i < n; i++)
// // 	{
// // 		if(A[i] > 0 && A[i] <= n)
// // 		{
// // 			Flag[A[i] - 1] = 1;
// // 		}
// // 	}
// // 	for(i = 0; i < n; i++)
// // 	{
// // 		if (Flag[i] == 0)
// // 		{
// // 			break;
// // 		}
// // 	}
// // 	return i + 1
// // }

// // #define INT_MAX 0x7fffffff
// // typedef struct
// // {
// // 	int index1;
// // 	int index2;
// // 	int index3;
// // } IndexRecord[MaxSize];

// // // 计算绝对值
// // int CalculateAbs(int value)
// // {
// // 	if (value < 0)
// // 	{
// // 		return 0-value;
// // 	}
// // 	return value;
// // }

// // int CalCulateMinDistance(int A[], int m, int B[], int n, int C[], int p)
// // {
// // 	int min_distance = INT_MAX;
// // 	int distance;
// // 	for(int i = 0; i < m; i++)
// // 	{
// // 		for(int j = 0; j < n; j++)
// // 		{
// // 			for (int k = 0; k < p; k++)
// // 			{
// // 				distance = CalAbs(B[j]-A[i])+CalAbs(C[k]-B[j])+CalAbs(C[k]-A[i]);
// // 				if (distance < min_distance)
// // 				{
// // 					min_distance = distance;
// // 				}
// // 			}
// // 		}
// // 	}
// // 	return distance;
// // }

// // typedef struct
// // {
// // 	char a; // 1Byte
// // 	int b; // 4Byte
// // } MyStruct;


// #include <stdio.h>
// #include <stdlib.h>

// typedef struct
// {
// 	char a;
// 	int b;
// } MyStruct;

// typedef struct LinkNode
// {
// 	int data;
// 	struct LinkNode *next;
// } LinkNode, *LinkList;

// // 计算链表的长度
// int CalculateTheLengthOfLinkList(LinkList LL)
// {
// 	int length = 0;
// 	LinkNode *flag_node = LL->next;
// 	while (flag_node != NULL)
// 	{
// 		length++;
// 		flag_node = flag_node->next;
// 	}
// 	return length;
// }

// // 找到链表的中间节点个节点
// LinkNode *FindKNode(LinkList LL, int k)
// {
// 	int length = CalculateTheLengthOfLinkList(LL);
// 	LinkNode *flag_node = LL->next;
// 	int count = 0;
// 	while (flag_node != NULL)
// 	{
// 		count++;
// 		if (count == length / 2)
// 		{
// 			break;
// 		}
// 	}
// 	return flag_node;
// }

// // 删除特定节点
// void DeleteSpecificNode(LinkList LL, int x)
// {
// 	LinkNode *pre_node = LL;
// 	LinkNode *current_node = LL->next;
// 	while (current_node != NULL)
// 	{
// 		if (current_node->data == x)
// 		{
// 			LinkNode *temp_node = current_node;
// 			current_node = current_node->next;
// 			pre_node->next = current_node;
// 			free(temp_node);
// 		}
// 		else
// 		{
// 			pre_node = current_node;
// 			current_node = current_node->next;
// 		}
// 	}
// }

// // 插入且保持单链表有序
// void InsertNode(LinkList LL, int x)
// {
// 	LinkNode *pre_node = LL;
// 	LinkNode *current_node = LL->next;
// 	LinkNode *new_node = (LinkNode *)malloc(sizeof(LinkNode));
// 	new_node->data = x;
// 	new_node->next = NULL;
// 	while (current_node->data <= x || current_node != NULL)
// 	{
// 		pre_node = current_node;
// 		current_node = current_node->next;
// 	}
// 	new_node->next = current_node;
// 	pre_node->next = new_node;
// }

// // 删除重复的数（绝对值相同；2015考题）
// void Delete(LinkList LL, int n)
// {
// 	int count[n+1];
// 	for (int i = 0; i < n+1; i++)
// 	{
// 		count[i] = 0;
// 	}
// 	LinkNode *pre_node = LL;
// 	LinkNode *current_node = pre_node->next;
// 	while (current_node != NULL)
// 	{
// 		int abs = current_node->data >=0 ? current_node->data : -(current_node->data);
// 		count[abs]++;
// 		if (count[abs] > 1)
// 		{
// 			LinNode *temp_node = current_node;
// 			current_node = current_node->next;
// 			pre_node->next = current_node;
// 			free(temp_node);
// 		}
// 		pre_node = current_node;
// 		current_node = current_node->next;
// 	}
// }

// // 原地逆置（头插法）
// void LinkListReverse(LinkList LL)
// {
// 	LinkNode *head_node = (LinKNode *)malloc(sizeof(LinkNode));
// 	head_node->next == NULL;
// 	while (LL->next != NULL)
// 	{
// 		LinkNode *temp_node = LL->next;
// 		LL->next = LL->next->next;
// 		temp_node->next = head->next;
// 		head->next = temp_node;
// 	}
// 	LL->next = head_node->next;
// 	free(head_node);
// }

// // 拆分单链表
// LinkList LL1 = NULL;
// LinkList LL2 = NULL;

// void SplitLinkList(LinList LL)
// {
// 	// LL1采用头插法
// 	LL1 = (LinkNode *)malloc(sizeof(LinkNode));
// 	LL1->next = NULL;
// 	LinkNode *tail_node = LL1;
// 	// LL2采用尾插法
// 	LL2 = (LinkNode *)malloc(sizeof(LinkNode));
// 	LL2->next = NULL;
// 	int count = 1;
// 	while (LL->next != NULL)
// 	{
// 		LinNode *temp_node = LL->next;
// 		if (count % 2 == 1)
// 		{
// 			tail_node->next = temp_node;
// 			temp_node->next = NULL;
// 			tail_node = tail_node->next;
// 		}
// 		else
// 		{
// 			temp_node->next = LL2->next;
// 			LL2->next = temp_node;
// 		}
// 		count++;
// 	}
// }

// // 头插法和尾插法的综合应用（2019）
// void InsertApplication(LinkList LL)
// {
// 	// 统计链表长度
// 	int length = 0;
// 	LinkNode *flag_node = LL->next;
// 	while(flag_node != NULL)
// 	{
// 		length++;
// 		flag_node = flag_node->next;
// 	}
// 	// 找到中间节点
// 	LinkNode *middle_node = LL->next;
// 	int count = 1;
// 	while (middle_node -> next != NULL)
// 	{
// 		if (count == length / 2)
// 		{
// 			break;
// 		}
// 		count++;
// 	}
// 	// 后半段链表原地逆置
// 	LinkNode *head_node = (LinkNode *)malloc(sizeof(LinkNode));
// 	head_node = NULL;
// 	while (middle_node->next != NULL)
// 	{
// 		LinkNode *temp_node = middle_node->next;
// 		middle_node->next = middle_node->next->next;
// 		temp_node->next = head_node->next;
// 		head_node->next = temp_node;
// 	}
// 	middle_node->next = head_node->next;
// 	free(head_node);
// 	// 两个链表交替插入
// 	flag_node = LL->next;
// 	LinkNode middle_next_node;
// 	while (flag_node != NULL)
// 	{
// 		middle_next_node = middle_node->next
// 		middle_node->next = flag_node->next;
// 		flag_node->next = middle_node;
// 		flag_node = middle_node->next;
// 		middle_node = middle_next_node;
// 	}
// }

// #define MAXV 1000

// // 边节点
// typedef struct EdgeNode
// {
// 	int weight;
// 	int index;
// 	struct EdgeNode *next_edge;
// }EdgeNode;
// // 顶点节点
// typedef struct VertexNode
// {
// 	char data;
// 	EdgeNode *first_edge;
// } VertexNode, *VertexList[MAXV];
// // 邻接表
// typedef struct
// {
// 	VertexList list;
// 	int edge_num;
// 	int vertex_num;
// } Graph;

// int CoutKNode(Graph G)
// {
// 	int count = 0;
// 	int indegree[G.vertex_num];
// 	int outdegree[G.vertex_num];
// 	for (int i = 0; i < G.vertex_num; i++)
// 	{
// 		indegree[i] = 0;
// 		outdegree[i] = 0;
// 	}
// 	for (int i = 0; i < G.vertex_num; i++)
// 	{
// 		for (EdgeNode *temp_edge = G.list[i]->first_edge; temp_edge; temp_edge=temp_edge->next_edge)
// 		{
// 			outdegree[i]++;
// 			indegree[temp_edge->index]++;
// 		}
// 	}
// 	for (int i = 0; i < G.vertex_num; i++)
// 	{
// 		if (out_degree[i] > in_degree[i])
// 		{
// 			count++;
// 		}
// 	}
// 	return count;
// }



// // Link节点
// typedef struct LinkNode
// {
// 	unsigned ID;
// 	unsigned IP;
// 	int metric;
// 	struct LinkNode *next_link;
// } LinkNode;
// // Net节点
// typedef struct
// {
// 	unsigned IPPrefix;
// 	unsigned Mask;
// 	int metric;
// 	LinkNode *next;
// } NetNode;
// // 路由器节点
// typedef struct RouterNode
// {
// 	unsigned RouterID;
// 	NetNode *next_net;
// } NetGraph[4];


// int fun()
// {
// 	while (IsEmpty(Q) == false)
// 	{
// 		DeQueue(Q, v);
// 		for (w = FirstNeignbour(G, v); w >= 0; w = NextNeighbour(G, v, w))
// 		{
// 			if (visited[w] == false)
// 			{
// 				dis[w] = d[v] + 1;
// 				path[w] = v;
// 				visited[w] = true;
// 				Enqueue(Q, w);
// 			}
// 		}
// 	}
// }

// 二叉树结构
typedef struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
} BinaryTreeNode, *BinaryTree;

// 计算二叉树的高度
// 方法1：使用参数传递来实现

int height = 0;
bool CalHeightOfTree(BinaryTree BT, int level)
{
	if (BT == NULL)
	{
		return false;
	}
	if (level > height)
	{
		height = level;
	}
	CalHeightOfTree(BT->left, level + 1);
	CalHeightOfTree(BT->right, level + 1);
	return true;
}

// 方法2：返回值实现（后序遍历）
int CalHeightOfTree(BinaryTree BT)
{
	if (BT == NULL)
	{
		return 0;
	}
	int left_height = CalHeightOfTree(BT->left);
	int right_height = CalHeightOfTree(BT->right);
	if (left_height > right_height)
	{
		return left_height + 1;
	}
	else
	{
		return right_height + 1;
	}
}

// 计算二叉树的宽度
#define MAXNUMBER 1000
int level_width[MAXNUMBER];
bool CalWidthOfTree(BinaryTree BT, int level)
{
	if (BT == NULL)
	{
		return false;
	}
	level_width[level]++;
	CalWidthOfTree(BT->left, level + 1);
	CalWidthOfTree(BT->right, level + 1);
	return true;
}

// 判断二叉树是否平衡
bool IsBalance = true;
int JudgeAVL(BinaryTree BT)
{
	if (BT == NULL)
	{
		return 0;
	}
	int left_height = JudgeAVL(BT->left);
	int right_height = JudgeAVL(BT->right);
	if (left_height - right_height < -1 || left_height - right_height > 1)
	{
		IsBalance = false;
	}
	return left_height > right_height ? left_height + 1 : right_height + 1;
}