/*
Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises with pointers
instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa,
and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop
(Chapter 4)

for god sake, 真的要写那么多么。。。。。。好累好累。
getop 不想写了，感觉就是index的语法直接变成指针。
这题的目的大概在于让我们深刻理解 指针和index 就是一币两面。不同写法罢了。
*/
#include <stdio.h>
#include <string.h>

int getline(char *, int);
int atoi(char *);
void reverse( char *);
void itoa(int , char * );
int strindex_right(char *s, char *t);
int main()
{
    char s[100];
    // int i = getline(s, 6);
    // printf("%s", s);

    // printf("%d\n",atoi("123"));
    // itoa(100,s);
    // printf("%s", s);

    char test1[200]="some thing is big big, bro!";
    int index1 = strindex_right(test1, "big");
    printf("the index of |big| of test1 should be 18. ------------> %d\n", index1);
    return 0;
}


int getline(char * s, int lim) {
    int c;
    char *t=s;

    while (--lim>-1 && ( (c=getchar())!= EOF && c!='\n')){
       *s++ = c;
    }
    if (c == '\n')
       *s++ = c;
    *s = '\0';
    return s - t;
}


/* atoi: convert s to integer */
int atoi(char *s) {
    int i, n;
    n = 0;
    for (i = 0; *(s+i) >= '0' && *(s-i) <= '9'; ++i)
        n = 10 * n + (*(s+i) - '0');
    return n;
}


void itoa(int n, char * s)
{
    int i, sign;
    char *p = s;
    if (n < 0) /* record sign */{
        // printf("%d", n);
        sign=-1; /* make n positive */
        i = 0;
        do { /* generate digits in reverse order */
            // printf("%d", n%10);
            *s++ = -(n % 10) + '0'; /* get next digit */
        } while ((n /= 10) < 0); /* delete it */
    }
    else{
        sign=1;
        i = 0;
        do { /* generate digits in reverse order */
            // printf("%d", n%10);
            *s++ = (n % 10) + '0'; /* get next digit */
        } while ((n /= 10) > 0); /* delete it */
    }
    if (sign < 0)
        *s++ = '-';
    *(s+i) = '\0';
    reverse(p);
}

void reverse(char * s) {
    int i=0;
    for (int j=strlen(s)-1;i<j;i++,j--){
        char temp = *(s+i);*(s+i) = *(s+j);*(s+j) = temp;
    }
}


/* strindex: return index of t in s, -1 if none */
int strindex_right(char *s, char *t)
{
    int i, j, k,index;
    index=-1;
    for (i = 0; *(s+i) != '\0'; i++) {
        for (j=i, k=0; *(t+k)!='\0' && *(s+j)==*(t+k); j++, k++)
                ;
        if (k > 0 && *(t+k) == '\0')
            index=i;
    }
    return index+1?index:-1;
}