/*
Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s.
*/
#include <stdio.h>
#include <string.h>

#define MAX 1000

void reverse(char s[]);
void itob(int n, char s[], int b);


int main() {
    char res[MAX];
    int n=-35;
    // printf("%d", 2147483647);
    itob(n, res,16);
    printf("%s",res);
    return 0;
}



/* itoa: convert n to characters in s */
void itob(int n, char s[], int b)
{
    char map[16] ="0123456789ABCDEF";
    int i, sign;
    if (n < 0) /* record sign */{
        // printf("%d", n);
        sign=-1; /* make n positive */
        i = 0;
        do { /* generate digits in reverse order */
            // printf("%d", n%10);
            s[i++] = map[-(n % b)]; /* get next digit */
        } while ((n /= b) < 0); /* delete it */
    }
    else{
        sign=1;
        i = 0;
        do { /* generate digits in reverse order */
            // printf("%d", n%10);
            s[i++] = map[(n % b)]; /* get next digit */
        } while ((n /= b) > 0); /* delete it */
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