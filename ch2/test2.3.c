#include <stdio.h>
#include <windows.h>

/**
 * 练习2-3 编写函数htoi(s)，把由十六进制数字组成的字符串（包含可选的前缀0x 或0X)转换为与之等价的整型值。字符串中
 * 允许包含的数字包括： 0〜9、a〜f以及A〜F。
 * 
 */
#define MAXLINE 1000	/* maximum input line length */

int main()
{
    int len = 0, res = 0, i;
    char c, line[MAXLINE];
   while ((c = getchar()) != EOF) {
       if(c >= '0' && c <= '9' || c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F' || c == 'X' || c == 'x') {
           if (c == 'x' || c == 'X') {
               if (len - 1 < 0 || line[len - 1] != '0') {
                   continue;
               }
           }
           line[len++] = c;
       } else {
           if (line[0] != '0' || line[1] != 'x' && line[1] != 'X' || len <= 2) {
               printf("nil\n");
           } else {
               int base = 1, num = 0;
               for (i = len - 1; i > 1; i--) {
                   if (line[i] >= '0' && line[i] <= '9') {
                       num = line[i] - '0';
                   } else if (line[i] >= 'a' && line[i] <= 'f') {
                       num = line[i] - 'a' + 10;
                   } else if (line[i] >= 'A' && line[i] <= 'F') {
                       num = line[i] - 'A' + 10;
                   } else {
                       continue;
                   }
                   res += base * num;
                   base *= 16;
               }
               line[len] = '\0';
               printf("\n%s = %d\n", line, res);
               len = res = 0;
           }
       }
   }
    system("pause");
    return 0;
}