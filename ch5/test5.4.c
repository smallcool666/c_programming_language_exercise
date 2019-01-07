#include <stdio.h>
#include <windows.h>

/**
 * 练习5-4	编写函数strend(s, t)。如果字符串t出现在字符串s的尾部，该函数返回1;否则返回0。
 * 
 * 思路：
 *      先分别遍历两个字符串达到字符串的结尾，并记录t的长度，根据t的长度作为循环依据逐个比较s和t的元素
 */
int strend(char *s, char *t);
int main()
{
    char s[100], t[100];
    printf("input s:\n");
    scanf("%s", s);
    printf("input t:\n");
    scanf("%s", t);
    printf("%d\n", strend(s, t));
    system("pause");
    return 0;
}

int strend(char *s, char *t)
{
    int tlen = 0;
    char *send = s, *tend = t;
    while (*send) {
        send++;
    }
    while (*tend) {
        tend++;
        tlen++;
    }
    while (tlen-- >= 0) {
        if (*send-- != *tend--) {
            return 0;
        }
    }
    return 1;
}