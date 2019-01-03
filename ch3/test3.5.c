#include <stdio.h>
#include <windows.h>

/**
 * 练习3-5 编写函数itob(n, s, b)，将整数n转换为以b为底的数，并将转换结果以字符的形式保存到字符串s中。
 * 例如，itob(n, s, 16)把整数n格式化成十六进制整数 保存在s中。
 * 
 * 思路：
 *    进制转换使用辗转相除法，在循环中用s去除以b，得到的余数就是各个位上的值，每次循环s都会用s/b更新
 *    最先得到的数是低位，最后需要反转一下
 */
void itob(int n, char s[], int b);
int main()
{
    int b, n;
    char s[1000];
    printf("input n, b:");
    scanf("%d %d", &n, &b);
    itob(n, s, b); 
    printf("%d 的 %d 进制为 %s\n", n, b, s);
    system("pause");
    return 0;
}

void itob(int n, char s[], int b)
{
    //使用0-9和a-z来表示0-36，最大表示36进制
    if (b > 37) {
        printf("too large num\n");
        return ;
    }
    int i, j, wei;
    char c;
    for (i = 0; n > 0; n /= b) {
        wei = n % b;
        if (wei < 10) {
            s[i++] = wei + '0';
        } else {
            s[i++] = wei - 10 + 'a';
        }
    }
    s[i] = '\0';
    //存放的数据是反着的，即s[0]存的是最低位的值，要反转一下
    i = i - 1;
    for (j = 0; j <= i / 2; j ++) {
        c = s[j];
        s[j] = s[i - j];
        s[i - j] = c;
    }
}