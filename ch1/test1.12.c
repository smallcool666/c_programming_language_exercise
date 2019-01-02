#include <stdio.h>
#include <windows.h>

/**
 * 练习1-12	编写一个程序，以每行一个单词的形式打印其输入。
 */

#define IN 1	/* inside a word */
#define OUT 0	/* outside a word */

/* count lines, words, and characters in input */
int main()
{
    int c, state;
    state = OUT;
    while ((c = getchar())	!= EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state != OUT ) {
                putchar('\n');
                state = OUT;
            }
        } else {
            putchar (c);
            state = IN;
        }
    }
    system("pause");
    return 0;
}