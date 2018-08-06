/*
xercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint: use an internal
static variable.

解法：
    运行环境在calculator的文件夹中。
    停了四个月没写程序，这道题终于感觉状态回来了。

    思路就是声明一个静态变量， 用来存多读了的c。
    c如果是空格，就替掉。
    如果不是，直接进入原程序流。
*/










#include "cal.h"
#include <stdio.h>
#include <ctype.h>

int getop(char s[]) {
    int i, c, neg;
    static int extra=0;

    if (extra != 0) {
        c = extra;
        if (c == ' ' || c == '\t') {
               while ( (s[0] = c = getch()) == ' ' || c == '\t')
                    ;
                s[1] = '\0';
        }
        
    }
    else {
            while ( (s[0] = c = getch()) == ' ' || c == '\t')
                ;
                s[1] = '\0';
    }




    if (isalpha(c)) {
        int i=0;
        while(isalpha(s[++i] = c = getch()))
            ;
        extra = c;
        s[i] = '\0';
        return NAME;
    }

    if (!isdigit(c) && c != '.' && c !='-'){
        // putchar(c);
        return c;
    }
    
    else if (c=='-' &&   isdigit(c=getch()) )
    {
        // this is a negative number
        extra = c;
        neg=1;
    }
    else if (c == '-') {
        return c;
    }
    i=0;
    if (isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';

    if (c != EOF)
    extra = c;
    
    return NUMBER;    // signal that a number is found.
}
