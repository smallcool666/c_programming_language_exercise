#include <stdio.h>
#include <windows.h>

/**
 * 练习1-15 重新编写1.2节中的温度转换程序，使用函数实现温度转换计算。
 */

float ftoc(float fahr);

int main()
{
    float fahr, celsius;
    float lower = 0.0, upper = 300.0, step = 40.0;

    printf("%8s\t%8s\n", "fahr", "celsius");
    fahr = lower;
    while (fahr <= upper) {
        printf("%8.2f\t%8.2f\n", fahr, ftoc(fahr));
        fahr = fahr + step;
    }
    system("pause");
    return 0;
}

float ftoc(float fahr)
{
    return 5 * (fahr - 32) / 9;
}