#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct
{
    ElemType *data;
    int length;
}DynamicSequenceList;

bool InitDynamicSequenceList(DynamicSequenceList &DSL, int length)
{
    DSL.length = length + 1;
    DSL.data = (ElemType *)malloc(DSL.length * sizeof(ElemType));
    if (DSL.data == NULL)
    {
        return false;
    }
    for (int i = 1; i < DSL.length; i++)
    {
        DSL.data[i] = i;
    }
    return true;
}

// 顺序查找
int SearchSequenceList(DynamicSequenceList DSL, int element_value)
{
    DSL.data[0] = element_value; // 存储哨兵，循环查找的时候不需要判断越界
    int pos_index;
    for (pos_index = DSL.length-1; DSL.data[pos_index] != element_value; pos_index--);
    return pos_index;
}

// 顺序查找（顺序表有序），后序比较可省略
int SearchSequenceListUsingSortedList(DynamicSequenceList SDSL, int element_value)
{
    SDSL.data[0] = element_value; // 存储哨兵，循环查找的时候不需要判断越界
    int pos_index;
    for (pos_index = SDSL.length-1; SDSL.data[pos_index] != element_value; pos_index--)
    {
        if (element_value > SDSL.data[pos_index])
        {
            return 0;
        }
    }
    return pos_index;
}

int main()
{
    DynamicSequenceList DSL;
    InitDynamicSequenceList(DSL, 10);
    int pos = SearchSequenceList(DSL, 0);
    if (pos != 0)
    {
        printf("SequenceSearch is Successful!");
    }
    else
    {
        printf("SequenceSearch is Failed");
    }
    return 0;
}