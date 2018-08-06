#include <stdio.h>
#include "cal.h"
#define MAXVAL 100
static int sp = 0; /* stack position */
static double val[MAXVAL];


/* push: push f onto value stack */
void push(double f) {

    if (sp < MAXVAL)
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