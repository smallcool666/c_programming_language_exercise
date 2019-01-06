#include <stdio.h>
#include <windows.h>

/**
 * 练习4-14 定义宏swap(t, x, y)以交换t类型的两个参数。（使用程序块结构会对 你有所帮助。）
 *      
 */

#define swap(t, x, y)   { t tmp;\
    tmp = x;\
    x = y;\
    y = tmp;}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    swap("int", a, b);
    printf("after swap:%d %d\n", a, b);
    system("pause");
    return 0;
}