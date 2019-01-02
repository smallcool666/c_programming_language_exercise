#include <stdio.h>
#include <windows.h>
#include <limits.h>

/**
 * 练习2-1 编写一个程序以确定分别由signed及unsigned限定的char、short、 int与long类型变量的取值范围。采用打印标准头
 * 文件中的相应值以及直接计算两种方式实 现。后一种方法的实现较困难一些，因为要确定各种浮点类型的取值范围。
 */
#define MAXLINE 1000	/* maximum input line length */

int main()
{
    /**
     * ANSI C标准规定：各种类型的取值范围必须在头文件#include <limits.h>中定义。
     */
    printf("signed char min = %d\n", SCHAR_MIN);
    printf("signed char max = %d\n", SCHAR_MAX);
    printf("unsigned char max = %u\n", UCHAR_MAX);
    printf("signed int min = %d\n", INT_MIN);
    printf("signed int max = %d\n", INT_MAX);
    printf("unsigned int max = %d\n", UINT_MAX);
    printf("signed short min = %d\n", SHRT_MIN);
    printf("signed short max = %d\n", SHRT_MAX);
    printf("unsigned short max = %d\n", USHRT_MAX);
    printf("signed long min = %d\n", LONG_MIN);
    printf("signed long max = %d\n", LONG_MAX);
    printf("unsigned long max = %d\n", ULONG_MAX);

    printf("\n--------\n");
    /**
     * ~0把0每一位都置位1
     * (unsigned char)~0把~0的结果转为无符号字符型
     * (unsigned char)~0 >> 1，右移一位去掉符号位
     * (char)((unsigned char)~0 >> 1)，转换成需要的类型
     */
    printf("signed char min = %d\n", ~(char)((unsigned char)~0 >> 1));
    printf("signed char max = %d\n", (char)((unsigned char)~0 >> 1));
    printf("unsigned char max = %u\n", (unsigned char)~0);
    printf("signed int min = %d\n", ~(int)((unsigned int)~0 >> 1));
    printf("signed int max = %d\n", (int)((unsigned int)~0 >> 1));
    printf("unsigned int max = %d\n", (unsigned int)~0);
    printf("signed short min = %d\n",  ~(short)((unsigned short)~0 >> 1));
    printf("signed short max = %d\n", (short)((unsigned short)~0 >> 1));
    printf("unsigned short max = %d\n", (unsigned short)~0);
    printf("signed long min = %d\n", ~(long)((unsigned long)~0 >> 1));
    printf("signed long max = %d\n", (long)((unsigned long)~0 >> 1));
    printf("unsigned long max = %d\n", (unsigned long)~0);
    system("pause");
    return 0;
}