#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLength 50

/*
KMP算法难点在于next数组的求解，读者如果难以理解的话可以人工运行一下代码
其实要点就是可以个图，你就会发现先考虑最好情况，如果最好情况不满足向前偏移即可继续对比...
推荐一个B站视频：BV16X4y137qw
希望可以对读者加深理解
*/

// 静态分配的顺序串
typedef struct
{
    char string_data[MaxLength+1];
    int length;
} StaticCharacterString;

// 串的赋值
bool StringAssign(StaticCharacterString &SCS, char *string_value)
{
    if (strlen(string_value) > MaxLength)
    {
        return false;
    }
    for (int i = 1; i <= strlen(string_value); i++)
    {
        SCS.string_data[i] = string_value[i-1];
    }
    SCS.length = strlen(string_value);
    return true;
}

// 求KMP算法中的next数组
void GetKMPNextArray(StaticCharacterString PatternString, int next[])
{
    next[1] = 0;
    int pattern_index = 1;
    int next_tool = 0;
    while (pattern_index <= PatternString.length)
    {
        if (next_tool == 0 || PatternString.string_data[pattern_index] == PatternString.string_data[next_tool])
        {
            pattern_index++;
            next_tool++;
            next[pattern_index] = next_tool;
        }
        else
        {
            next_tool = next[next_tool];
        }
    }
}

// 通过next数组求出nextval数组对KMP算法进行优化
void GetKMPNextValueArray(StaticCharacterString PatternString, int nextval[])
{
    int pattern_index;
    for (pattern_index = 2; pattern_index <= PatternString.length; pattern_index++)
    {
        if (PatternString.string_data[pattern_index] == PatternString.string_data[nextval[pattern_index]])
        {
            nextval[pattern_index] = nextval[nextval[pattern_index]];
        }
    }
}

// 串的KMP模式匹配算法(主串指针不回朔)
int StringKMPPatternMatching(StaticCharacterString MainString, StaticCharacterString PatternString, int next[])
{
    int main_index = 1;
    int pattern_index = 1;
    while (main_index <= MainString.length && pattern_index <= PatternString.length)
    {
        if (pattern_index == 0 || MainString.string_data[main_index] == PatternString.string_data[pattern_index])
        {
            main_index++;
            pattern_index++;
        }
        else
        {
            pattern_index = next[pattern_index];
        }
    }
    if (pattern_index > PatternString.length)
    {
        return main_index - pattern_index + 1;
    }
    return -1;
}

int main()
{
    StaticCharacterString MainString;
    StaticCharacterString PatternString;
    char main_string_value[20] = "hello world";
    char pattern_string_value[20] = "o w";
    StringAssign(MainString, main_string_value);
    StringAssign(PatternString, pattern_string_value);
    int next[strlen(pattern_string_value)+1];
    GetKMPNextArray(PatternString, next);
    int index = StringKMPPatternMatching(MainString, PatternString, next);
    printf("index = %d\n", index);
    return 0;
}