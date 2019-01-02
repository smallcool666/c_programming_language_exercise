#include <stdio.h>
#include <windows.h>

/**
 * 练习3-2 编写一个函数escape(s, t)，将字符串t复制到字符串s中，并在复制 过程中将换行符、制表符等不可见字符分别转换
 * 为\n、\t等相应的可见的转义字符序列。要 求使用swich语句。再编写一个具有相反功能的函数，在复制过程中将转义字符序列
 * 转换为 实际字符。
 */

#define MAXLINE 1000

int escape(char s[], char t[]);
void nonescape(char s[], char t[]);
int main()
{
    char s[MAXLINE], t[MAXLINE], c;
    int i = 0;
    while ((c = getchar()) != EOF) {
        t[i++] = c;
    }
    t[i] = '\0';
    nonescape(s, t);
    printf("%s\n", s);
    system("pause");
    return 0;
}

/**
 * 把换行符、制表符换成转义字符展示，主要是转换时一个字符变成两个字符，需要注意一下字符中的位置
 */
int escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\n': 
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default :
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

/**
 * 转义字符转实际字符，两个字符变一个
 */
void nonescape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++, j++) {
        if (t[i] == '\\') {
            switch (t[i+1]) {
                case 'n':
                    s[j] = '\n';
                    i++;
                    break;
                case 't':
                   s[j] = '\t';
                   i++;
                    break;
                default :
                    s[j] = t[i];
                    break;
            }
        } else {
            s[j] = t[i];
        }
    }
    s[j] = '\0';
}