/*
Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
the modulus (%) operator and provisions for negative numbers.


soulution:
    % for fmod function in math.h
    negative number case is based on the presumption that - is followed by number.
    use if clause ramify the condition.
*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int sp = 0;
double val[MAXOP];

int getop(char []);
void push(double);
double pop();
int getch(void);
void ungetch(int);
void debug(int d);

int main() {
    int type;
    char s[MAXOP];
    double op2;
    while(type = getop(s)){
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                }
                else {
                    printf("zero divisor error!\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    push( fmod(pop(), op2));
                }
                else {
                    printf("zero divisor error!\n");
                }
                break;
            case '\n':
                 printf("result: \t%.8g\n", pop());
                 break;
        }
    }
    return 0;
}

/* push: push f onto value stack */
void push(double f) {

    if (sp < MAXOP)
        val[sp++] = f;
    else
        printf("error: stack is full, can't push %g\n", f);   

}

/* pop: pop and return top value from stack */
double pop() {
    if (sp == -1) {
        printf("error: stack is null, can't pop\n");
        return 0.0;
    }
    else
        return val[--sp];
}

int getop(char s[]) {
    int i, c, neg;
    while ( (s[0] = c = getch()) == ' ' || c == '\t')
    ;
    s[1] = '\0';
    

    if (!isdigit(c) && c != '.' && c !='-'){
        // putchar(c);
        return c;
    }
    
    else if (c=='-' &&   isdigit(c=getch()) )
    {
        // this is a negative number
        ungetch(c);
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
    ungetch(c);
    
    return NUMBER;    // signal that a number is found.
}


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

void debug(int d) {
    printf("running here! value is  %d \n", d);
}