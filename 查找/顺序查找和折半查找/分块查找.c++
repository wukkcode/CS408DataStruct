#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100

typedef int ElemType;
typedef struct
{
    ElemType max_value;
    int low_index;
    int high_index;
} IndexTable;

// 查找索引表（折半查找）
int SearchIndexTable(IndexTable* IT, int length, int target_value)
{
    int low_index = 0;
    int high_index = length - 1;
    int mid_index;
    while (low_index <= high_index)
    {
        mid_index = (low_index + high_index) / 2;
        if (target_value == IT[mid_index].max_value)
        {
            return mid_index;
        }
        else if (target_value < IT[mid_index].max_value)
        {
            high_index = mid_index - 1;
        }
        else
        {
            low_index = mid_index + 1;
        }
    }
    // 查找失败（查找的元素值远大于最大的索引节点的最大值）
    if (low_index >= length)
    {
        return -1;
    }
    return low_index;
}

int main()
{
    ElemType SequenceList[Maxsize] = {7, 10, 13, 19, 16, 20, 27, 22, 30, 40, 36, 43, 50, 48};
    IndexTable IT[5] = {10, 0, 1, 20, 2, 5, 30, 6, 8, 40, 9, 10, 50, 11, 13};
    return 0;
}