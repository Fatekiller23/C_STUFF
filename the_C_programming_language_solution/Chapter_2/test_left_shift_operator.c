#include <stdio.h>
void itob(unsigned int s);
unsigned getmask(int p, int n);

int main() {
    unsigned int c = 0xFF;
    // for (int i=0;i<8;i++){
    //     c =c << 1;
    //     itob(c);
    // }
    unsigned int res = getmask(5,3);
    itob(res);
    
    // for (int i=0;i<3;i++){
    //     res =res << 1;
    //     itob(res);
    // }
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


unsigned getmask(int p, int n) {
    unsigned int i = 0xFF;
    return ((i >> (p+1-n)) & ~(~0 << n)) << n;
}