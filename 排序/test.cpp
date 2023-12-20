#include <stdio.h>

typedef MaxSize 50

typedef struct LinkNode
{
    char letter;
    LinkNode *next;
} LinkNode, *WordList;

// 计算单词的长度
int CalculateLengthOfWord(WordList word)
{
    int length = 0;
    while (word->next != NULL)
    {
        length++;
        word = word->next;
    }
    return length;
}

// 找共同后缀的第一个字母（太优雅了）
LinkNode* FindCommonSuffix(WordList word1, WordList word2)
{
    int length1 = CalculateLengthOfWord(word1);
    int length2 = CalculateLengthOfWord(word2);
    LinkNode* str1 = word1;
    LinkNode* str2 = word2;
    while (length1 > length2)
    {
        length1--;
        str1 = str1->next;
    }
    while (length2 > length1)
    {
        length2--;
        str2 = str2->next;
    }
    while (str1->next != NULL && str1->next != str2->next)
    {
        str1 = str1->next;
        str2 = str2->next;
    }
    return str1->next;
}

typedef struct
{
    int data[MaxSize];
    int length;
} SequenceList;



SequenceList MergeLists(SequenceList sl1, SequenceList sl2)
{
    SequenceList result_sl;
    result_sl.length = sl1.length + sl2.length;
    int i, j, k;
    for (i = 0, j = 0, k = i; i < sl1.length && j < sl2.length;)
    {
        if (sl1.data[i] <= sl2.data[i])
        {
            result_sl.data[k++] = sl1.data[i++];
        }
        else
        {
            result_sl.data[k++] = sl2.data[j++];
        }
    }
    while (i < sl1.length)
    {
       result_sl.data[k++] = sl1.data[i++]; 
    }
    while (j < sl2.length)
    {
        result_sl.data[k++] = sl1.data[j++];
    }
    return result_sl;
}



// 键盘中断处理程序示例
void keyboardInterruptHandler()
{
    char key = readFromKeyboardHardware(); // 从硬件读取按键
    addToKeyboardBuffer(key); // 将按键添加到键盘控制器缓冲区
    signalKeyboardDriver(); // 通知键盘驱动程序有新数据
}

// 键盘驱动程序示例
void keyboardDriver()
{
    while(true)
    {
        waitForSignalFromInterruptHandler(); // 等待来自中断处理程序的信号
        char key = getFromKeyboardBuffer(); // 从键盘控制器缓冲区获取按键
        processkey(key); // 处理按键
        snedKeyToSystem(key); // 将按键发送到系统缓冲区
    }
}