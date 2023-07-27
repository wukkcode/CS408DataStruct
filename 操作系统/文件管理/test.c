#include <stdio.h>

typedef struct
{
    int number; // 学号
    int addr; // 学生记录的逻辑地址
} IndexTable;

typedef struct
{
    char name[30]; // 姓名
    char major[30]; // 专业
    // more info...
} StudentInfo;

int main()
{
    FILE *fp = fopen(".\\test.txt", "w");
    if (fp == NULL)
    {
        printf("failed!");
    }
    for (int i = 1; i <= 1000; i++)
    {
        fputs("hello world!", fp);
    }
    fclose(fp);
    return 0;
}