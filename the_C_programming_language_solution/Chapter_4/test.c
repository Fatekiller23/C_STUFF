#include <stdio.h>

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void);
void printd(int n);

int main()
{
    int c;
    static a; // static is default initialize to 0.
    printf("%d", a);    
    char pattern[] = "abcde";
    printf("%s", pattern);


    int cc[8] = {0,1,2,3,4,5}; // no initializer default to be 0.
    for (int i=0;i<8;i++)
        printf("%d,", cc[i]);

    printd(5638);
    return 0;
}



int getch(void) {
    int i;
    // i = (buf > 0) ? buf[--bufp] : getchar();
    return (buf > 0) ? buf[--bufp] : getchar();
    // return i;
}

void printd(int n) {
    // print a decimal to string. recursion style.
    if (n<0) {
        putchar('-');
        n = -n;
    }
    if(n/10) {
        printd(n/10);
    }
    putchar(n%10 + '0');
}