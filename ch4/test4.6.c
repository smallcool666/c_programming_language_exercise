#include <stdio.h>
#include <stdlib.h> /* for atof ()	*/
#include "4.3_pushandpop.c"
#include "4.3_getop.c"

/**
 * 练习4-6	给计算器程序增加处理变量的命令（提供26个具有单个英文字母变量名的变量很容易）。增加一个变量存放最近打印的值。
 * 
 * 思路：
 *      1. getop 中添加对字母的处理，并能识别sin、exp、pow等函数名
 *      2. 再main中添加对函数的处理
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
    int type, var;
    double op2, variables[26] = {0.0}, v;
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
            case '=':
                //在=赋值操作之前，一定有一个字母变量，遇到字母会向栈中压入变量值，对于赋值操作要把无效的变量值丢弃
                pop();
                if (var >= 'A' && var <= 'Z') {
                    variables[var - 'A'] = pop();
                }
                break;
            case '\n':
                //用小v存储上次打印的值
                v = pop();
                printf("\t%.8g\n", v);
                break;
            default:
                //遇到A-Z的字母，有可能是变量赋值，也有可能是使用变量，无法区分，直接全部压入栈中
                if (type >= 'A' && type <= 'Z') {
                    push(variables[type - 'A']);
                } else if (type = 'v') {
                    push(v);
                } else {
                    printf("error: unknown command %s\n", s);
                }
                break;
        }
        //存储上一个type，对于变量赋值操作存储的就是变量名
        var = type;
    }
    return 0;
}