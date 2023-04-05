#include <stdio.h>
#include <stdlib.h>
#define InitSize 100

typedef int ElemType;

// 顺序表结构（动态分配）
typedef struct 
{
    ElemType *data;
    int length;
    int MaxSize;
} DynamicSequenceList;

// 初始化顺序表
bool InitDynamicSequenceList(DynamicSequenceList &DSL)
{
    DSL.data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
    if (DSL.data == NULL)
    {
        return false;
    }
    DSL.length = 0;
    DSL.MaxSize = InitSize;
    return true;
}

// 当前顺序表的容量不够用了，申请更大的空间
bool IncreaseDynamicSequenceListSpace(DynamicSequenceList &DSL, int extra_length)
{
    DynamicSequenceList temp_dsl = DSL;
    DSL.data = (ElemType *)malloc(sizeof(ElemType) * (DSL.MaxSize + extra_length));
    if (DSL.data == NULL)
    {
        return false;
    }
    DSL.MaxSize = temp_dsl.MaxSize + extra_length;
    DSL.length = temp_dsl.length;
    // 元素转移到新空间
    for (int i = 0; i < DSL.length; i++)
    {
        DSL.data[i] = temp_dsl.data[i];
    }
    return false;
}

/*
其他基本操作和静态分配的顺序表一样，这里不再给出
唯一需要注意的是MaxSize不再作为常量给出，而是作为结构体的一个成员，访问的时候注意一下即可
*/

int main()
{
    DynamicSequenceList DSL;
    InitDynamicSequenceList(DSL);
    printf("maxsize = %d\n", DSL.MaxSize);
    IncreaseDynamicSequenceListSpace(DSL, 50);
    printf("maxsize = %d\n", DSL.MaxSize);
    return 0;
}
