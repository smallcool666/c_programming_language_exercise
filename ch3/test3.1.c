#include <stdio.h>
#include <windows.h>

/**
 * 练习3-1 在上面有关折半查找的例子中，while循环语句内共执行了两次测试，其实 只要一次就足够（代价是将更多的测试在
 * 循环外执行)。重写该函数，使得在循环内部只执行 一次测试。比较两种版本函数的运行时间。
 */

int main()
{
    system("pause");
    return 0;
}

//只是循环里的判断短了，并没有优化到性能，代码量更多了
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n -1;
    mid = (low+high)/2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid])
            high = mid + 1;
        else
            low = mid + 1;
        mid = (low+high)/2;
    }
    if (x == v[mid]) {
        return mid;
    }
    return -1;	/* no match */
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1]	*/
int binsearchOld(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n -1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1;	/* no match */
}