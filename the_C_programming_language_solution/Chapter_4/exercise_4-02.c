/*
Exercise 4-2. Extend atof to handle scientific notation of the form
*/

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main() {
    char testdata[300]="123.45e+2";
    // char testdata[300]="123.45E2";
    double res;
    res = atof(testdata);    
    printf("the result of 123.45e+2 should be 12345.000000 ------------> %f", res);
    return 0;
}



/* atof: convert string s to double */
double atof(char s[]) {
    double val, power;
    int i, sign, exponent, ex_sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
                ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
                i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e' || s[i] == 'E'){
        i++;
        ex_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
                    i++;    
        for (exponent = 0; isdigit(s[i]); i++)
            exponent = 10 * exponent + (s[i] - '0');
    
        if (ex_sign+1) {
            for (int i=0;i<exponent;i++)
                power /= 10;
        }
        else {
            for (int i=0;i<exponent;i++)
                power *= 10;            
        }
    }

    return sign * val / power;
}