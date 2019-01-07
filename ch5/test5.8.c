#include <stdio.h>
#include <windows.h>

/**
 *练习5-8	函数day_of_year和month_day中没有进行错误检查，请解决该问题。
 *
 * 思路：
 *   检查包括：
 *      1.月份数据在1-12之间
 *      2.一年天数不超过365
 *      3. 没有负数
 *      4. 每月天数最多31
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
    if (year < 0) {
        printf("invalid year\n");
        return 0;
    }
    if (month < 1 || month > 12) {
        printf("invalid month\n");
        return 0;
    }
    if (day < 1 || day > 31) {
        printf("invalid day\n");
        return 0;
    }
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;

}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return ;
    }
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    if (i > 12 && yearday > daytab[leap][i]) {
        *pmonth = -1;
        *pday = -1;
        return ;
    }
    *pmonth = i;
}