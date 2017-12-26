/*
Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case,
with a conditional expression instead of if-else.

ep1 ? ep2 : ep3
ep3 should be the type of ep1

*/
#include <stdio.h>

void lower(char s[]);

int main() {
    char s[20] = "ABCdskLL";
    lower(s);
    printf("the result of ABCdskLL should be abcdskll ----> ");
    printf("%s\n", s);

    return 0;
}

void lower(char s[]) {
    for(int i=0;s[i]!='\0';i++) {
        (s[i]>=65 && s[i]<=90) ? s[i]+=32 : 0;
    }
}