/*
Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
a function for the other direction as well, converting escape sequences into the real characters.
*/

#include <stdio.h>

#define MAX 100

void show_escape(char s[], char t[]);
void hide_escape(char s[], char t[]);

int main() {
    char s[MAX];
    char z[MAX];
    char t[MAX] = "tab\tspace newline\n\n";
    show_escape(s, t);
    printf("the result should be tab\\tspace\\snewline\\n\\n\n-------------------> %s\n", s);

    hide_escape(z, s);
    printf("the result should be \ntab\tspace newline\n\n\n-------------------> \n%s", z);


    return 0;
}

void show_escape(char s[], char t[]) {
    int c;
    int i=0; int j = 0;

    while ((c=t[i]) != '\0') {

        switch (c) {
            case ' ':
                s[j]='\\';
                s[++j]='s';
                break;
            case '\t':
                s[j]='\\';
                s[++j]='t';
                break;
            case '\n':
                s[j]='\\';
                s[++j]='n';
                break;
            default:
                s[j] = c;
                break;
        }
        i++;
        j++;
    }
}

void hide_escape(char s[], char t[]) {
    int c;
    int j=0;
    int i=0;
    int escape=0;
    while ((c=t[i]) != '\0') {

        switch (c) {
            case '\\':
                escape=1; 
                break;
            case 'n':
                (escape==1) ? (s[j]='\n') : (s[j]=c);
                escape=0;
                j++;
                break;
            case 't':
                (escape==1) ? (s[j]='\t') : (s[j]=c);
                escape=0;
                j++;
                break;
            case 's':
                (escape==1) ? (s[j]=' ') : (s[j]=c);
                escape=0;
                j++;
                break;
            default:
                s[j]=c;
                j++;
                break;
        }
        i++;
    }
    s[i] == '\0';
}