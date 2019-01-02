#include <stdio.h>
#include <windows.h>

/**
 * 练习2-2	在不使用运算符&&或||的条件下编写一个与上面的for循环语句等价的循环语句。
 * 
 * //上面的for语句如下
 * for (i=0; i<lim-1 && (c=getchar())	!= '\n'	&& c != EOF; ++i)
 *      s[i] = c;
 */
#define MAXLINE 1000	/* maximum input line length */

int main()
{
    int i = 0, lim = MAXLINE;
    char c, s[MAXLINE];
    while (1) {
        if (i >= lim - 1) {
            printf("not enough space\n");
            break;
        }else if ((c = getchar()) == EOF) {
            break;
        } else if (c == '\n') {
            break;
        }
        s[i] = c;
        i++;
    }
    system("pause");
    return 0;
}