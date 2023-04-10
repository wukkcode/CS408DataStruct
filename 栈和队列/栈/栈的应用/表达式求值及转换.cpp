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
bool PushSequenceStack(SequenceStack &SS, ElemType pushed_element)
{
    if (SequenceStackIsFull(SS) == true)
    {
        return false;
    }
    SS.data[++SS.top] = pushed_element;
    return true;
}

// 出栈
bool PopSequenceStack(SequenceStack &SS, ElemType &popped_element)
{
    if (SequenceStackIsEmpty(SS) == true)
    {
        return false;
    }
    popped_element = SS.data[SS.top--];
    return true;
}

// 获取栈顶元素
bool GetTopElement(SequenceStack SS, ElemType &top_element)
{
    if (SequenceStackIsEmpty(SS) == true)
    {
        return false;
    }
    top_element = SS.data[SS.top];
    return true;
}

// 中缀表达式转后拽表达式
bool TransformInfixToSuffix(char *infix_str, char *suffix_str)
{
    if (strlen(infix_str) == 0)
    {
        return false;
    }
    SequenceStack OPSS;
    InitSequenceStack(OPSS);
    int j = 0;
    for (int i = 0; i < strlen(infix_str); i++)
    {
        if ('0' <= infix_str[i] && infix_str[i] <= '9')
        {
            suffix_str[j] = infix_str[i];
            j++;
        }
        else if (infix_str[i] == '(')
        {
            PushSequenceStack(OPSS, infix_str[i]);
        }
        else if (infix_str[i] == ')')
        {
            ElemType top_element;
            GetTopElement(OPSS, top_element);
            while (top_element != '(')
            {
                char popped_element;
                PopSequenceStack(OPSS, popped_element);
                suffix_str[j] = popped_element;
                j++;
                GetTopElement(OPSS, top_element);

            }
            PopSequenceStack(OPSS, top_element);
        }
        else if (infix_str[i] == '-' || infix_str[i] == '+')
        {
            if (SequenceStackIsEmpty(OPSS) == true)
            {
                PushSequenceStack(OPSS, infix_str[i]);
                continue;
            }
            ElemType top_element;
            GetTopElement(OPSS, top_element);
            while (SequenceStackIsEmpty(OPSS) != true && (top_element == '+' || top_element == '-' || top_element == '/' || top_element == '*'))
            {
                ElemType popped_element;
                PopSequenceStack(OPSS, popped_element);
                suffix_str[j] = popped_element;
                j++;
                GetTopElement(OPSS, top_element);
            }
            PushSequenceStack(OPSS, infix_str[i]);
        }
        else if (infix_str[i] == '/' || infix_str[i] == '*')
        {
            if (SequenceStackIsEmpty(OPSS) == true)
            {
                PushSequenceStack(OPSS, infix_str[i]);
                continue;
            }
            ElemType top_element;
            GetTopElement(OPSS, top_element);
            while ((SequenceStackIsEmpty(OPSS) != true) &&(top_element == '/' || top_element == '*'))
            {
                ElemType popped_element;
                PopSequenceStack(OPSS, popped_element);
                suffix_str[j] = popped_element;
                j++;
                GetTopElement(OPSS, top_element);
            }
            PushSequenceStack(OPSS, infix_str[i]);
        }
    }
    while (SequenceStackIsEmpty(OPSS) != true)
    {
        ElemType popped_element;
        PopSequenceStack(OPSS, popped_element);
        suffix_str[j] = popped_element;
        j++;
    }
    suffix_str[j] = '\0';
    return true;
}

// 计算后缀表达式
bool CalculateSuffix(char *suffix_str, ElemType &sum_value)
{
    if (strlen(suffix_str) == 0)
    {
        return false;
    }
    SequenceStack OPSS;
    InitSequenceStack(OPSS);
    for (int i = 0; i < strlen(suffix_str); i++)
    {
        if ('0' <= suffix_str[i] && suffix_str[i] <= '9')
        {
            PushSequenceStack(OPSS, suffix_str[i]);
        }
        else
        {
            ElemType left_value, right_value, calculated_value;
            PopSequenceStack(OPSS, right_value);
            PopSequenceStack(OPSS, left_value);
            switch(suffix_str[i])
            {
                case '+':
                    calculated_value = (left_value - '0') + (right_value - '0') + '0';
                    break;
                case '-':
                    calculated_value = (left_value - '0') - (right_value - '0') + '0';
                    break;
                case '*':
                    calculated_value = (left_value - '0') * (right_value - '0') + '0';
                    break;
                case '/':
                    calculated_value = (left_value - '0') / (right_value - '0') + '0';
                    break;
            }
            PushSequenceStack(OPSS, calculated_value);
        }
    }
    PopSequenceStack(OPSS, sum_value);
    return true;
}

int main()
{
    char infix_str[50] = "1+(2*3)-(1-3)";
    char suffix_str[50];
    TransformInfixToSuffix(infix_str, suffix_str);
    printf("suffix = %s\n", suffix_str);
    ElemType calculated_result;
    CalculateSuffix(suffix_str, calculated_result);
    printf("calculated result = %c\n", calculated_result);
    return true;
}