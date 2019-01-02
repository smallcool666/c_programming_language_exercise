#include <stdio.h>
#include <windows.h>

/**
 * 练习1-6	验证表达式getchar()!= EOF的值是0还是1。
 * 
 * 输入非Ctrl+c组合时，表达式值为1,输入Ctrl+c表示输入结束时，表达式值为0
 */

int main()
{
    char c;
    while((c = getchar()) != EOF) {
        printf("%d\n", c!=EOF);
    }
    printf("%d\n", c!=EOF);
    system("pause");
}