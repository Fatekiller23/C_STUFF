/*
Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function
for conversion.
*/


#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */


void print_celsius_table(int lower, int upper, int step);

int main()
{
  
    int lower, upper, step;
    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    print_celsius_table(lower, upper, step);
    return 0;
}

void print_celsius_table(int lower, int upper, int step) {
        int fahr, celsius;
        while (fahr <= upper) {
            celsius = 5 * (fahr-32) / 9;
            printf("%d\t%d\n", fahr, celsius);
            fahr = fahr + step;
        }
}