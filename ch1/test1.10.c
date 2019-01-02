#include <stdio.h>
#include <windows.h>
#include <conio.h>

/**
 *  练习1-10	编写一个将输入复制到输出的程序，并将其中的制表符替换为\t，把回退符替换为\b，把反斜杠替换为\\。这样可以将
 * 制表符和回退符以可见的方式显示出来。
 * 
 *  getch()是编程中所用的函数，这个函数是一个不回显函数，当用户按下某个字符时，函数自动读取，无需按回车，有的C语言命令行程
 * 序会用到此函数做游戏，但是这个函数并非标准函数，要注意移植性！
 */

int main()
{
    char c;
    while ((c = getch()) != EOF) {
        if (c == '\t') {
            putchar(c);
            putchar('\n');
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }
    system("pause");
}