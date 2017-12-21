/*
Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
*/

#include <stdio.h>

int main() {
    int c;
    c = (getchar()  != EOF);
    printf("%d,  c == 1: %d", c, c==1);
    return 0;
}