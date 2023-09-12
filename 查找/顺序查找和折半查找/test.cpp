#include <stdio.h>
#define MaxSize 50

typedef char* InfoType;
typedef int KeyType;
// 数据元素的定义
typedef struct
{
    KeyType primary_key;
    InfoType other_info;
} ElemType;

// 顺序表的定义
typedef struct
{
    ElemType data[MaxSize];
    int length;

} StaticSequenceList;


// 查找（不带哨兵）
int SearchInSequenceList(StaticSequenceList SSL, KeyType target_key)
{
    for (int i = 1; i <= SSL.length; i++)
    {
        if(SSL.data[i].primary_key = target_key)
        {   
            return i;
        }
    }
    return 0;
}

// 查找（带哨兵）
int SearchInSequenceListWithFlag(StaticSequenceList SSL, KeyType target_key)
{
    int index = SSL.length;
    SSL.data[0].primary_key = target_key;
    while (SSL.data[index].primary_key != target_key)
    {
        index--;
    }
    return index;
}