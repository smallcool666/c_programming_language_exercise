#include <stdio.h>
#include <windows.h>

/**
 * 练习4-13 编写一个递归版本的reverse(s)函数，以将字符串s倒置。
 * 
 * 思路：
 *      
 */
void reverse(char s[]);

int main()
{
    char s[100];
    scanf("%s", s);
    reverse(s);    
    printf("%s\n", s);
    system("pause");
    return 0;
}

void myreverse(char s[], int start, int end);

void reverse(char s[])
{
    myreverse(s, 0, strlen(s) - 1);
}

void myreverse(char s[], int start, int end)
{
    int tmp;
    if (start >= end) {
        return ;
    }
    tmp = s[start];
    s[start] = s[end];
    s[end] = tmp;
    myreverse(s, start + 1, end - 1);
}