/*
Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in
Appendix B, Section 4.

*/


/*

Exercise 4-4. Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack.

thinking:
! ------------ show
@ ------------ duplicate
# ------------ swap
$ ------------ clear
*/



#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define NAME '1' /* signal that a function name was found */

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int sp = 0; /* stack position */
double val[MAXOP];

int getop(char []);
void push(double);
double pop();
int getch(void);
void ungetch(int);
void debug(int d);

void duplicate(void);
void show(void);
void swap(void);
void clear(void);
void use_function(char []);


int main() {
    int type;
    char s[MAXOP];
    double op2;
    while(type = getop(s)){
        switch (type) {
            case NAME:
                use_function(s);
                break;

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

            case '!':
                show();
                break;

            case '@':
                duplicate();
                break;

            case '#':
                swap();
                break;

            case '$':
                clear();

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

    if (isalpha(c)) {
        int i=0;
        while(isalpha(s[++i] = c = getch()))
            ;
        ungetch(c);
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


void duplicate(void) {
    double temp = pop();
    push(temp);
    push(temp);
}
void show(void) {
    //show function.
    if (sp > 0)
    printf("show top elements in stack:    %.8g\n", val[sp-1]);
    else
        printf("the stack is empty! \n");
}
void swap(void) {
    double temp1 = pop();
    double temp2 = pop();
    push(temp1);
    push(temp2);
}
void clear(void) {
    sp=0;
}

void use_function(char s[]) {
    double op2;
    if (strcmp(s,"sin") == 0){
        //use sin
        push(sin(pop()));
    }
    if (strcmp(s, "cos") == 0){
        // use cos
        push(cos(pop()));
    }
    if (strcmp(s, "exp") == 0){
        // use exp
        push(exp(pop()));
    }
    if (strcmp(s,"pow") == 0){
        // use pow
        op2 = pop();
        push(pow(pop(), op2));
    }

}
