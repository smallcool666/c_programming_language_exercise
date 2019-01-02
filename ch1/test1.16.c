#include <stdio.h>
#include <Windows.h>
/**
 *  练习1-16	修改打印最长文本行的程序的主程序main使之可以打印任意长度的输入行的长度，并尽可能多地打印文本。
 * 
 * 分析：要求能打印行的长度，打印尽量多的字符
 */
#define MAXLINE 1000	/* maximum input line length */

int getline (char line[] , int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len;	/* current line length */
    int max;	/* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;
    while ((len = getline (line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)	/* there was a line */
        printf("%s", longest);
    system("pause");
    return 0;
}

/* getline: read a line into s, return length */
int getline (char s[],int lim)
{
    int c, i;
    //去掉i < lim-1的判断，保证i可以保存行的长度
    for (i=0; (c=getchar ()) !=EOF && c != '\n'; ++i) {
        //添加判断，确保不会数组溢出
        if (i < lim - 1) {
            s[i] = c;
        }
    }
    
    //如果溢出了，最后两个位置放回车符和\0，否则还是原来数组够用的逻辑
    if (i <= lim -2) {
        s[lim - 1] = '\0';
        s[lim - 2] = '\n';
    } else {
        if (c == '\n') {
            s[i] = c;
            ++i;
        }
        s[i]= '\0'; 
    }
    
    return i;
}
/* copy: copy from, into ,to,; assume to is big enough */
void copy(char to[], char from[])
{
    int i; i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}