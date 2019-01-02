#include <stdio.h>
#include <windows.h>

/**
 * 练习1-8 编写一个统计空格、制表符与换行符个数的程序。
 */

int main()
{
    int blank_num = 0, table_num = 0, newline_num = 0;
    char c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blank_num++;
        } else if (c == '\t') {
            table_num++;
        } else  if (c == '\n') {
            newline_num++;
        }
    }
    printf("blank'num = %d, table'num = %d, newline'num = %d\n", blank_num, table_num, newline_num);
    system("pause");
}