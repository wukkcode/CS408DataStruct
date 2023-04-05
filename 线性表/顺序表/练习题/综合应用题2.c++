/*
2. 设计一个高效算法，将顺序表Z的所有元素逆置，要求算法的空间复杂度为0(1)。
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
        printf("%-2d", SSL.data[i]);
    }
    printf("\n");
    return true;
}

// 逆置顺序表的元素
bool InverseSequenceList(StaticSequenceList &SSL)
{
    if (StaticSequenceListIsEmpty(SSL) == true)
    {
        return false;
    }
    ElemType temp_element;
    for (int i = 0; i < SSL.length / 2; i++)
    {
        temp_element = SSL.data[i];
        SSL.data[i] = SSL.data[SSL.length - i - 1];
        SSL.data[SSL.length - i - 1] = temp_element;
    }
    return true;
}

int main()
{
    StaticSequenceList SSL;
    InitStaticSequenceList(SSL);
    SSL.length = 5;
    for (int i = 0; i<SSL.length; i++)
    {
        SSL.data[i] = i+1;
    }
    TraverseStaticSequenceList(SSL);
    InverseSequenceList(SSL);
    TraverseStaticSequenceList(SSL);
}