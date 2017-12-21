/*
Exercise 1-11. How would you test the word count program? What kinds of input are most
likely to uncover bugs if there are any?

我认为是特殊符号。 比如说不能正确编码的那种。 还有没有考虑到的转移字符。/f
1. 字符数量太大，导致int overflow.(巨幅小说)
2. 如果得到的字符不属于 判断空格的 条件， 是一个特殊字符，就不符合统计的正确性。
3. 一堆异国语言的文集。
4. 0-length file.

*/

#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
/* count lines, words, and characters in input */
main() {
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
        ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
        state = OUT;
        else if (state == OUT) {
        state = IN;
        ++nw;
        }
    }
printf("%d %d %d\n", nl, nw, nc);
}