#include <stdio.h>

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void);

int main()
{
    int c;
    
    printf("%d", 5%0);
    return 0;
}



int getch(void) {
    int i;
    // i = (buf > 0) ? buf[--bufp] : getchar();
    return (buf > 0) ? buf[--bufp] : getchar();
    // return i;
}