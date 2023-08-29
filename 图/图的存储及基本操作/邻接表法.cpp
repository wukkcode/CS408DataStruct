/*
和树的孩子表示法类似，都是用一个数组来存储节点个数
无向图空间复杂度为O(|V| + 2|E|)，要存储两份边节点
有向图空间复杂度为O(|V| + |E|)
优点：1.能非常节省空间的存储稀疏图； 2.很容易找到邻边
缺点：1.判断顶点之间是否存在边；2.在邻接表中找入度
*/

#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 3

typedef char VertexType;

// 边节点的结构
typedef struct ArcNode
{
    int vertex_node_index; // 边所指向节点的下标（注意无向图）
    struct ArcNode* next_arc; // 指向下一条边
    // int weight; // 边的权值
} ArcNode;

// 顶点结构
typedef struct VertexNode
{
    VertexType data; // 节点信息
    ArcNode* first_arc; // 指向第一条边
} VertexNode, AdjacencyList[MaxVertexNum];

// 图的邻接表存储
typedef struct
{
    AdjacencyList vertex_nodes;
    int vertex_num;
    int arc_num;
} AdjacencyGraph;

int main()
{
    AdjacencyGraph AG;
    AG.vertex_num = 3;
    AG.arc_num = 6;
    for (int i = 0; i < AG.vertex_num; i++)
    {
        AG.vertex_nodes[i].data = 'a' + i;
    }
    ArcNode arc_node1, arc_node2, arc_node3, arc_node4, arc_node5, arc_node6;
    arc_node1.vertex_node_index = 0;
    arc_node2.vertex_node_index = 0;
    arc_node1.next = &arc_node2;
    arc_node2.next = NULL;
    AG.vertex_nodes[0].next = &arc_node1;
    arc_node3.vertex_node_index = 1;
    arc_node4.vertex_node_index = 1;
    arc_node3.next = &arc_node4;
    arc_node4.next = NULL;
    AG.vertex_nodes[1].next = &arc_node3;
    arc_node5.vertex_node_index = 2;
    arc_node6.vertex_node_index = 2;
    arc_node5.next = &arc_node6;
    arc_node6.next = NULL;
    AG.vertex_nodes[2].next = &arc_node5;
    return 0;
}