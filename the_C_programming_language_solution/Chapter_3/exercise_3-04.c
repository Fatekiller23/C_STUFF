/*
Exercise 3-4. In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2**(wordsize-1)). Explain why
not. Modify it to print that value correctly, regardless of the machine on which it runs.

solution:
    因为程序是将 原数字整个取负值运算，但是整形范围在 -2147483648~2147483647
    是不存在2147483648 这个表示的。
    所以答案就很简单了。我们不要他变正数了，负数取模也行，不就是
*/
#include <stdio.h>
#include <string.h>

#define MAX 1000

void reverse(char s[]);
void itoa(int n, char s[]);

int main() {
    char res[MAX];
    int n=-35;
    // printf("%d", 2147483647);
    itoa(n, res);
    printf("%s",res);
    return 0;
}


/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;
    if (n < 0) /* record sign */{
        // printf("%d", n);
        sign=-1; /* make n positive */
        i = 0;
        do { /* generate digits in reverse order */
            // printf("%d", n%10);
            s[i++] = -(n % 10) + '0'; /* get next digit */
        } while ((n /= 10) < 0); /* delete it */
    }
    else{
        sign=1;
        i = 0;
        do { /* generate digits in reverse order */
            // printf("%d", n%10);
            s[i++] = (n % 10) + '0'; /* get next digit */
        } while ((n /= 10) > 0); /* delete it */
    }
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}



void reverse(char s[]) {
    int i=0;
    for (int j=strlen(s)-1;i<j;i++,j--){
        char temp = s[i];s[i] = s[j];s[j] = temp;
    }
}