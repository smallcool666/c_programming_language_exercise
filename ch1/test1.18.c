#include <stdio.h>
#include <Windows.h>
/**
 *  练习1-18	编写一个程序，删除每个输入行末尾的空格及制表符，并删除完全是空格的行。
 */
#define MAXLINE 100	/* maximum input line length */

int main()
{
    //blank_len表示当前行最末尾的连续空格字符数，遇到非空格就重置为0
    int blank_len = 0, len = 0;
    char c;
    char line[MAXLINE]; /* current input line */
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            //如果空行就不输出
            if (len > blank_len) {
                line[len - blank_len] = '\0';
                //字符串后面添加---用于定位输出的结束
                printf("%s---\n", line);
                len = 0;
                continue;
            }
        }
        if (c == ' ' || c == '\t') {
            blank_len++;
        } else {
            blank_len = 0;
        }
        line[len] = c;
        //len指向下一个字符
        len++;
    }
    system("pause");
    return 0;
}