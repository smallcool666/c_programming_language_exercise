#include <stdio.h>
#include <windows.h>

/**
 * 练习1-5	修改温度转换程序，要求以逆序（即按照从300度到0度的顺序）打印温度转换表。
 */

int main()
{
    float fahr, celsius;
    float lower = 0.0, upper = 300.0, step = 40.0;

    printf("%8s\t%8s\n", "fahr", "celsius");    
    for (fahr = upper; fahr >= lower; fahr -= step) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%8.2f\t%8.2f\n", fahr, celsius);        
    }
    system("pause");
}