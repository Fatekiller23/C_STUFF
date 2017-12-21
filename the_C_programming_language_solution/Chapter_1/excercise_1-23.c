/*
Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.
*/


#include <stdio.h>
#define MAXLEN 100000
#define BACKSLASH 47
#define YES 1
#define NO 0


int getline(char s[],int lim);
void copy(char to[], char from[]);
void put_raw_char(char c);
void print_raw_arry(char s[]);
void strip_newline(char s[]);


/* print the longest input line */
main()
{
    int inline_comment, mul_comment = NO;
    int len; /* current line length */
    char line[MAXLEN]; /* current input line */
    char result[MAXLEN]; /* current input line */
    int j=0;
    while ((len = getline(line, MAXLEN)) > 0) {
        inline_comment = NO;
        int first=line[0];
        int i;
        for (i=1; i<len; i++) {
            
            // printf("first is %c, now is %c \n", first, line[i]);
            if (line[i] == BACKSLASH && first == BACKSLASH) {
                inline_comment = YES;
            }
            
            if (first == BACKSLASH && line[i] == '*') {
                mul_comment = YES;
            }

            if (first == '*' && line[i] == BACKSLASH && mul_comment == YES) {
                mul_comment = NO;
                i=i+1;
                first = line[i];

            }
            // printf("inline_comment: %d , mul_comment: %d\n\n", inline_comment, mul_comment);
            if (inline_comment == YES)
                break;

            if (mul_comment == YES){
                first = line[i];
                continue;
            
            }

            
            // put_raw_char(first);
            result[j] = first;
            j++;   
            first = line[i];
        }
        result[j] = '\n';
        j++;
    }
    result[j+1] = '\0';
    // print_raw_arry(result);
    strip_newline(result);
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

void put_raw_char(char c) {
        if (c =='\t'){
            printf("\\t");
        }
        else if(c == '\b'){
            printf("\\b");
        }
        else if(c =='\\'){
            printf("\\");
        }
        else if(c ==' '){
            printf("\\s");
        }
        else if(c =='\n'){
            printf("\\n");
        }
        else{
            printf("%c",c);
        }
}

void print_raw_arry(char s[]) {
    int length=0;
    int c;
    while (s[length] != '\0')
        ++length;
    for (int i=0;i<length;i++){
        c =s[i];
        if (c =='\t'){
            printf("\\t");
        }
        else if(c == '\b'){
            printf("\\b");
        }
        else if(c =='\\'){
            printf("\\");
        }
        else if(c ==' '){
            printf("\\s");
        }
        else if(c =='\n'){
            printf("\\n");
        }
        else{
            printf("%c",c);
        }
    }
}

void strip_newline(char s[]) {
    int i = 0;
    while (s[i] == '\n')
        i++;

    int is_newline = 0;
    
    while (s[i] != '\0' ) {
        if (s[i] =='\n'){

            if (is_newline!=1){
                printf("%c", s[i]);
                is_newline =1;
            }
        }
        else {
            printf("%c", s[i]); 
            is_newline =0;
        }
        ++i;
    }
   
}