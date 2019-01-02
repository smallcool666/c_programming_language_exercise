#include <stdio.h>
#include <Windows.h>
/**
 *  练习1-17	编写一个程序，打印长度大于80个字符的所有输入行。
 */
#define MAXLINE 81	/* maximum input line length */

int main()
{
    int i, len = 0;	/* current line length */
    char c;
    char line[MAXLINE]; /* current input line */
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            //打印一个换行，让新输入的行另起一行输入
            printf("\n");
            //新行长度清零
            len = 0;
            continue;
        }
        //读进来的内容长度不足80时，先暂时放在line数组里，长度到80时输出，后续字符全部输出
        if (len < 80) {
            line[len++] = c;
        } else if (len == 80) {
            for (i = 0; i < 80; i++) {
                putchar(line[i]);
            }
            len++;//这时长度81
            putchar(c);
        } else {
            putchar(c);
            len++;
        }
    }
    system("pause");
    return 0;
}