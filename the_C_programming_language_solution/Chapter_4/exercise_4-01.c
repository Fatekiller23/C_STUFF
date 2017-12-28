/*
Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.
*/
#include <stdio.h>
#include <string.h>

int strindex_right(char s[], char t[]);

int main() {
    char test1[200]="some thing is big big, bro!";
    int index1 = strindex_right(test1, "big");
    printf("the index of |big| of test1 should be 18. ------------> %d\n", index1);

    char test2[200]="some thing is none none, bro!";
    int index2 = strindex_right(test2, "big");
    printf("the index of |big| of test2 should be 18. ------------> %d\n ", index2);
    return 0;
}






/* strindex: return index of t in s, -1 if none */
int strindex_right(char s[], char t[])
{
    int i, j, k,index;
    index=-1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
                ;
        if (k > 0 && t[k] == '\0')
            index=i;
    }
    return index+1?index:-1;
}