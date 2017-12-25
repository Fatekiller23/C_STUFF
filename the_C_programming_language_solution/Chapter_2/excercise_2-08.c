/*
Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.
*/

#include <stdio.h>

void itob(unsigned int s);
unsigned rightrot(unsigned x, int n);

int main() {
    unsigned int x = 0b00001111;
    unsigned res;
    res = rightrot(x, 2);
    printf("the result should be 11000011:\n");
    itob(res);
    return 0;
}

unsigned rightrot(unsigned x, int n) {
    n = n % 8;
    // construct base
    unsigned base = 0x00;
    base = (x << (8-n)) | base;
    
    // right shift
    x = x >> n;

    // combine
    x = x | base;
    return x;
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
