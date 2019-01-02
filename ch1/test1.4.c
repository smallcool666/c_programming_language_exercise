#include <stdio.h>
#include <windows.h>

/**
 * 练习1-4	编写一个程序打印摄氏温度转换为相应华氏温度的转换表。
 */

int main()
{
    float fahr, celsius;
    float lower = -100.0, upper = 100.0, step = 20.0;

    printf("%8s\t%8s\n", "celsius", "fahr");
    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius * 9.0 / 5.0 + 32;
        printf("%8.2f\t%8.2f\n", celsius, fahr);
        celsius = celsius + step;
    }
    system("pause");
}