#include <stdio.h>
#include <windows.h>

/**
 * 练习2-8 编写一个函数 rightrot(x, n)，该函数返回将x循环右移（即从最右端 移出的位将从最左端移入）n(二进制）位后所
 * 得到的值。
 */

int rightrot(int x, int n);

int main()
{
    //256 = 10000000, 结果应该为10001100 = 268
    printf("%d, %d\n", 256, rightrot(256, 3));
    system("pause");
    return 0;
}

int rightrot(int x, int n)
{
    int i, len, y = x;
    //得到x的二进制数的位数
    for (len = 0; y != 0; len++) {
        y = y / 2;
    }

    int tmp1, tmp2;
    for (i = 0; i < n; i++) {
        // x = (x >> 1) | ((x & 1) << len) 加法改成按位或也是一样的效果
        // << 比 + 优先级低，如果用加法的话，需要加括号
        x = (x >> 1) + ((x & 1) << len);
    }
    return x;
}