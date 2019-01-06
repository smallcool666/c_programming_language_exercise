#include <stdio.h>
#include <stdlib.h> /* for atof ()	*/
#include "4.3_pushandpop.c"
#include <ctype.h>
#include <math.h>
#include <string.h>

/**
 * 练习4-5	给计算器程序增加访问sin、exp与pow等库函数的操作。有关这些库函数的详细信息，参见附录B.4节中的头文件<math.h>。
 * 
 * 思路：
 *      1. getop 中添加对字母的处理，并能识别sin、exp、pow等函数名
 *      2. 再main中添加对函数的处理
 *      3. 对函数类型进行区分，识别函数并进行对应处理
 */

#define MAXOP 100	/* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define FUNCTION '-1' /* signal that a function was found */

int getop(char []);
void push(double);
double pop(void);
void funcexec(char s[]);

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
                //fmod()函数可以对浮点型数据进行取模运算
                push(fmod(pop(), op2));
                break;
            //添加取模操作
            //添加函数操作
            case FUNCTION:
                funcexec(s);
                break;
            //添加函数操作
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

void funcexec(char s[])
{
    double op2;
    if (strcmp(s, "sin") == 0) {
        push(sin(pop()));
    } else if (strcmp(s, "exp") == 0) {
        push(exp(pop()));
    } else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    }
}

int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c, flag = 1;
    while ((s[0] = c = getch()) == ' '|| c == '\t')
        ;
    s[1] = '\0';
    //如果是字母或数字，或.和-，就继续
    if (!isalnum(c) && c != '.' && c != '-')
        return c;	/* not a number */
     i = 0;
     //如果是字母，说明是函数名，获取所有的字母
     if (isalpha(c)) {
         while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        ungetch(c);
        return FUNCTION;
     }
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