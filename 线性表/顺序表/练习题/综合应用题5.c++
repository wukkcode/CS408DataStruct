/*
5.从顺序表中删除其值在给定值s与/之间(包含s和"要求5<r)的所有元素，若s或
t不合理或顺序表为空，则显示出错信息并退出运行。
注意：与第四题不同的是这里的顺序表不要求有序，则可以用第三道题的解法来做
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

// 方法一：用一个num变量计数在这个范围内的元素的个数，然后将剩余的元素依次向前移动num个位置
bool DeleteAllElementAtRange_fun1(StaticSequenceList &SSL, ElemType left_value, ElemType right_value)
{
    if (StaticSequenceListIsEmpty(SSL) == true)
    {
        return false;
    }
    int num = 0;
    for (int i = 0; i < SSL.length; i++)
    {
        if (left_value <= SSL.data[i] && SSL.data[i] <= right_value)
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

bool DeleteAllElementAtRange_fun2(StaticSequenceList &SSL, ElemType left_value, ElemType right_value)
{
    if (StaticSequenceListIsEmpty(SSL) == true)
    {
        return false;
    }
    int count = 0;
    for (int i = 0; i < SSL.length; i++)
    {
        if (left_value > SSL.data[i] || SSL.data[i] > right_value)
        {
            SSL.data[count] = SSL.data[i];
            count++;
        }
    }
    SSL.length = count;
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