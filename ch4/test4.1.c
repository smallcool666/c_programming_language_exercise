#include <stdio.h>
#include <windows.h>

/**
 * 练习4-1	编写函数strindex(s, t)，它返回字符串t在s中最右边出现的位置。如果s中不包含t，则返回-1。
 * 
 * 思路：
 *   在书中例子的基础上进行修改，书中是从前往后查找来找到最早出现的位置，本题可以从右往左查找最右边出现的位置
 */
int strindex(char s[], char t[]);

int main()
{
    char s[1000], t[1000], c;
    int i = 0, pos;
    printf("input s:\n");
    while((c = getchar()) != '\n') {
        s[i++] = c;
    }
    s[i] = '\0';

    i = 0;
    printf("input t:\n");
    while((c = getchar()) != '\n') {
        t[i++] = c;
    }
    t[i] = '\0';
    pos = strindex(s, t);
    printf("%d\n", pos);
    system("pause");
    return 0;
}

int strindex(char s[], char t[])
{
    int i, j, k, lens, lent;
    lens = lent = 0;
    for (i = 0; s[i] != '\0'; i++, lens++)
        ;
    for (i = 0; t[i] != '\0'; i++, lent++)
        ;
    for (i = lens - lent; i  >= 0; i--) {
        for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++)
            ;
        if (k>0 && t[k]== '\0') {
            return i;
        }
    }
    return -1;
}

/* strindex: return index of t in s, -1 if none */
int strindexold(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++){
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k>0 && t[k]== '\0')
            return i;
    }
    return -1;
}