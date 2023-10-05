

#include <stdio.h>
#include <stdlib.h>
#define SingleKeyNumber 100 // 单个关键字的范围

typedef int ElemType;
typedef struct LinkListNode
{
    ElemType data;
    struct LinkListNode *next;
} LinkListNode;

typedef struct
{
   LinkListNode* front;
   LinkListNode* rear;
} LinkQueue;

int main()
{
    LinkQueue* AuxiliaryArray[SingleKeyNumber];
    return 0;
}

for (int i = 0; i < SingleKeyNumber-1; i++)
{
    AuxiliaryArray[i].rear = AuxiliaryArray[i+1].front; // 将每一个基数的辅助队列首尾相接
    AuxiliaryArray[i] = NULL;

}
AuxiliaryArray[SingleKeyNumber-1] = NULL; // 收集完成之后，最后一个基数的辅助队列置为空
