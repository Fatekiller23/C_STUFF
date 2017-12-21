/*
Exercise 1-1. Run the ``hello, world'' program on your system. Experiment with leaving
out parts of the program, to see what error messages you get.

solution:
    the compiler will warn about unknown escape sequence: '\w'.
    but the program can be compiled completely. and prints 'w' character if excape sequence
    is '\w'.
*/


#include <stdio.h>
void main()
{
    printf("\w");
    // return 0;
}