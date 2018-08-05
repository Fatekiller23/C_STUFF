/*
Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify
getch and ungetch accordingly.

单纯的把buffsize 设成1 不就行了么。。。
但是这样又不用改，估计不是这个解法。
*/


#include <stdio.h>

int buff = EOF;

int getch(void);
void ungetch(int);


int main()
{
    /* code */
    int c = getch();
    ungetch(c);

    printf("the result should be the character you put in.\n%c\n", getch());
    
    ungetch(c);
    printf("there will be a wrong signal ^^");

    return 0;
}

int getch(void) {
    if (buff == EOF) {
        return getchar();
    }
    else
        return buff;
}

void ungetch(int c) 
{
    if (buff == EOF) {
        buff = c;
    }
    else
        printf("wrong, already have a character!\n");
}
