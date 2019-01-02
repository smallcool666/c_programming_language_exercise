#include <stdio.h>
#include <windows.h>

/**
 * 练习1-3	修改温度转换程序，使之能在转换表的顶部打印一个标题。
 */

int main()
{
    float fahr, celsius;
    float lower = 0.0, upper = 300.0, step = 40.0;

    printf("%8s\t%8s\n", "fahr", "celsius");
    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%8.2f\t%8.2f\n", fahr, celsius);
        fahr = fahr + step;
    }
    system("pause");
}