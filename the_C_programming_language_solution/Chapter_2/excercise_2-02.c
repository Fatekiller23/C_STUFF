/*
Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.

Notice you that Expressions connected by && and || are evaluated left to right.
*/

#include <stdio.h>
#define MAXLEN 1000
int getline(char s[],int lim);

int main() {
    char line[MAXLEN];
    int len;

    while(len= getline(line,MAXLEN)){
        printf("%s", line);
    }
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[],int lim) {
    int c, i;
    for (i=0; i < lim-1; ++i) {
        c = getchar();
        if (c == EOF)
            break;
        if (c=='\n')
            break;
        s[i] = c;
    }
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}