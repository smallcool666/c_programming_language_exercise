#include <stdio.h>
#include <windows.h>

/**
 * 练习5-6 采用指针而非数组索引方式改写前面章节和练习中的某些程序，例如 getline (第1、4章），atoi、itoa以及它们的变体形式（第2、3、4章），
 * reverse (第 3章），strindex、getop (第4章）等等。
 * 
 * 仅实现了getline和getop两个方法，并把老的方法和用指针实现的方法放在一起便于比较
 */

int mygetline(char *s, int lim);


int main()
{
    char s[100], t[100];
    printf("input line:\n");
    mygetline(s, 100);
    printf("line: %s---\n", s);
    system("pause");
    return 0;
}

int getlineold(char s[], int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar ()) !=EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i]= '\0'; 
    return i;
}

int mygetline(char *s, int lim)
{
    int c;
    char *start = s;
    while (--lim > 0 && (*s++ = c=getchar ()) !=EOF && c != '\n')
        ;
    *s = '\0'; 
    return s - start;
}

#define NUMBER '0' /* signal that a number was found */
int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
int getopold(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' '|| c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;	/* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')	/* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int getop(char *s)
{
    int i, c;
    while ((*s = c = getch()) == ' '|| c == '\t')
        ;
    *++s = '\0';
    if (!isdigit(c) && c != '.')
        return c;	/* not a number */
    s--;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(*s++ = c = getch()))
            ;
    if (c == '.')	/* collect fraction part */
        while (isdigit(*s++ = c = getch()))
            ;
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}