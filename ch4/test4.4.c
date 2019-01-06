/**
 * 练习4-4	在栈操作中添加几个命令，分别用于在不弹出元素的情况下打印栈顶元素；复制栈顶元素；交换栈顶两个元素的值。另外增加一个命令用于清空栈。
 * 
 * 思路：
 *      1. 不弹出元素的情况下打印栈顶元素：pop之后再压回到栈中;这里是用数组实现的，直接返回指针当前指向位置，不修改指针值即可
 *      2. 复制栈顶元素：pop出来栈顶元素，复制，再压回到栈中；这里是用数组实现的，直接赋值当前指向位置的值即可
 *      3. 交换栈顶两个元素的值：pop两次，按相反顺讯压回到栈中；交换顶部两个元素的值即可
 *      4. 清空栈：pop元素直到为空；设置指针值为初始值
 */

#define MAXOP 100	/* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main()
{
}

#define MAXVAL 10 /* maximum depth of val stack */
int sp =0;	/* next free stack position */
double val[MAXVAL]; /* value stack */
/* push: push f onto value stack */

void push(double f)
{
    if (sp< MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/**
 * 打印栈顶元素
 */
void printtopstack(void)
{
    if(sp > 0) {
        printf("%d\n", val[sp]);
    } else {
        printf("error: stack empty\n");        
    }
}

/**
 * 复制栈顶元素
 */
void cpoytopstack(double *target)
{
    if(sp > 0) {
        *target = val[sp];
    } else {
        printf("error: stack empty\n");        
    }
}

/**
 * 交换栈顶两个元素的值
 */
void exchangetoptwo(void)
{
    double tmp;
    if(sp > 2) {
        tmp = val[sp];
        val[sp] = val[sp - 1];
        val[sp - 1] = tmp;
    } else {
        printf("error: there is not enough item in stack\n");
    }
}

/**
 * 清空栈
 */
void exchangetoptwo(void)
{
    double tmp;
    if(sp > 2) {
        tmp = val[sp];
        val[sp] = val[sp - 1];
        val[sp - 1] = tmp;
    } else {
        printf("error: there is not enough item in stack\n");
    }
}