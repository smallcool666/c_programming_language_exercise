#include <stdio.h>
#include <windows.h>

/**
 *练习2-10 重新编写将大写字母转换为小写字母的函数lower，并用条件表达式替代其中的if-else结构。
 */

int lower(char c);

int main()
{
    char c;
    while ((c = getchar()) != EOF) {
        putchar(lower(c));
    }
    
    system("pause");
    return 0;
}

int lower(char c)
{
    return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}