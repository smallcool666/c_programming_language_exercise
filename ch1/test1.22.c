#include <stdio.h>
#include <Windows.h>
/**
 *  练习1-22 编写一个程序，把较长的输入行“折”成短一些的两行或多行，折行的位置在输入行的第n列之前的最后一个非空格
 * 之后。要保证程序能够智能地处理输入行很长以及在指定的列前没有空格或制表符时的情况。
 */
#define MAXLINE 1000	/* maximum input line length */

int main()
{
    //设置n的长度是10，也可以通过输入指定
    int len = 0, blank_pos = 0, n = 10;
    char c, line[MAXLINE];
    while ((c = getchar()) != EOF) {
        //达到指定折行长度时输出内容
        if (len >= n || c == '\n') {
            //过滤空行
            if (len) {
                //把字符串结尾定位到非空字符后面
                line[blank_pos + 1] = '\0';
                //多输出一个---用于定位字符串结束
                printf("%s---\n", line);
                //数据清零，开始下一行的循环
                len = blank_pos = 0;
            }
            continue;
        }
        //如果不是空格，更新一下最近的空格位置
        if (c != ' ' && c != '\t') {
            blank_pos = len;
        }
        line[len++] = c;
    }
    system("pause");
    return 0;
}