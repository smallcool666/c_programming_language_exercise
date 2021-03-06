#include <stdio.h>
#include <stdlib.h> /* for atof ()	*/
#include "4.3_pushandpop.c"
#include <ctype.h>
#include <math.h>

/**
 * 练习4-3	在有了基本框架后，对计算器程序进行扩充就比较简单了。在该程序中加入取模（％)运算符，并注意考虑负数的情况。
 * 
 * 思路：
 *      1. 添加取模处理
 *      2. 添加负数处理，负数需要在getop中处理
 *      3. getop方法直接写在本文件里
 */

#define MAXOP 100	/* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            //添加取模操作
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    //fmod()函数可以对浮点型数据进行取模运算
                    push(fmod(pop(), op2));
                } else {
                    printf("% error: zero divisor\n");
                }
                break;
            //添加取模操作
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define NUMBER '0' /* signal that a number was found */

int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c, flag = 1;
    while ((s[0] = c = getch()) == ' '|| c == '\t')
        ;
    s[1] = '\0';
    //-可能是负数的一部分，需要之后判断处理
    if (!isdigit(c) && c != '.' && c != '-')
        return c;	/* not a number */
     i = 0;
    //如果-后面紧跟一个数字，说明是一个负数，否则就是一个减号，直接返回
    if (c == '-') {
        c = getch();
        if (isdigit(c)) {
            s[++i] = c;
        } else {
            ungetch(c);
            return '-';
        }
    }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')	/* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;	/* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp >0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}