/*
Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time.
*/


#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int getline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse( char original[], char new[]);


/* print the longest input line */
main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    char new[MAXLINE];
    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        reverse(line, new);
        printf("%s", new);
    }

    return 0;
}
/* getline: read a line into s, return length */
int getline(char s[],int lim) {
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

void reverse( char original[], char new[]) {
    int i, j=0;

    while (original[i] != '\0')
        ++i;
    new[i] = '\0';
    new[i-1] = '\n';
    int trailer = i -2;

    while (trailer > -1) {
        new[j] = original[trailer];
        --trailer;
        ++j;
    }
}