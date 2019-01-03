#include <stdio.h>
#include <windows.h>

/**
 * 练习3-4 在数的对二的补码表示中，我们编写的itoa函数不能处理最大的负数，即n等于-2^(n-1)的情况。
 * 请解释其原因。修改该函数，使它在任何机器上运行时都能打印出正确的值。
 * 
 * 原因：
 *   有符号数的范围是-2^(n-1)~2^(n-1)-1,最大的复数转成整数之后上溢
 * 思路：
 *   不能处理最大的负数是因为一开始就先把负数转换成正数，不进行这个转换，对余数求绝对值就可以了
 */

#define MAXLINE 1000
void itoa(int n, char s[]);

int main()
{
    system("pause");
    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;
    sign = n;
    i = 0;
    do {
        s[i++] = (n % 10 < 0 ? -n % 10 : n % 10) + '0';
    } while ( (n /= 10)	>0);
    if (sign < 0)
        s[i++]='-';
    s[i] = '\0';
    reverse(s);
}