/*
Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.

体会就是，所有问题都是由简单的子问题构造的。解决一个复杂问题时，不如先构造一些小的思维模型。
问题在于，如何巧妙的构造思维模型呢？？
*/
#include <stdio.h>

void itob(unsigned int s);
unsigned getmask(int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);

int main() {
    unsigned int x = 0b10101010;
    unsigned res;
    res = invert(x, 3,2);
    itob(res);
    return 0;
}

unsigned invert(unsigned x, int p, int n) {
    unsigned res;
    res = setbits(x,p,n,~x);
    return res;
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

