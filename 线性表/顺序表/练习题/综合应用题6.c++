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
    int work_index; // 去重之后的元素应该放的位置
    int first_different_index;
    for (first_different_index = 0, work_index = 1; work_index < SSL.length; work_index++)
    {
        if (SSL.data[work_index] != SSL.data[first_different_index])
        {
            first_different_index++;
            SSL.data[first_different_index] = SSL.data[work_index];
        }
    }
    SSL.length = first_different_index + 1;
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