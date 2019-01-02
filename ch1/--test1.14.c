#include <stdio.h>
#include <windows.h>
#include <conio.h>

/**
 * 练习1-14 编写一个程序，打印输入中各个字符出现频度的直方图。
 */

void horizontal(int *arr, int len);
void vertical(int *arr, int len);

/* count lines, words, and characters in input */
int main()
{
    int i, c, arr[256] = {0};
    while ((c = getchar()) != EOF) {
        if (c >= 0 && c <= 255) {
            arr[c]++;
        }
    }
    for (i = 0; i < 256; i++) {
        // printf("arr[%d] = %d\n", i, arr[i]);
        // if (arr[i]) {
        //     printf("arr[%d] = %d\n", i, arr[i]);
        // }
        printf("%d\n", i);
    }
    printf("---------%d\n", i);
    horizontal(arr, 256);
    vertical(arr, 256);
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
    printf("\n垂直直方图\n");
    for (i = len - 1; i >= 0; i--) {
        for (j =0; j < len; j++) {
            if (!arr[j]) {
                continue;
            }
            if (arr[j] >= i) {
                printf(" * ");
            }
        }
        printf("\n");
    }
    for (i = 0; i < len; i++) {
        if (arr[i]) {
            printf("%3d", arr[i]);
        }
    }
    printf("\n");
}