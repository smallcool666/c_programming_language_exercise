#include <stdio.h>
#include <windows.h>

/**
 * 练习5-1 在上面的例子中，如果符号+或-的后面紧跟的不是数字，getint函数将把 符号视为数字0的有效表达方式。
 * 修改该函数，将这种形式的+或-符号重新写回到输入流中。
 * 
 * 思路：
 *      读到+或者-时，再读一个字符，如果不是数据就压回到输入中
 */

int main()
{
    system("pause");
    return 0;
}

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign, tmp;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != ' + ' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c =='-') {
        tmp = c;
        c = getch();
        if (!isdigit(c)) {
            if (c != EOF) {
                ungetch(c);
            }
            ungetch(tmp);
        }
        //返回+或-符号
        return tmp;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn =10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
