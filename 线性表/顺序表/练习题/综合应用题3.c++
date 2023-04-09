/*
3.对长度为n的顺序表L,编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算
法删除线性表中所有值为x的数据元素。
思考：这一题情理之中，意料之外，读者应该画图才能完全理解
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

// 方法一：用一个num变量记录记录当前有多少个特定的value值，然后将后面的元素向前移动num个位置
bool DeleteAllSpecificElements_fun1(StaticSequenceList &SSL, ElemType value)
{
    if (StaticSequenceListIsEmpty(SSL) == true)
    {
        return false;
    }
    int num = 0;
    for (int i = 0; i < SSL.length; i++)
    {
        if (SSL.data[i] == value)
        {
            num++;
        }
        else
        {
            SSL.data[i - num] = SSL.data[i];
        }
    }
    SSL.length -= num;
    return true;
}

// 方法二：用num记录顺序表中不等于value的元素个数，然后将不等于value移动到num（数组下标）位置
bool DeleteAllSpecificElements_fun2(StaticSequenceList &SSL, ElemType value)
{
    if (StaticSequenceListIsEmpty(SSL) == true)
    {
        return false;
    }
    int num = 0;
    for (int i = 0; i < SSL.length; i++)
    {
        if (SSL.data[i] != value)
        {
            SSL.data[num] = SSL.data[i];
            num++;
        }
    }
    SSL.length = num;
    return true;
}

int main()
{
    StaticSequenceList SSL;
    InitStaticSequenceList(SSL);
    SSL.length = 5;
    SSL.data[0] = 1;
    for (int i = 1; i<SSL.length; i++)
    {
        SSL.data[i] = i;
    }
    TraverseStaticSequenceList(SSL);
    DeleteAllSpecificElements_fun2(SSL, 1);
    TraverseStaticSequenceList(SSL);
    return 0;
}