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

// 判断顺序表是否为满
bool StaticSequenceListIsFull(StaticSequenceList SSL)
{
    if (SSL.length == MaxSize)
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

// 插入元素到第i个位置
bool InsertElementByPos(StaticSequenceList &SSL, int pos, ElemType value)
{
    // 判断顺序表是否已经满了
    if (StaticSequenceListIsFull(SSL) == true)
    {
        return false;
    }

    // 判断插入位置是否合理，共有length+1个位置可插入(1, length+1)
    if (pos < 1 || pos > SSL.length + 1)
    {
        return false;
    }

    // 向后移动第n-i+1个元素，不好理解的话，画个图（学数据结构必须要画图，不然太抽象了）
    int i;
    for (i = SSL.length; i >= pos; i--)
    {
        SSL.data[i] = SSL.data[i - 1];
    }
    SSL.data[i] = value;
    SSL.length++;
    return true;
}

// 删除第i个元素
bool DeleteElementByPos(StaticSequenceList &SSL, int pos, ElemType &value)
{
    // 判断顺序表是否为空
    if (StaticSequenceListIsEmpty(SSL)== true)
    {
        return false;
    }
    // 判断删除位置是否合理，一共有length个位置可以删除(1, length)
    if (pos < 1 || pos > SSL.length)
    {
        return false;
    }
    value = SSL.data[pos-1];
    for (int i = pos-1; i < SSL.length-1; i++)
    {
        SSL.data[i] = SSL.data[i+1];
    }
    SSL.length--;
    return true;
}

// 按值查找
bool SearchElementByValue(StaticSequenceList SSL, ElemType value, int &pos)
{
    // 判断顺序表是否为空
    if (StaticSequenceListIsEmpty(SSL) == true)
    {
        return false;
    }
    for (int i = 0; i<SSL.length; i++)
    {
        if (SSL.data[i] == value)
        {
            pos = i + 1;
            return true;
        }
    }
    return false;
}

// 按位置查找
bool SearchElementByPos(StaticSequenceList SSL, int pos, ElemType &value)
{
    // 判断顺序表是否为空
    if (StaticSequenceListIsEmpty(SSL) == true)
    {
        return false;
    }

    // 判断查找位置是否合理
    if (pos < 1 || pos > SSL.length)
    {
        return false;
    }

    value = SSL.data[pos - 1];
    return true;
}

ElemType GetMinValue(StaticSequenceList &SSL)
{
    if (SSL.length == 0)
    {
        return -9999;
    }
    ElemType min = SSL.data[0];
    int pos = 0;
    for (int i = 1; i < SSL.length; i++)
    {
        if (min < SSL.data[i])
        {
            min = SSL.data[i];
            int pos = i;
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
    InsertElementByPos(SSL, 2, 6);
    TraverseStaticSequenceList(SSL);
    ElemType value = 0;
    DeleteElementByPos(SSL, 2, value);
    printf("Deleted value = %d\n", value);
    TraverseStaticSequenceList(SSL);
    int pos = 0;
    SearchElementByValue(SSL, 2, pos);
    printf("pos = %d\n", pos);
    SearchElementByPos(SSL, 4, value);
    printf("Search result = %d\n", value);
    return 0;
}