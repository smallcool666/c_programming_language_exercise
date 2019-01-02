#include <stdio.h>
#include <Windows.h>
/**
 *  练习1-23 编写一个删除C语言程序中所有的注释语句。要正确处理带引号的字符串与字符常量。在C语言中，注释不允许嵌套。
 * 
 * 简单分析：要识别三种开始符号：/*,//,"
 * 对于/*，直到遇到*\/符号才会结束，中间的任何内容都会丢弃
 * 对于//，直到遇到换行符，中间的内容全部丢弃
 * 对于",在遇到另一个非转义"之前，中间的/*,//两种符号不分析
 * 优先级：/*和"，谁先出现谁优先，都优先//
 */
#define MAXLINE 5000 //最多接收5000字符的输入

int main()
{
    char c, line[MAXLINE], last_char;
    //三个标记，qutation标记当前是否在双引号中，mline标记是否在多行注释中，sline标记是否在单行注释中
    int qutation, mline, sline, len;
    qutation = mline = sline = len = 0;
    while ((c = getchar()) != EOF) {
        line[len] = c;
        if (len - 1 >= 0) {
            //如果当前没有在字符串或注释中，判断一下是不是快进入某个状态了
            if (!mline && !sline && !qutation) {
                if (!len && c == '"') {
                    qutation = 1;
                }
                //进入字符串
                if (c == '"' && line[len - 1] != '\\') {
                    qutation = 1;
                }
                //进入多行注释
                if (c == '*' && line[len - 1] == '/') {
                    mline = 1;
                    //多行注释的话注释符号也不打印
                    len -= 2;
                }
                // 进入单行注释
                if (c == '/' && line[len - 1] == '/') {
                    sline = 1;
                    len -= 2;
                }
            } else {
                if (qutation == 1) {
                    //字符串内的内容正常打印
                    if (c == '"' && line[len -1] != '\\') {
                        qutation = 0;
                    }
                }
                if (mline == 1) {
                    if (c == '/' && last_char == '*') {
                        mline = 0;
                    }
                    last_char = c;
                    len--;
                }
                if (sline == 1) {
                    if (c == '\n') {
                        sline = 0;
                    }
                    len--;
                }
            }
        }
        len++;
    }
    line[len] = '\0';
    printf("\n---%s---\n", line);
    system("pause");
    return 0;
}