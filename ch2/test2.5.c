#include <stdio.h>
#include <windows.h>

/**
 * 练习2-5	编写函数any (si, s2)，将字符串s2中的任一字符在字符串s1中第一次出现的位置作为结果返回。如果s1中不包含s2中
 * 的字符，则返回-1。（标准库函数strpbrk具有同样的功能，但它返回的是指向该位置的指针。）
 * 
 */
#define MAXLINE 50	/* maximum input line length */
int any(char s1[], char s2[]);

int main()
{
    int len1 = 0, len2 = 0;
    char c, s1[MAXLINE], s2[MAXLINE];
    printf("input string one:\n");
    while ((c = getchar()) != '\n') {
        s1[len1++] = c;
    }
    s1[len1] = '\0';
    printf("input string two:\n");
    while ((c = getchar()) != '\n') {
        s2[len2++] = c;
    }
    s2[len2] = '\0';
    int res;
    res = any(s1, s2);
    printf("---\n%d\n---", res);
    system("pause");
    return 0;
}
int any(char s1[], char s2[])
{
    int i, j, len1 = 0, len2 = 0, res = -1;
    //计算一下字符串的长度
    for (i = 0; s1[i++] != '\0'; len1++) {}
    for (i = 0; s2[i++] != '\0'; len2++) {}
    for (i = 0; i < len2; i++) {
        for (j = 0; j < len1; j++) {
            if (s1[j] == s2[i]) {
                if (res == -1 || j < res) {
                    res = j;
                }
                break;
            }
        }
    }
    return res;
}