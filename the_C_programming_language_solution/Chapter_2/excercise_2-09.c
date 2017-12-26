/*
Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount.

solution:
    因为二进制的减一，一定会让最后一位1变为0（借位），在与原数进行bitwise 与操作，则会将最后一位1 与成 0.
*/

#include <stdio.h>

void itob(unsigned int s);

int main() { 
    int counter = 0;
    unsigned int number = 0b11110011;
    while (number != 0) {
        // itob(number);
        number &= (number-1);
        counter++;
    }
    printf("%d\n", counter);
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
