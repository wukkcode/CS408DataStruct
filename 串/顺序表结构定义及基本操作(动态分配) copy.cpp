#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLength 50

// 静态分配的顺序串
typedef struct
{
    char string_data[MaxLength];
    int length;
} StaticCharacterString;

// 动态分配的顺序串
typedef struct
{
    char* string_data;
    int length;
} DynamicCharacterString;

// 串的初始化
void ClearString(StaticCharacterString &SCS)
{
    SCS.length = 0;
}

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

// 串的复制
bool StringCopy(StaticCharacterString &SCS1, StaticCharacterString SCS2)
{
    for (int i = 1; i <= SCS2.length; i++)
    {
        SCS1.string_data[i] = SCS2.string_data[i];
    }
    return true;
}

// 串的判空操作
bool StringIsEmpty(StaticCharacterString SCS)
{
    if (SCS.length == 0)
    {
        return true;
    }
    return false;
}

// 串的比较操作：如果SCS1>SCS2，返回正值；如果SCS1<SCS2，返回负值；如果SCS1=SCS2，返回0；
int StringCompare(StaticCharacterString SCS1, StaticCharacterString SCS2)
{
    for (int i = 1; i <= SCS1.length && i <= SCS2.length; i++)
    {
        if (SCS1.string_data[i] != SCS2.string_data[i])
        {
            return SCS1.string_data[i] - SCS2.string_data[i];
        }
    }
    return SCS1.length - SCS2.length;
}

// 求串长
int StringLength(StaticCharacterString SCS)
{
    return SCS.length;
}

// 求子串：SubSCS是一个空串
bool GetSubString(StaticCharacterString &SubSCS, StaticCharacterString MomSCS, int position, int length)
{
    // 位置及所取字串长度不合理
    if (position + length - 1 > MomSCS.length || position <= 0)
    {
        return false;
    }
    for (int i = 1; i <= length; i++)
    {
        SubSCS.string_data[i] = MomSCS.string_data[position++];
    }
    SubSCS.length = length;
    return true;
}

// 串连接：注意连接之后的串的长度可能超过最大长度
bool ConcatString(StaticCharacterString &NewSCS, StaticCharacterString SCS1, StaticCharacterString SCS2)
{
    int index_tool;
    if (SCS1.length + SCS2.length <= MaxLength)
    {
        for (index_tool = 1; index_tool <= SCS1.length; index_tool++)
        {
            NewSCS.string_data[index_tool] = SCS1.string_data[index_tool];
        }
        for (int j = 1; j <= SCS2.length; j++)
        {
            NewSCS.string_data[index_tool++] = SCS2.string_data[j];
        }
        NewSCS.length = SCS1.length + SCS2.length;
        return true;
    }
    else
    {
        for (index_tool = 1; index_tool <= SCS1.length; index_tool++)
        {
            NewSCS.string_data[index_tool] = SCS1.string_data[index_tool];
        }
        for (int j = 1; index_tool <= MaxLength; j++)
        {
            NewSCS.string_data[index_tool++] = SCS2.string_data[j];
        }
        NewSCS.length = MaxLength;
        return false;
    }
}

// 定位操作：假设母串和子串都不为空，且子串的长度小于等于母船的长度
int IndexSubString(StaticCharacterString MomString, StaticCharacterString SubString)
{
    StaticCharacterString result_substring;
    int i;
    for (i = 1; i <= MomString.length && GetSubString(result_substring, MomString, i, SubString.length); i++)
    {
        if (StringCompare(result_substring, SubString) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    StaticCharacterString MomSCS;
    StaticCharacterString SubSCS;
    ClearString(MomSCS);
    ClearString(SubSCS);
    char string_value[20] = "hello world";
    StringAssign(MomSCS, string_value);
    printf("MomString = %s. MomString length = %d\n", MomSCS.string_data+1, MomSCS.length);
    GetSubString(SubSCS, MomSCS, 3, 2);
    printf("%s\n", SubSCS.string_data+1);
    int index = IndexSubString(MomSCS, SubSCS);
    printf("index = %d\n", index);
}