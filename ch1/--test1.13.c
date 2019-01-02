#include <stdio.h>
#include <windows.h>
#include <conio.h>

/**
 * 练习1-13 编写一个程序，打印输入中单词长度的直方图。水平方向的直方图比较容易 绘制，垂直方向的直方图则要困难些。
 */

#define IN 1	/* inside a word */
#define OUT 0	/* outside a word */

void horizontal(int *arr, int len);
void vertical(int *arr, int len);

/* count lines, words, and characters in input */
int main()
{
    int c, state, len = 0, arr[10] = {0}, i;

    state = OUT;
    while ((c = getchar())	!= EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                arr[len]++;
                len = 0;
                state = OUT;
            }
        } else {
            state = IN;
            len++;
        }
    }
  
    horizontal(arr, 10);
    vertical(arr, 10);
    system("pause");
    return 0;
}
void horizontal(int *arr, int len)
{    
    int i, j;
    printf("\n水平直方图\n");
    for (i = 0; i < len; i++) {
        if (arr[i]) {
            printf("%3d  ", i);
            for (j = 0; j < arr[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
}

void vertical(int *arr, int len)
{
    int i, j;
        for (i = 0; i < 10; i++) {
        if (arr[i]) {
            printf("arr[%d] = %d\n", i, arr[i]);
        }
    }  
    int flag;
    printf("\nvertical 垂直直方图\n");
    for (i = len - 1; i >= 0; i--) {
        flag = 0;
        for (j = 1; j < len; j++) {
            if (arr[j] >= i) {
                flag = 1;
                printf(" * ");
            }
        }
        if (flag == 1) {
            printf("\n");
        }
    }
    if (!flag) {
        printf("\n");
    }
    for (i = 0; i < len; i++) {
        if (arr[i]) {
            printf("%3d", arr[i]);
        }
    }
    printf("\n");
}