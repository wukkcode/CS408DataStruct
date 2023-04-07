#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef int ElemType;
//定义共享栈的结构
typedef struct
{
    ElemType data[MaxSize];
    int top1;
    int top2;
} SharedSequenceStack;

// 初始化共享栈
void InitSharedSequenceStack(SharedSequenceStack &SSS)
{
    SSS.top1 = -1;
    SSS.top2 = MaxSize;
}

// 判断共享栈是否为空
bool SharedSequenceStackIsEmpty(SharedSequenceStack SSS, int stack_number)
{
    if (stack_number == 1 && SSS.top1 == -1)
    {
        return true;
    }
    if (stack_number == 2 && SSS.top2 == MaxSize)
    {
        return true;
    }
    return false;
}

// 判断共享栈是否为满
bool SharedSequenceStackIsFull(SharedSequenceStack SSS)
{
    if (SSS.top2 - SSS.top1 == 1)
    {
        return true;
    }
    return false;
}
