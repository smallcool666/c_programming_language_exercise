#include <ctype.h>
#include <string.h>

/**
 * 练习4-9 以上介绍的getch与ungetch函数不能正确地处理压回的EOF。考虑压回 EOF时应该如何处理？请实现你的设计方案。
 * 
 * 思路：
 *      char buf[BUFSIZE];
 *      原来的处理中缓存数组是字符数组，而EOF的值为-1，所以把缓存数组转换成整形数组即可，在使用时作为字符处理
 *  
 */