#include <stdio.h>
#include <windows.h>

/**
 * 练习2-4	squeeze(s1, s2)，将字符串si中任何与字符串s2中字符匹配的字符都删除。
 * 
 */
#define MAXLINE 50	/* maximum input line length */
void squeeze(char s1[], char s2[]);

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
    squeeze(s1, s2);
    printf("---\n%s\n---", s1);
    system("pause");
    return 0;
}
void squeeze(char s1[], char s2[])
{
    int i, j, len1 = 0, len2 = 0;
    //计算一下字符串的长度
    for (i = 0; s1[i++] != '\0'; len1++) {}
    for (i = 0; s2[i++] != '\0'; len2++) {}
    for (i = 0; i <len1 - len2 + 1; i++) {
        j = 0;
        // 以当前字符开始，和s2比较，看相同字符串的最长长度
       while (s1[i + j] == s2[j] && j < len2) {
           j++;
       }
    //    如果找到的长度相等，说明包含这个子串
       if (j == len2) {
           //用后面的字符覆盖查到的子串，吧最后的\0也覆盖到前面
           for (j = i; j <= len1 - len2; j++) {
               s1[j] = s1[j + len2];
           }
           for (j = 0, len1 = 0; s1[j] != '\0'; j++) {
               len1++;
           }
           //第i个字符也被覆盖了，所以还要从第i个字符开始比较
           i--;
       }
    }
}