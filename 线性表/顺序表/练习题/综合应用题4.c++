/*
4. 从有序顺序表中删除其值在给定值s与f之间(要求s<t)的所有元素，若s或，不合理
或顺序表为空，则显示出错信息并退出运行。
思考：这一段代码实现非常精简巧妙，值得揣摩思考
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

// 删除顺序表指定范围的元素
bool DeleteAllElementAtRange(StaticSequenceList &SSL, ElemType left_value, ElemType right_value)
{
    if (StaticSequenceListIsEmpty(SSL) == true)
    {
        return false;
    }
    int left_index, right_index;
    // 找到顺序表中第一个大于等于left_value的下标
    for (left_index = 0; left_index < SSL.length && SSL.data[left_index] < left_value; left_index++);
    // 顺序表中所有元素都小于left_value则返回false
    if (left_index >= SSL.length)
    {
        return false;
    }
    // 找到顺序表中第一个大于right_value的下标
    for (right_index = left_index; right_index < SSL.length && SSL.data[right_index] <= right_value; right_index++);
    // 移动删除
    for (; right_index < SSL.length; left_index++, right_index++)
    {
        SSL.data[left_index] = SSL.data[right_index];
    }
    SSL.length = left_index;
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
    DeleteAllElementAtRange(SSL, 1, 3);
    TraverseStaticSequenceList(SSL);
    return 0;
}