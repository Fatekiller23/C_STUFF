/*
strcmp: 
array version and pointer version.
*/

#include <stdio.h>

int strcmp1(char *, char *);
int strcmp2(char *, char *);
int strcmp3(char *, char *);


int main(int argc, char const *argv[])
{
    int i = strcmp2("some", "som1");
    char s[10] = "abcd";
    char b[10] = "qwer";

    printf("%d", i);
    return 0;
}

int strcmp1( char *s, char *b) {
    int i=0;
    for(;s[i]==b[i];i++)
        if (s[i]=='\0')
            return 0;
    return s[i] - b[i];
}


int strcmp2( char *s, char *b) {
    for(;*s==*b;s++,b++)
        if (*s=='\0')
            return 0;
    return *s - *b;
}
