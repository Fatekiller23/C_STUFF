// Cases and the default clause can occur in any order. ?
// 确实default可以出现在任何位置。
//  execution falls through to the next unless you take
//  explicit action to escape ?
//  是的，满足那个值就从哪开始一直往下走。


#include <stdio.h>
 /* count digits, white space, others */
main() {
    int c, i, nwhite, nother, ndigit[10];
    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '0': case '1':putchar('1'); case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ndigit[c-'0']++;
                break;
            default:
                nother++;
                break;            
            case ' ':
            case '\n':
            case '\t':
                nwhite++;
                break;

        }
    }
    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n",
    nwhite, nother);
    return 0;
}

