#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef int ElemType;
typedef struct
{
   ElemType data[MaxSize];
   int length; 
} StaticSequenceList;

int BinarySearch(StaticSequenceList SSL, int element_value)
{
    int low_index = 0;
    int high_index = SSL.length - 1;
    int mid_index;
    while (low_index <= high_index) // 注意判断条件是小于等于
    {
        mid_index = (low_index + high_index) / 2;
        if (SSL.data[mid_index] == element_value)
        {
            return mid_index;
        }
        else if (SSL.data[mid_index] < element_value)
        {
            low_index = mid_index + 1;
        }
        else
        {
            high_index = mid_index - 1;
        }
    }
    return -1;
}

int main()
{
    StaticSequenceList SSL;
    for (int i = 0; i < 10; i++)
    {
        SSL.data[i] = i + 1;
    }
    SSL.length = 10;
    int pos = BinarySearch(SSL, 10);
    if (pos != -1)
    {
        printf("Element's position index is %d", pos);
    }
    else 
    {
        printf("BinarySearch is Failed!");
    }
}
