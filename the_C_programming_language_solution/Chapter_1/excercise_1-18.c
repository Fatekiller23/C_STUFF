/*
Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines.
*/

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int getline(char line[], int maxline);
void copy(char to[], char from[]);
void get_off(char original[], char new[],int trailer);
void raw(char s[]);


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
        raw(new);
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
    int end = 0;
    for (int i = trailer-2;i != -1; --i) {
        // printf("this word is %c \n", original[i]);

        if (original[i] != '\t' && original[i] != '\b'  && original[i] != ' '){
            if (end == 0)
                new[i+1] = '\0';
                end = 1;
            new[i] = original[i];
            // printf("new index %d is %c",i, new[i]);
        }

        
    }
}

void raw(char s[]) {
    int i = 0;
    while ( s[i] != '\0') {
        if (s[i] =='\t'){
            printf("\\t");
        }
        else if(s[i] == '\b'){
            printf("\\b");
        }
        else if(s[i] =='\\'){
            printf("\\");
        }
        else if(s[i] ==' '){
            printf("\\s");
        }
        else{
            printf("%c",s[i]);
        }
        i++;
    }
}