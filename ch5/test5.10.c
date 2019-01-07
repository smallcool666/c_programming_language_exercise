#include <stdio.h>
#include <stdlib.h> /* for atof ()	*/
//这两个文件在ch4目录下，需要修改一下include路径或者把这两个文件放到同一目录下
#include "4.3_getop.c"
#include "4.3_pushandpop.c"

/**
 * 练习5-10 编写程序expr，以计算从命令行输入的逆波兰表达式的值，其中每个运算 符或操作数用一个单独的参数表示。例如，命令
 *  expr 2 3 4 + *
 *
 * 思路：
 *      在4.3计算薄的基础上进行修改
 *      读入参数使用ungets方法输入一个空格（参数结束标记）和一个argv的参数
 *      修改循环条件为agrc > 0，出错的话把argv置为1，就能结束循环了 
 */

#define MAXOP 100	/* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
//4.7中实现的方法
void ungets(char s[]);

int main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];
    while (argc > 0) {
        ungets(" ");
        ungets(*++argv);
        type = getop(s);
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
            case '\n':
                printf("\t%.8g\n", pop());break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    system("pause");
    return 0;
}

void ungets(char s[])
{
    int i, len;
    while (*s) {
        len++;
    }
    while (len > 0) {
        ungetch(s[--len]);
    }
}