#include <stdio.h>
#include <windows.h>

/**
 *练习5-9 用指针方式代替数组下标方式改写函数day_of_year和month_day。
 *
 * 思路：
 *      修改获取二位数组元素的方式
 */
#define MAXCHAR 10000 //最多存储的字符数

int main()
{
    system("pause");
    return 0;
}

static char daytab[2][13] = {
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap, *p;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = daytab[leap];
    while (month--)
        day += *p++;
    return day;

}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap, *prt;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    prt = daytab[leap];
    for (i = 1; yearday > *(prt + i); i++)
        yearday -= *(prt + i);
    *pmonth = i;
}