/*
6. 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
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

// 删除有序顺序表中重复的元素
bool DeleteAllRepeatedElements(StaticSequenceList &SSL)
{
    if (StaticSequenceListIsEmpty(SSL) == true)
    {
        return false;
    }
    int index_work;
    int first_different;
    for (first_different = 0, index_work = 1; index_work < SSL.length; index_work++)
    {
        if (SSL.data[index_work] != SSL.data[first_different])
        {
            SSL.data[++first_different] = SSL.data[index_work];
        }
    }
    SSL.length = first_different + 1;
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
    DeleteAllElementAtRange_fun2(SSL, 2, 3);
    TraverseStaticSequenceList(SSL);
    return 0;
}