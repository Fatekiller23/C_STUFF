#include <stdio.h>
#define BUFSIZE 100
static char buf[BUFSIZE]; /* buffer for ungetch */
static int bufp = 0; /* next free position in buf */
double last;


int getch(void) {
    int i;
    // i = (buf > 0) ? buf[--bufp] : getchar();
    return (bufp > 0) ? buf[--bufp] : getchar();
    // return i;
}

void ungetch(int c) 
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    }
    else
        buf[bufp++] = c;
}
