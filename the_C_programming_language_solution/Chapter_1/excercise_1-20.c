/*
Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?

编写程序 detab，将输入中的制表符替换成适当数目的空格，使空格充满到
下一个制表符终止位的地方。假设制表符终止位的位置是固定的，比如每隔 n 列就会出现一
个制表符终止位。n 应该作为变量还是符号常量呢？
*/

/*
下面的程序确实把制表符换成了相应的空格，这里是对一串输入进行循环的单字符处理。
如果是每隔n列出现一个制表符中止位，那么n应该作为一个符号常量。

*/
#define MAXLEN 100
#define SPACE 8
#include <stdio.h>

int main() {
    int c, last=0;    // last 用来记录上一个字符是否是\t, 如果是，就不重复输出空格了。
    char result[MAXLEN];
    int i = 0;
    while ( (c=getchar()) != EOF ){
        if (c != '\t'){
            result[i] = c;
            ++i;
            last = 0;
        }
        else {
            if (last == 0){
                for (int j=0;j<SPACE;++j)
                {
                    result[i] = ' ';
                    ++i;
                }
                last = 1;
            }
        }
    }
    printf("%s", result);
    return 0;
}