#include <stdio.h>
#include <windows.h>

/**
 * 练习5-2	模仿函数getint的实现方法，编写一个读取浮点数的函数getfloat。getfloat函数的返回值应该是什么类型？
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
int getfloat(double *pn)
{
    int i, c, chushu = 1;
    while ((c = getch()) == ' '|| c == '\t')
        ;
    if (!isdigit(c) && c != '.' && c != '+' && c != '-' && c != EOF)
        return c;	/* not a number */
    *pn = 0;
    while (isdigit(c)) {
        *pn = *pn * 10.0 + c - '0';
        c = getch();
    }
    if (c == '.')	/* collect fraction part */
        while (isdigit(c = getch())) {
            chushu *= 10.0;
            *pn = *pn * 10.0 + c - '0';
        }
    *pn = *pn / chushu;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}
