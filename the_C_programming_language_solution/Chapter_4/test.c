#include <stdio.h>


#define square(x) x*x
#define paste(front, back) front ## back // create a token. 可以用来动态的变量名生成。
#define BUFSIZE 100



// // test #ifdefine #define
// #if !defined(HDR)
// #define HDR
// #define MSF 100
// #endif


// special form.
#ifndef HDR
#define HDR
/* contents of hdr.h go here */
#define MSF 100
#endif

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void);
void printd(int n);

int main()
{
    // int c;
    // static a; // static is default initialize to 0.
    // printf("%d", a);    
    // char pattern[] = "abcde";
    // printf("%s", pattern);


    // int cc[8] = {0,1,2,3,4,5}; // no initializer default to be 0.
    // for (int i=0;i<8;i++)
    //     printf("%d,", cc[i]);

    // printd(5638);

    // printf("%d\n",square(10));
    // int paste(name,1) = 0;
    // printf("%d\n", name1);

    printf("%d", MSF);
    return 0;
}



int getch(void) {
    int i;
    // i = (buf > 0) ? buf[--bufp] : getchar();
    return (buf > 0) ? buf[--bufp] : getchar();
    // return i;
}

void printd(int n) {
    // print a decimal to string. recursion style.
    if (n<0) {
        putchar('-');
        n = -n;
    }
    if(n/10) {
        printd(n/10);
    }
    putchar(n%10 + '0');
}