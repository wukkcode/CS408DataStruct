#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef int ElemType;
typedef struct
{
   ElemType data[MaxSize];
   int length; 
} StaticSequenceList;

// 折半查找的算法效率要比顺序查找的算法优秀的多，但前提是线性表（这里指的是顺序存储的线性表）是有序的，所以有得必有失..
// 读者着重思考一下，查找判定树的构造以及其性质，这才是考察的重点

int BinarySearch(StaticSequenceList SSL, int element_value)
{
    int low_index = 0;
    int high_index = SSL.length - 1;
    int mid_index;
    while (low_index <= high_index) // 注意判断条件是小于等于
    {
        // 注意这里是向下取整，构造查找判定树的时候需要注意一下：右子树节点-左子树节点=0,1
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
