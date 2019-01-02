#include <stdio.h>
#include <windows.h>

/**
 * 练习3-3 编写函数expand(s1, s2)，将字符串si中类似于a-z —类的速记符号在字符串s2中扩展为等价的完整列表abc...xyz。
 * 该函数可以处理大小写字母和数字，并可 以处理a-b-c、a-zO-9与-a-z等类似的情况。作为前导和尾随的-字符原样排印。
 * 
 * 思路：
 * 1. 没有找到起始字符时，第一个-就是前导
 * 2. 第一个找到的字符就是起始符号
 * 3. 第二个找到的字符可能是中间字符或者结束字符
 *  3.1如果第二个字符后面是一个‘-’和另一个字符，说明第二个字符是中间字符，跳过这一个，继续找结束字符
 */

#define MAXLINE 1000
int isletterordigit(char c);
void expand(char s1[], char s2[]);

int main()
{
    char s1[MAXLINE], s2[MAXLINE], c;
    int i = 0;
    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            s1[i++] = c;
        } else {
            s1[i] = '\0';
            expand(s1, s2);
            printf("%s => \n%s\n", s1, s2);
            //清空数据，重新开始
            s2[0] = '\0';
            i = 0;
            s1[0] = '\0';
        }
        
    }
    system("pause");
    return 0;
}

void expand(char s1[], char s2[])
{
    char start, end, c;
    int i, j, hassuffix;
    i = j = hassuffix = 0;
    start = end = '\0'; //设初值为null
    for (i = 0; s1[i] != '\0'; i++) {
        //如果是前导的-，直接输出
        if (s1[i] == '-' && start == '\0') {
            s2[j++] = s1[i];
            continue;
        }
        //字母或者数字就是起始字符、结束字符、中间字符三者之一
        if (isletterordigit(s1[i])) {
            if (start == '\0') {
                start = s1[i];
            } else if (end == '\0') {
                //如果第二个字母数字后面还是-，说明是后缀或者这个字符是中间字符，判断一下
                if (s1[i + 1] == '-') {
                    //第二个-后面还有字符，说明第二个字符时中间字符，跳过
                    if (isletterordigit(s1[i + 2])) {
                        i++;
                    } else {
                        // 有-后缀
                        hassuffix = 1;
                        end = s1[i];
                        i++;
                    }
                } else {
                    end = s1[i];
                }
            }
        }

        if (start != '\0' && end != '\0') {
            while (start <= end) {
                s2[j++] = start;
                start++;
            }
            if (hassuffix) {
                s2[j++] = '-';
            }
            start = end = '\0';
            hassuffix = 0;
        }
    }
    s2[j] = '\0';
}

int isletterordigit(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}