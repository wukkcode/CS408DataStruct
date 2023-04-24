/*
8. 已知在一维数组中依次存放两个线姓表(a1, a2,..., an)和(b1, b2,..., bn)。编写一
个函数，将数组中两个顺序表的位置互换，即将(b1, b2,..., bn)放在(a1, a2,..., an)的前面。
*/

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20

typedef int ElemType;

// 顺序表结构（静态分配）
typedef struct
{
    ElemType data[MaxSize];
    int length;
} StaticSequenceList;

// 初始化顺序表
void InitStaticSequenceList(StaticSequenceList &SSL)
{
    SSL.length = 0;
}

// 判断顺序表是否为空
bool StaticSequenceListIsEmpty(StaticSequenceList SSL)
{
    if (SSL.length == 0)
    {
        return true;
    }
    return false;
}

// 遍历顺序表
bool TraverseStaticSequenceList(StaticSequenceList SSL)
{
    if (StaticSequenceListIsEmpty(SSL) == true)
    {
        return false;
    }
    for (int i = 0; i < SSL.length; i++)
    {
        printf("%d", SSL.data[i]);
        printf(" ");
    }
    printf("\n");
    return true;
}

// 交换两个顺序表的位置
/*
算法思想：
1. 先将静态线性表中的所有元素逆置
2. 然后将各个每个线性表中的元素逆置
*/
bool ReverseStaticSequenceList(StaticSequenceList &SSL, int left_pos, int right_pos)
{
    if (StaticSequenceListIsEmpty(SSL) == true)
    {
        return false;
    }
    int mid_pos = (left_pos + right_pos) / 2;
    for (int i = left_pos - 1; i < mid_pos; i++)
    {
        ElemType temp_element = SSL.data[i];
        SSL.data[i] = SSL.data[right_pos - (i - left_pos+1) - 1];
        SSL.data[right_pos - (i - left_pos + 1) - 1] = temp_element;
    }
    return true;
}

int main()
{
    StaticSequenceList SSL;
    InitStaticSequenceList(SSL);
    SSL.length = 13;
    for (int i = 0; i<13; i++)
    {
        if (i < 6)
        {
           SSL.data[i] = i+1;
        }
        else
        {
            SSL.data[i] = 10 + i;
        }
    }
    TraverseStaticSequenceList(SSL);
    ReverseStaticSequenceList(SSL, 1, 13);
    TraverseStaticSequenceList(SSL);
    ReverseStaticSequenceList(SSL, 1, 7);
    TraverseStaticSequenceList(SSL);
    ReverseStaticSequenceList(SSL, 8, 13);
    TraverseStaticSequenceList(SSL);
    return 0;
}