/*
Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.

solution:
    watch out! As the book said, the number of bits of which type used is depended on your machine
    implementations, cause each complier is free to choose appropraite sizes for its own hardware.
    
    signed int: 32 bit   range: - 2**31 ~ 2**31-1
    unsigned int: 32 bit   range: 0 ~ (2**32 - 1)

    signed short: 16 bit   range: - 2**15 ~ 2**15-1   
    unsigned short: 16 bit    range: 0 ~ (2**16 -1)

    signed long: 32 bit   range: - 2**31 ~ 2**31-1
    unsigned long: 32 bit   range: 0 ~ (2**32 - 1)

    signed char: 8 bit   range: - 2**7 ~ 2**7-1
    unsigned char: 8 bit   range: 0 ~ (2**8 - 1)

FIXME: floating numbers...... is troublesome. later .....

*/

#include <stdio.h>
#include <limits.h>
#include <float.h>
int main() {
    // signed int
    int max_int = 2147483647;
    int min_int = -2147483647-1;
    printf("max int is %d, min int is %d\n", max_int, min_int);
    printf("max int + 1 is %d, min int -1 is %d\n", max_int+1, min_int-1);

    // unsigned int
    unsigned max_u_int = 4294967295;
    unsigned min_u_int = 0;
    printf("max unsigned int is %u, min unsigned int is %u\n", max_u_int, min_u_int);
    printf("max unsigned (int + 1) is %u, min unsigned (int - 1) is %u\n", max_u_int+1, min_u_int-1);

    // signed short int
    short max_s_int = 32767;
    short min_s_int = -32768;
    printf("max short is %d, min short is %d\n", max_s_int, min_s_int);
    printf("max short + 1 is %d, min short -1 is %d\n", max_s_int+1, min_s_int-1);

    // unsigned short int
    unsigned short max_u_s_int = 65535;
    unsigned short min_u_s_int = 0;
    printf("max unsigned short int is %u, min unsigned short int is %u\n", max_u_s_int, min_u_s_int);
    printf("max unsigned short (int + 1) is %u, min unsigned short (int - 1) is %u\n", max_u_s_int+1, min_u_s_int-1);

    // signed long int
    long max_l_int = 2147483647L;
    long min_l_int = -2147483647L-1;
    printf("max long is %d, min long is %d\n", max_l_int, min_l_int);
    printf("max long + 1 is %d, min long -1 is %d\n", max_l_int+1, min_l_int-1);


    // unsigned long int
    unsigned long max_u_l_int = 0xFFFFFFFFUL;
    unsigned long min_u_l_int = 0;
    printf("max unsigned int is %u, min unsigned int is %u\n", max_u_int, min_u_int);
    printf("max unsigned (int + 1) is %u, min unsigned (int - 1) is %u\n", max_u_int+1, min_u_int-1);

    // signed char
    char max_char = 127;
    char min_char = -127-1;
    printf("max char is %d, min char is %c\n", max_char, min_char);
    printf("max char + 1 is %c, min char -1 is %d\n", max_char+1, min_char-1);

    // unsigned char
    unsigned max_u_int = 255;
    unsigned min_u_int = 0;
    printf("max unsigned int is %u, min unsigned int is %u\n", max_u_int, min_u_int);
    printf("max unsigned (int + 1) is %u, min unsigned (int - 1) is %u\n", max_u_int+1, min_u_int-1);

    return 0;
}


