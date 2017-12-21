/*
Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table.
*/

#include <stdio.h>
/* print Celsius-Fahrenheit table
for celsius = 0, 20, ..., 300; floating-point version */
main() {
    float fahr, celsius;
    float lower, upper, step;
    lower = 0; /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    celsius = lower;
    printf(" __________________\n");
    printf("| celsius |  fahr  |\n");
    printf("^^^^^^^^^^^^^^^^^^^^\n");
    while (celsius <= upper) {
        fahr = (celsius+32.0) * (9.0/5.0);
        printf("%4.0f      |%8.2f\n", celsius, fahr );
        celsius = celsius + step;
    }
}