

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
void itob(unsigned int s);

int main() {
    unsigned int c = 0b01100000;
    itob(c);
    // itob(~c);
    unsigned int res;
    res = getbits(c, 6,2);
    itob(res);
    
    return 0;
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

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
// p+1-n, cause p=0 stand for the right most position.
//          n     x
//        /   \ /    \
//  _ _ _ _ _ _ _ _ _
// | | | | | | | | | |  ----> array
//           ...  1 0
//        p    
// p+1 from 1...., then do the calculus x = p+1-n
    return (x >> (p+1-n)) & ~(~0 << n);
}
