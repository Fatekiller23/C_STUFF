/*
Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument. For example,
        expr 2 3 4 + *
evaluates 2 * (3+4).

这道题方显我牛逼本色。
从思路到结果，就是闭着眼睛敲。
然后没有debug过，脑袋里面通了，然后现实一下就通了。
哈哈哈哈，心中有剑，手中就有剑。
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> /* for atof() */
#define BUFSIZE 100
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int sp = 0;
double val[MAXOP];
double pop();
void push(double f);
int getop(char s[]);

int main(int argc, char *argv[])
{
    /* code */
    int type;
    while(*argv != NULL) {
        type = getop(*argv);
        double op2;
        switch(type) {
            case NUMBER:
                push(atof(*argv));
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
        }
        argv++;
    }
    printf("result: \t%.8g\n", pop());
    return 0;
}


int getop(char s[]) {
    int i=0;
    int c;
    int neg;
    while ( s[i] == ' ' || s[i] == '\t') {
        i++;
    }
    c = s[i];
    if (!isdigit(c) && c != '.' && c !='-'){
        // putchar(c);
        return c;
    }
    
    else if (c=='-' &&   isdigit(s[i+1]))
    {
        // this is a negative number
        neg=1;
    }
    else if (c == '-') {
        return c;
    }

    return NUMBER;    // signal that a number is found.
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