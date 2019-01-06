#include <ctype.h>
#include <string.h>

/**
 * 练习4-8	假定最多只压回一个字符。请相应地修改getch与ungetch这两个函数。
 * 
 * 思路：缓存容量只有一个字符，使用一个字符变量存储字符即可
 *  
 */

char buf = 0;

int getch(void) /* get a (possibly pushed-back) character */
{
    char c;
    if (buf != 0) {
        c = buf;
    } else {
        c = getchar();
    }
    buf = 0;
    return c;
}
void ungetch(int c) /* push character back on input */
{
    if (buf == 0)
        printf("ungetch: buff is full\n");
    else
        buf = c;
}