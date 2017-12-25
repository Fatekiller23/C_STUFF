/*
Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.

solution:
    the key to solve this problem is to easily get the correct mask.
        use x & 00011100, 1 for stay, 0 for away.
    trap:  1. 位运算的优先级  2. unsigned type

*/
#include <stdio.h>

void itob(unsigned int s);
unsigned getmask(int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
    unsigned int x = 0b00000000;
    unsigned int y = 0b10101100;
    int p = 5;
    int n = 3;
    unsigned res = setbits(x,p,n,y);
    printf("the result should use y(5,3):101 to x(5,3) which is:\n");
    itob(res);
    return 0;
}


unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // mask x
    x = x & ~getmask(p,n);
    // mask y
    y = y & getmask(p,n);
    // combination
    return x | y;
}


void itob(unsigned int s) {
    char res[9];
    int index = 7;
    while (index != -1) {
        // printf("s is %d, index is %d, res[%d] is %d, \n",s,index,index,s%2);
        res[index] = (s % 2) + 48;
        s = s / 2;
        index--;
    }
    res[8] ='\0';
    printf("%s\n", res);
}

/*getmask(5,2) -->  00110000*/
unsigned getmask(int p, int n) {
    unsigned int i = 0xFF;
    return ((i >> (p+1-n)) & ~(~0 << n)) << n;
}