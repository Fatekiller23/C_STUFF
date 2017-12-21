/*
Exercise 1-12. Write a program that prints its input one word per line.

这段程序小细节在于 将 判断转义字符的逻辑放在了最前面，这样当第二个逻辑生效时，自然表明进入了一个单词里面。
*/

#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
/* count lines, words, and characters in input */
main() {
    int c,nw,state;
    state = OUT;
    nw = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
        state = OUT;
        putchar('\n');
        continue;
        }
        else if (state == OUT) {
        state = IN;
        }
        putchar(c);
    }
}