#include <ctype.h>

/**
 * 练习4-11 修改getop函数，使其不必使用ungetch函数。提示：可以使用一个 static类型的内部变量解决该问题。
 * 
 * 思路：
 *      用static类型的内部变量存储需要ungetch处理的字符，在获取字符的时候先判断static变量是否为空
 */
#define NUMBER '0' /* signal that a number was found */

int getch(void);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    static int buf = 0;
    if (buf == 0) {
        c = getch();
    } else {
        c = buf;
        buf = 0;
    }
    while ((s[0] = c) == ' '|| c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;	/* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')	/* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        buf = c;
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;	/* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp >0) ? buf[--bufp] : getchar();
}