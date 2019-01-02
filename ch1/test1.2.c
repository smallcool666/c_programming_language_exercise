#include "stdio.h"
#include <windows.h>
/**
 * 练习1-2 做个实验，当printf函数的参数字符串中包含\c (其中c是上面的转义字符序列中未曾列出的某一个字符）时，观察一下会出现什么情况。
 */

int main()
{
    // warning: unknown escape sequence: '\c'
    //hello worldcc
    printf("hello world\c\c\n");
    system("pause");
    return 0;
}