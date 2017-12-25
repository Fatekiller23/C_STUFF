/*
Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.)
*/
#include <stdio.h>



// function prototype
int not_in(int c,char s[]);
int any(char s[], char b[]);


int main() {
    char s[20] = "some hing";
    char b[20] = "abcd";
    int index;
    index = any(s, b);
    printf("the index should be 5 ----> %d", index);
    return 0;
}

int any(char s[], char b[]) {
    int i=0;
    while(s[i]!='\0') {
        if(!not_in(s[i], b))
        break;
        i++;
    }
    if (s[i]=='\0')
        return -1;
    return i;
}

// if c not in s return 1, otherwise return 0.
int not_in(int c,char s[]) {
    int state = 1;
    for(int i = 0; s[i] != '\0'; i++)
        if (s[i]==c)
        state =0;
    return state;
}