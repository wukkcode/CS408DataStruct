#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 50

typedef char ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int top;
} SequenceStack;

// 初始化顺序栈
void InitSequenceStack(SequenceStack &SS)
{
    SS.top = -1;
}

// 判断顺序栈是否为空
bool SequenceStackIsEmpty(SequenceStack SS)
{
    if (SS.top == -1)
    {
        return true;
    }
    return false;
}

// 判断顺序栈是否为满
bool SequenceStackIsFull(SequenceStack SS)
{
    if (SS.top == MaxSize-1)
    {
        return true;
    }
    return false;
}

// 进栈
bool PushSequenceStack(SequenceStack &SS, ElemType pushed_value)
{
    if (SequenceStackIsFull(SS) == true)
    {
        return false;
    }
    SS.data[++SS.top] = pushed_value;
    return true;
}

// 出栈
bool PopSequenceStack(SequenceStack &SS, ElemType &popped_value)
{
    if (SequenceStackIsEmpty(SS) == true)
    {
        return false;
    }
    popped_value = SS.data[SS.top--];
    return true;
}

// 括号匹配
bool BracketsMatching(char brackets_str[], int length)
{
    SequenceStack SS;
    InitSequenceStack(SS);
    for (int i = 0; i < length; i++)
    {
        if (brackets_str[i] == '(' || brackets_str[i] == '[' || brackets_str[i] == '{')
        {
            PushSequenceStack(SS, brackets_str[i]);
        }
        else
        {
            if (SequenceStackIsEmpty(SS) == true)
            {
                return false;
            }
            char top_bracket;
            PopSequenceStack(SS, top_bracket);
            if (brackets_str[i] == '(' && top_bracket != ')')
            {
                return false;
            }
            if (brackets_str[i] == '[' && top_bracket != ']')
            {
                return false;
            }
            if (brackets_str[i] == '{' && top_bracket != '}')
            {
                return false;
            }
        }
    }
    if (SequenceStackIsEmpty(SS) == true)
    {
        return true;
    }
    return false;
}

int main()
{
    char brackets_str[] = "((){}[])";
    
    if (BracketsMatching(brackets_str, strlen(brackets_str)))
    {
        printf("Brackets matching is successful!\n");
    }
    else
    {
        printf("Brackets matching is failed!\n");
    }
    return 0;
}