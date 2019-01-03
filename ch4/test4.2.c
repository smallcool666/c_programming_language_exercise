#include <stdio.h>
#include <windows.h>
#include <ctype.h>

/**
 * 练习4-2	对atof函数进行扩充，使它可以处理形如
 *      123.45e-6
 * 的科学表示法，其中，浮点数后面可能会紧跟一个e或E以及一个指数（可能有正负号）。
 * 
 * 思路：
 *   在书中例子的基础上进行修改，后面再添加对
 */
double atofnew(char s[]);

int main()
{
    char s[1000], c;
    int i = 0;
    double pos;
    printf("input s:\n");
    while((c = getchar()) != '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    pos = atofnew(s);
    printf("%f\n", pos);
    system("pause");
    return 0;
}

double atofnew(char s[])
{
    double val, power, res;
    int i, sign;
    for (i = 0; isspace(s[i]); i++)	/* skip white space */
        ;
    sign = (s [i] == '-') ? -1 : 1;
    if (s[i] == '+'|| s[i]=='-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val +	(s[i] - '0');
    }
    if (s[i]=='.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    //下面的代码是在原来基础上添加的逻辑
    int esign = 1, zhishu;
    float chengshu = 1.0;
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        if(s[i] == '-') {
            esign = -1;
        }
        if (s[i] == '-' || s[i] == '+') {
            i++;
        }
        for (zhishu = 0.0; isdigit(s[i]); i++) {
            zhishu = 10.0 * zhishu + (s[i] - '0');
        }
        for (i = 0; i < zhishu; i++) {
            chengshu *= 10.0;
        }
    }
    res = sign * val / power;
    if (esign == 1) {
        return res * chengshu;
    }
    return res / chengshu;
}

/* strindex: return index of t in s, -1 if none */
/* atof: convert string s to double */
double atofold(char s[])
{
    double val, power; int i, sign;
    for (i = 0; isspace(s[i]); i++)	/* skip white space */
        ;
    sign = (s [i] == '-') ? -1 : 1;
    if (s[i] == '+'|| s[i]=='-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val +	(s[i] - '0');
    }
    if (s[i]=='.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}