#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLength 50

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

// 串的朴素模式匹配算法(即找出所有的子串与模式串相比较)
int StringNaivePatternMatching(StaticCharacterString MainString, StaticCharacterString PatternString)
{
    int main_index = 1;
    int pattern_index = 1;
    while (main_index <= MainString.length && pattern_index <= PatternString.length)
    {
        if (MainString.string_data[main_index] == PatternString.string_data[pattern_index])
        {
            main_index++;
            pattern_index++;
        }
        else
        {
            main_index = main_index - pattern_index + 2;
            pattern_index = 1;
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
    char pattern_string_value[20] = "x";
    StringAssign(MainString, main_string_value);
    StringAssign(PatternString, pattern_string_value);
    int index = StringNaivePatternMatching(MainString, PatternString);
    printf("index = %d\n", index);
    return 0;
}