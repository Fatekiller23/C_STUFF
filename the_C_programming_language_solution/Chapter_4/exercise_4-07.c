/*
Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch?

我觉得应该自己对buf 和 bufp 直接操作，如果用了ungetch，程序就不分离了。嵌套不舒服。

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
    /* code */
    ungets("abcd");
    printf("%c%c%c%c \n", getch(),getch(),getch(),getch());
    printf("the result should be abcd \n");
    return 0;
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

void ungets(char s[]) {
    int i=0;
    while (s[i] != '\0') {
        if (bufp >= BUFSIZE) {
            printf("ungetch: too many characters\n");
            break;
        }
        buf[bufp++] = s[i++];

    }
}