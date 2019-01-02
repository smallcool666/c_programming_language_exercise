#include <stdio.h>
#include <windows.h>

/**
 * 练习1-9	编写一个将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替。
 */

int main()
{
    char c;
    //flag用来表示当前字符的前一个字符是不是空格
    // 1表示前一个字符是空格，那么如果当前字符还是空格，就不输出，如果是非空格，flag置为0
    // 0表示前一个字符不是空格，如果当前字符时空格，就输出空格，然后flag置为1
    int flag = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (flag == 0) {
                putchar(c);
            }
            flag = 1;
        } else {
            putchar(c);
            flag = 0;
        }
    }
    system("pause");
}