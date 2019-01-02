#include <stdio.h>
#include <windows.h>

/**
 * 练习2-9	在求对二的补码时，表达式x&=(x - 1)可以删除x中最右边值为1的一个二进制位。请解释这样做的道理。
 * 用这一方法重写bitcount函数，以加快其执行速度。
 */

int bitcount(int x);

int main()
{
    //256 = 10000000, 结果应该为10001100 = 268
    printf("%d, %d\n", 256, bitcount(256));
    system("pause");
    return 0;
}

int bitcount(int x)
{
    int num = 1;
    while ((x = x & (x - 1)) != 0) {
        num++;
    }
    return num;
}