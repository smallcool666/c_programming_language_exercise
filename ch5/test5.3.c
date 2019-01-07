#include <stdio.h>
#include <windows.h>

/**
 * 练习5-3	用指针方式实现第2章中的函数strcat。函数strcat(s, t)将t指向的字符串复制到s指向的字符串的尾部。
 * 
 * 思路：
 *      先循环到达s的结尾，再把t逐个赋值到s中
 */
void mystrcat(char *s, char *t);
int main()
{
    char s[100], t[100];
    printf("input s:\n");
    scanf("%s", s);
    printf("input t:\n");
    scanf("%s", t);
    mystrcat(s, t);
    printf("strcat(s, t) = %s---\n", s);
    system("pause");
    return 0;
}

void mystrcat(char *s, char *t)
{
    //判断条件等价于 *s != 0,又等价于*s != '\0'，因为'\0'的值为0
    while (*s)
        s++;
    while (*t) {
        *s++ = *t++;
    }
    return ;
}