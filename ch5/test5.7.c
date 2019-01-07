#include <stdio.h>
#include <windows.h>

/**
 * 练习5-7	重写函数readlines将输入的文本行存储到由main函数提供的一个数组中，而不是存储到调用alloc分配的存储空间中。该函数的运行速度比改写前快多少？
 * 
 */
#define MAXCHAR 10000 //最多存储的字符数

int main()
{
    system("pause");
    return 0;
}

#define MAXLEN 1000	/* max length of any input line */
/* readlines: read input lines */
int readlinesold(char *lineptr [], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;   
        } else {
            line[len-1] = '\0';	/* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

int readlines(char *lineptr [], char *arr, int maxlines)
{
    int len, nlines;
    char *p = arr, line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        //如果行数超限或者字符数超限，就报错
        if (nlines >= maxlines || p + len > arr + MAXCHAR) {
            return -1;   
        } else {
            line[len-1] = '\0';	/* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}