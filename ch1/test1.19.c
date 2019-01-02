#include <stdio.h>
#include <Windows.h>
/**
 *  练习1-19 编写函数reverse(s)，将字符串s中的字符顺序颠倒过来。使用该函数 编写一个程序，每次颠倒一个输入行中的字符
 * 顺序。
 */
#define MAXLINE 1000	/* maximum input line length */

void reverse(char arr[], int len);

int main()
{
    int len = 0, i;
    char c;
    char line[MAXLINE]; /* current input line */
    while ((c = getchar()) != EOF) {
       if (c != '\n') {
           line[len++] = c;
       } else {
           line[len] = '\0';
           reverse(line, len);
           for (i = 0; i < len; i++) {
               printf("%c", line[i]);
           }
           printf("\n");
           len = 0;
       }
    }
    system("pause");
    return 0;
}

void reverse(char arr[], int len)
{
    int i, tmp, mid = len / 2;
    for (i = 0; i < mid; i++) {
        tmp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = tmp;
    }
}