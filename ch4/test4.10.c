#include <ctype.h>

/**
 * 练习4-10 另一种方法是通过getline函数读入整个输入行，这种情况下可以不使用 getch与ungetch函数。请运用这一方法修改计算器程序。
 * 
 * 思路：
 *      只需要修改getop函数即可
 *  
 */

#define NUMBER '0' /* signal that a number was found */
#define MAXLINE 1000

int getline(char line[], int limit);

char line[MAXLINE];
int pos;

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    if (line[pos] == '\0') {
        if (getline(line, MAXLINE) == 0) {
            return EOF;
        }
        pos = 0;
    }
    while ((s[0] = c = line[pos++]) == ' '|| c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;	/* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = line[pos++]))
            ;
    if (c == '.')	/* collect fraction part */
        while (isdigit(s[++i] = c = line[pos++]))
            ;
    s[i] = '\0';
    po--;
    return NUMBER;
}