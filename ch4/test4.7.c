#include <ctype.h>
#include <string.h>
#include "4.3_getop.c"
/**
 * 练习4-7	编写一个函数ungets(s)，将整个字符串s压回到输入中。ungets函数需要使用buf和bufp吗？它能否仅使用ungetch函数？
 * 
 * 思路：得到字符串长度，循环调用ungetch函数压回栈中
 *  
 */ 
#define NUMBER '0' /* signal that a number was found */

void ungetch(int);

void ungets(char s[])
{
    int i, len = strlen(s);
    while (len > 0) {
        ungetch(s[--len]);
    }
}