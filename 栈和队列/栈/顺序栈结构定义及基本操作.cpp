#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef int ElemType;
//定义顺序栈的结构
typedef struct
{
    ElemType data[MaxSize];
    int top;
} SequenceStack;

// 初始化栈
void InitSequenceStack(SequenceStack &SS)
{
    SS.top = -1;
}

// 判断栈是否为空
bool SequenceStackIsEmpty(SequenceStack SS)
{
    if (SS.top == -1)
    {
        return true;
    }
    return false;
}

// 判断栈是否为满
bool SequenceStackIsFull(SequenceStack SS)
{
    if (SS.top == MaxSize-1)
    {
        return true;
    }
    return false;
}

// 进栈
bool PushSequenceStack(SequenceStack &SS, ElemType value)
{
    if (SequenceStackIsFull(SS) == true)
    {
        return false;
    }
    SS.data[++SS.top] = value;
    return true;
}

// 出栈
bool PopSequenceStack(SequenceStack &SS, ElemType &value)
{
    if (SequenceStackIsEmpty(SS) == true)
    {
        return false;
    }
    value = SS.data[SS.top--];
    return true;
}

// 获取栈顶元素
bool GetTopElement(SequenceStack SS, ElemType &value)
{
    if (SequenceStackIsEmpty(SS) == true)
    {
        return false;
    }
    value = SS.data[SS.top];
    return true;
}

int main()
{
    SequenceStack SS;
    InitSequenceStack(SS);
    for (int i = 0; i < 10; i++)
    {
        PushSequenceStack(SS, i+1);
    }
    ElemType value;
    GetTopElement(SS, value);
    printf("Top value = %d\n", value);
}