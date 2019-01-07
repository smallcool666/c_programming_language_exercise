#include <stdio.h>
#include <windows.h>

/**
 * 练习5-5	实现库函数strncpy、strncat和strncmp，它们最多对参数字符串中的前n个字符进行操作。
 * 例如，函数strncpy(s, t, n)将t中最多前n个字符复制到s中。更详细的说明请参见附录B。
 * 
 */

void mystrncpy(char *s, char *t, int n);
void mystrncat(char *s, char *t, int n);
int mystrncmp(char *s, char *t, int n);

int main()
{
    char s[100], t[100];
    printf("input s:\n");
    scanf("%s", s);
    printf("input t:\n");
    scanf("%s", t);
    printf("strncmp(s, t, 2) = %d\n", mystrncmp(s, t, 2));
    mystrncpy(s, t, 2);
    printf("after strncpy(s, t, 2), s = %s\n", s);
    mystrncat(s, t, 2);
    printf("after strncat(s, t, 2), s = %s\n", s);
    system("pause");
    return 0;
}

void mystrncpy(char *s, char *t, int n)
{
    for (; n > 0 && *t; n--) {
        *s++ = *t++;
    }
    *s = '\0';
}

void mystrncat(char *s, char *t, int n)
{
    while(*s) {
        s++;
    }
    for (; n > 0; n--) {
        *s++ = *t++;
    }
    *s = '\0';
}

int mystrncmp(char *s, char *t, int n)
{
    for (; n > 0 && *s && *t; n--) {
        if (*s > *t) {
            return 1;
        } else if (*s < *t){
            return -1;
        }
        s++;
        t++;
    }
    return 0;
}