#include "cal.h"
#include <stdio.h>
#include <ctype.h>

int getop(char s[]) {
    int i, c, neg;
    static int extra=0;

    if (extra != 0) {
        c = extra;
        if (c == ' ' || c == '\t') {
               while ( (s[0] = c = getch()) == ' ' || c == '\t')
                    ;
                s[1] = '\0';
        }
        
    }
    else {
            while ( (s[0] = c = getch()) == ' ' || c == '\t')
                ;
                s[1] = '\0';
    }




    if (isalpha(c)) {
        int i=0;
        while(isalpha(s[++i] = c = getch()))
            ;
        extra = c;
        s[i] = '\0';
        return NAME;
    }

    if (!isdigit(c) && c != '.' && c !='-'){
        // putchar(c);
        return c;
    }
    
    else if (c=='-' &&   isdigit(c=getch()) )
    {
        // this is a negative number
        extra = c;
        neg=1;
    }
    else if (c == '-') {
        return c;
    }
    i=0;
    if (isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';

    if (c != EOF)
    extra = c;
    
    return NUMBER;    // signal that a number is found.
}
