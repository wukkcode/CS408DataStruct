/*
1. 从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。空出的位
置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。
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

// 删除最小的元素
ElemType DeleteMinValue(StaticSequenceList &SSL)
{
    if (SSL.length == 0)
    {
        return -9999;
    }
    ElemType min = SSL.data[0];
    int pos = 0;
    for (int i = 1; i < SSL.length; i++)
    {
        if (min > SSL.data[i])
        {
            min = SSL.data[i];
            pos = i;
        }
    }
    if (pos != SSL.length - 1)
    {
        SSL.data[pos] = SSL.data[SSL.length-1];
    }
    SSL.length--;
    return min;
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
    printf("min = %d\n",  DeleteMinValue(SSL));
    printf("min = %d\n",  DeleteMinValue(SSL));
    printf("min = %d\n",  DeleteMinValue(SSL));
    printf("min = %d\n",  DeleteMinValue(SSL));
    printf("min = %d\n",  DeleteMinValue(SSL));
    printf("min = %d\n",  DeleteMinValue(SSL));
}