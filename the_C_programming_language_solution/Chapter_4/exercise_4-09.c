/*
Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
what their properties ought to be if an EOF is pushed back, then implement your design.

解答是这样的
The reason why the code in K&R can't handle EOF is because it is defined as follows:
#define EOF -1
i.e. its value is negative and a char array can't hold a negative value.
Change the buffer type to int and the problem is solved. 

但是经过我的测试，我发现char 可以有-1的表示。
所以这道题就。。。。罢了罢了就这样吧

*/


#include <stdio.h>


#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void);
void ungetch(int);
void ungets(char []);

int main()
{
    buf[0] = EOF;
    printf("%d", buf[0]);
}

int getch(void) {
    int i;
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) 
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    }
    else
        buf[bufp++] = c;
}