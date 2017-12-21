/*
Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?

*/


#define MAXLEN 1000
#define SPACE 8
#include <stdio.h>

int main() {
    char result[MAXLEN];
    char c;
    int index=0;
    int spaces, tabs;
    while ((c = getchar()) != EOF && c!='\n'){

        if (c == ' ') {
            int counts = 1;

            while ((c=getchar()) == ' ' ){
                counts += 1;
            }
            spaces = counts % SPACE;
            tabs = counts / SPACE;
            printf("%d----tabs \n%d ----- spaces\n", tabs, spaces);

            // add tabs
            for (int i = 0; i < tabs; i++){
                result[index] = '\t';
                index++;
            }

            // add spaces
            for (int i = 0; i < spaces; i++){
                result[index] = ' ';
                index++;
            }


            result[index] = c;
            index++;
        }
        else {

            result[index] = c;
            index++;
        }
    }
    result[index] = '\0';
    printf("%s\n", result);
}

