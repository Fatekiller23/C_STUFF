/*
Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2

solution:
    squeeze2 use squeeze as building block.
    squeeze3 use not_in funcntion to get the same funciton as `s[i] != c` in squeeze().
    Both should work.
*/
#include <stdio.h>



// function prototype
void squeeze(char s[], int c);
void squeeze2(char s[], char b[]) ;
void squeeze3(char s[], char b[]);
int not_in(int c,char s[]);




int main() {
    char s[20] = "some thing";
    char b[20] = "some th";
    // squeeze(s, 's');
    squeeze3(s, b);
    printf("%s", s);
    return 0;
}


/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
        s[j++] = s[i];
    s[j] = '\0';
}

void squeeze2(char s[], char b[]) {
    int i=0;
    while (b[i] != '\0') {
        squeeze(s, b[i++]);
    }
}

void squeeze3(char s[], char b[]) {
    int i, j;
    for (i=j=0; s[i] != '\0'; i++)
        if(not_in(s[i], b))
        s[j++] = s[i];
    s[j] = '\0';
}

int not_in(int c,char s[]) {
    int state = 1;
    for(int i = 0; s[i] != '\0'; i++)
        if (s[i]==c)
        state =0;
    return state;
}