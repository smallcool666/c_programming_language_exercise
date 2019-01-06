#include <stdio.h>
#include <windows.h>

/**
 * 练习4-12 运用printd函数的设计思想编写一个递归版本的itoa函数，即通过递归 调用把整数转换为字符串。
 * 
 * 思路：
 *      用static类型的内部变量存储需要ungetch处理的字符，在获取字符的时候先判断static变量是否为空
 */
void myitoa(int n, char s[]);
int pos = 0;

int main()
{
    int n;
    char s[100];
    scanf("%d", &n);
    myitoa(n, s);
    s[pos] = '\0';
    printf("%d itoa = %s\n", n, s);
    system("pause");
    return 0;
}

void myitoa(int n, char s[])
{
    if (n < 0) {
        n = -n;
        s[pos++] = '-';
    }
    if (n / 10 > 0) {
        myitoa(n / 10, s);
    }
    s[pos++] = n % 10 + '0';
}


// void itoaold(int n, char s[])
// {
//     int i, sign;
//     if ((sign = n) < 0)	/* record sign */
//         n=-n;	/* make n positive */
//     i = 0;
//     do {	/* generate digits in reverse order */
//         s[i++] =n %10 + '0';	/* get next digit */
//     } while ( (n /= 10)	>0);	/* delete it */
//     if (sign < 0)
//         s[i++]='-';
//     s[i] = '\0';
//     reverse(s);
// }