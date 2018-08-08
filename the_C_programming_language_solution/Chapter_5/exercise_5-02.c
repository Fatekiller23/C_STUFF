/*
Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does
getfloat return as its function value?

我认为还是应该是整形，因为其表示一个状态量。

*/

#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100
static char buf[BUFSIZE]; /* buffer for ungetch */
static int bufp = 0; /* next free position in buf */
#define SIZE 100

int getch(void);
void ungetch(int);
int getfloat(double *);

int main(int argc, char const *argv[])
{
    double some;
    getfloat(&some);
    printf("the result should be %g.", some);
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

int getfloat(double *p) {
    int c, b, sign;
    double temp;
    while((c=getch()) == ' ')
        ;

    if (!isdigit(c) && c != '-' && c != '+' && c != EOF && c != '.') {
        // not a number.
        ungetch(c);
        return 0;
    }
    sign = (c=='-')? -1:1;

    if (c == '+' || c =='-') {
        b = c;
        c = getch();
        if (!isdigit(c)) {
            // not a number
            ungetch(b);
            return 0;
        }
    }
    
    *p=c-'0';
    int xiaoshu=0;
    int counter=0;
    while(c=getch()) {
        if (xiaoshu == 1) {
            counter++;
        }
        if(isdigit(c)) {
            *p=10 * *p + (c-'0');

        }
        
        else if (c=='.')
        {
            xiaoshu=1;
        }
        else
            break;
    }
    if (counter != 0) {
        for(int j=0;j<counter-1;j++)
            *p = *p / (float)10;
    }
    *p = *p * sign;
    if (c != EOF){
        ungetch(c);
    }
    // positive value.
    return c;
}