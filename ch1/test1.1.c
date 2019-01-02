#include "stdio.h"
#include <windows.h>
/**
 * 练习1-1 在你自己的系统中运行“ hello, world”程序。再有意去掉程序中的部分内容，看看会得到什么出错信息。
 */

int main()
{
    printf("hello world\n");
    system("pause");
    return 0;
}