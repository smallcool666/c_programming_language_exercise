#include <stdio.h>
#include <windows.h>

/**
 * 练习3-6 修改itoa函数，使得该函数可以接收三个参数。其中，第三个参数为最小 字段宽度。为了保证转换后所得的结果至少具有第三个参数指定的最小宽度，
 * 在必要时应在 所得结果的左边填充一定的空格。
 * 
 * 思路：
 *   在3.4的基础上，最后翻转之前判断一下长度，如果长度不足就填充空格
 */

#define MAXLINE 1000
void itoa(int n, char s[]);

int main()
{
    system("pause");
    return 0;
}

void itoa(int n, char s[], int len)
{
    int i, sign;
    sign = n;
    i = 0;
    do {
        s[i++] = (n % 10 < 0 ? -n % 10 : n % 10) + '0';
    } while ( (n /= 10)	>0);
    if (sign < 0)
        s[i++]='-';
    while (i < len) {
        s[i++] = ' ';        
    }

    s[i] = '\0';
    reverse(s);
}