/*
Exercise 1-8. Write a program to count blanks, tabs, and newlines.
*/


#include <stdio.h>
/* count lines in input */
main() {
    int c, nl, blanks, tabs;
    nl = 0;
    blanks = 0;
    tabs = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n')
        ++nl;

        if (c == ' ')
        ++blanks;

        if (c == '\t')
        ++tabs;
    }

    printf("newlines is  %d\n", nl);
    printf("blanks is %d\n", blanks);
    printf("tabs is %d\n", tabs);
}