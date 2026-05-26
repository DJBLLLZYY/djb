#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 递归求字符串长度，不创建临时变量
int my_strlen( char* str)
{
    if (*str == '\0')
        return 0;
    else
        return 1 + my_strlen(str + 1);
}

int main()
{
    char str[100] = { 0 };  // 存储用户输入的字符串

    printf("请输入一个字符串: ");
    // 使用fgets可以读取空格，并且防止溢出
    /*fgets(str, sizeof(str), stdin);*/
    scanf("%s", str);
    // 移除fgets自带的换行符（不影响长度计算，但为了显示美观）
    //int i = 0;
    //while (str[i] != '\0' && str[i] != '\n')
    //    i++;
    //if (str[i] == '\n')
    //    str[i] = '\0';

    //int len = my_strlen(str);
    printf("字符串的长度为: %d\n", my_strlen(str));

    return 0;
}