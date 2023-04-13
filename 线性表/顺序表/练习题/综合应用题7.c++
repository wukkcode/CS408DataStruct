/*
7. 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
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

// 合并两个顺序表并返回
bool MergeTwoSequenceListS(StaticSequenceList SSL1, StaticSequenceList SSL2, StaticSequenceList &NewSSL)
{
    if (SSL1.length + SSL2.length > MaxSize)
    {
        return false;
    }
    int index1 = 0;
    int index2 = 0;
    int new_index = 0;
    while (index1 < SSL1.length && index2 < SSL2.length)
    {
        if (SSL1.data[index1] <= SSL2.data[index2])
        {
            NewSSL.data[new_index++] = SSL1.data[index1++];
        }
        else
        {
            NewSSL.data[new_index++] = SSL2.data[index2++];
        }
    }
    while (index1 < SSL1.length)
    {
        NewSSL.data[new_index++] = SSL1.data[index1++];
    }
    while (index2 < SSL2.length)
    {
        NewSSL.data[new_index++] = SSL2.data[index2++];
    }
    NewSSL.length = new_index;
    return true;
}

int main()
{
    StaticSequenceList SSL1;
    InitStaticSequenceList(SSL1);
    StaticSequenceList SSL2;
    InitStaticSequenceList(SSL2);
    SSL1.length = 5;
    SSL2.length = 5;
    for (int i = 0; i<SSL1.length; i++)
    {
        SSL1.data[i] = i+1;
        SSL2.data[i] = SSL1.data[i]+ 5;
    }
    TraverseStaticSequenceList(SSL1);
    TraverseStaticSequenceList(SSL2);
    StaticSequenceList NewSSL;
    InitStaticSequenceList(NewSSL);
    MergeTwoSequenceListS(SSL1, SSL2, NewSSL);
    TraverseStaticSequenceList(NewSSL);
    return 0;
}