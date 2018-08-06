/*
Exercise 4-6. Add commands for handling variables. (It's easy to provide twenty-six variables
with single-letter names.) Add a variable for the most recently printed value.

*/


#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include "cal.h"
#include <math.h>
#include <string.h>
#define MAXOP 100 /* max size of operand or operator */


extern double last;


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

            case '\n':
                last = pop();
                printf("result: \t%.8g\n", last);
                break;
        }
    }
    return 0;
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

    if (strcmp(s,"last") == 0){
        // use pow
        printf("last result:   %.8g\n", last);
        getch(); // consume the extra newline character.
    }

}
