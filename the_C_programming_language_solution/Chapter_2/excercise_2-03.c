/*
Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F.

solution:
    using author's implementation of atoi.
*/

#include <stdio.h>
int atoi(char s[]);
int htoi(char s[]);
int main() {

    int n = htoi("0xB5");
    printf("%d", n);
    return 0;
}

/* atoi: convert s to integer */
int atoi(char s[]) {
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

int htoi(char s[]) {
    if (s[0]!='0' || (s[1] != 'x' && s[1] != 'X'))
        return -1;
    int i = 2;
    int n =0;
    for(;;++i) {
        if (s[i] >= '0' && s[i] <='9'){
            n = 16 * n + (s[i] - '0');
        }
        else if (s[i] >= 'A' && s[i] <='Z'){
            n = 16 * n + (s[i] - '7');
        }
        else if (s[i] >= 'a' && s[i] <='z'){
            n = 16 * n + (s[i] - 'w');
        }
        else{
            break;
        }
    }
    return n;
}