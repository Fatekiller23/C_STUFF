/*
Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank
*/

#include <stdio.h>
int main() {
    int c;
    int is_blank=0;
    while ((c = getchar()) != EOF ) {
        if (c==' '){
            if (is_blank!=1){
                printf("%c", c);
                is_blank =1;
            }
        }
        else {
            printf("%c", c); 
            is_blank =0;
        }
    }
    return 0;
}