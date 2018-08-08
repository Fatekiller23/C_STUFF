/*

Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input.

*/


#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100
static char buf[BUFSIZE]; /* buffer for ungetch */
static int bufp = 0; /* next free position in buf */
#define SIZE 100

int getch(void);
void ungetch(int);
int getint(int *);

int main(int argc, char const *argv[])
{
    int n, array[SIZE], getint(int *);
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;
    for (int i=0; i<20; i++)
        printf("%d | ", array[i]);
    return 0;
}

int getch(void) {
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

int getint(int *pn) {
    int c, b, sign;
    while((c=getch()) == ' ')
        ;
    if (!isdigit(c) && c != '-' && c != '+' && c != EOF) {
        // not a number.
        ungetch(c);
        return 0;
    }

    sign = (c=='-')? -1:1;

    if (c == '+' || c =='-') {
        b = c;
        c = getch();
        if (!isdigit(c)) {
            ungetch(b);
            return 0;
        }
    }


    for (*pn=0;isdigit(c);c=getch())
        *pn=10 * *pn + (c-'0');

    *pn = *pn * sign;

    // 如果此时c 不是eof，并且还是多读了的有效输入，那就理应把它塞回去。
    // 虽然我觉得这种情况应该不会发生。
    if (c != EOF){
        ungetch(c);
    }
    return c;
}

