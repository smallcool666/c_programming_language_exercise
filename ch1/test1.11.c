#include <stdio.h>
#include <windows.h>

/**
 *  练习1-11 你准备如何测试单词计数程序？如果程序中存在某种错误，那么什么样的输入最可能发现这类错误呢’
 * 
 */

#define IN 1	/* inside a word */
#define OUT 0	/* outside a word */

/* count lines, words, and characters in input */
int main()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc =0;
    while ((c = getchar())	!= EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
    system("pause");
    return 0;
}