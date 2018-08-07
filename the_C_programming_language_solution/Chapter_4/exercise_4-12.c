/*
Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert
an integer into a string by calling a recursive routine.

soluiton:
    想了两个版本的itoa。一种使用static 变量记录位数。 一种使用递归层数返回位数。
*/

#include <stdio.h>
void itoa_1(char[], int);
int itoa_2(char s[], int i);
void printd(int n);


int main(void)
{
    char s[20];
    itoa_1(s, -1234);
    printf("the result should be -1234 ----------| %s \n", s);

    itoa_2(s, -5678);
    printf("the result should be -5678 ----------| %s \n", s);

    return 0;
}

void itoa_1(char s[], int i) {
    static int a=0;
    if (i<0) {
        s[a++] = '-';
        i = -i;
    }
    if(i/10) {
        itoa_1(s, i/10);

    }
    s[a++]= i%10 + '0';
    s[a]='\0';
}


int itoa_2(char s[], int i) {
    int digit = 0;
    int neg=0;
    if (i<0) {
        neg=1;
        i = -i;
    }
    if(i/10) {
        digit = itoa_2(s, i/10);

    }
    s[digit]= i%10 + '0';
    s[digit+1]='\0';

    if (neg==1){
        // if the number is negative, preceded with '-'.
        for(int c=digit+1; c>-1;c--){
            s[c+1] = s[c];
        }
        s[0] = '-';
    }

    return digit + 1;
}
