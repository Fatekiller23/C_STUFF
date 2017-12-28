/*
Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough.
*/

#include <stdio.h>
#include <string.h>

#define MAX 1000

void reverse(char s[]);
void itoa(int n, char s[], int width);

int main() {
    char res[MAX];
    int n=-35;
    itoa(n, res, 10);
    printf("%s",res);
    return 0;
}


/* itoa: convert n to characters in s */
void itoa(int n, char s[], int width)
{
    int i, sign;
    if (n < 0) /* record sign */{
        sign=-1; /* make n positive */
        i = 0;
        do { /* generate digits in reverse order */
            s[i++] = -(n % 10) + '0'; 
        } while ((n /= 10) < 0); 
    }
    else{
        sign=1;
        i = 0;
        do { /* generate digits in reverse order */
            s[i++] = (n % 10) + '0'; 
        } while ((n /= 10) > 0); 
    }
    int j=i;
    for(int m=0;m<width-j;m++)
        s[i++]=' ';
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