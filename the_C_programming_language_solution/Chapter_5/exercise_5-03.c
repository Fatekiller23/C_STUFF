/*
Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s.

*/
#include <stdio.h>

void strcat1(char *, char *);

int main(void) {
    char s[100] = "abcde";
    char b[100] = "qwert";
    strcat1(s, b);
    printf("%s", s);
    return 0;
}

void strcat1(char * s, char * t) {
    while (*s != '\0') /* find end of s */
    s++;
    while((*s++=*t++)) // copy t to s.
    ;
}
