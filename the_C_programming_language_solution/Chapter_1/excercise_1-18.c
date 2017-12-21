/*
Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines.
*/

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int getline(char line[], int maxline);
void copy(char to[], char from[]);
void get_off(char original[], char new[],int trailer);
void raw(char s[], int end);


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
        get_off(line, new, len);
        raw(new, len);
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

/* return no trailing spaces */
void get_off(char original[], char new[],int trailer) {
    int work = 0;
    for (int i=trailer -2 ;trailer != -1; --trailer) {

        if (original[trailer] != '\t' || original[trailer] != '\b'  || original[trailer] != ' '){
            work = 1;
        }
        if (work == 1) {
            new[trailer] = original[trailer];
        }
        
    }
}

void raw(char s[], int end) {
    int i = 0;
    while ( i < end) {
        if (s[i] =='\t'){
            printf("\\t");
        }
        else if(s[i] == '\b'){
            printf("\\b");
        }
        else if(s[i] =='\\'){
            printf("\\");
        }
        else{
            printf("%c",s[i]);
        }
        i++;
    }
}