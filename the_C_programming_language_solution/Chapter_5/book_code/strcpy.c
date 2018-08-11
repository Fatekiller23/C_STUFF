#include <stdio.h>

void strcpy1(char *s, char *b);
void strcpy2(char *s, char *b);
void strcpy3(char *s, char *b);


int main(int argc, char const *argv[])
{
    printf("%d", 1==1);
    return 0;
}

// arrray version.
void strcpy1(char *s, char *b) {
    int i=0;
    while((s[i]=b[i]) != '\0')
        i++;
}


// pointer version
void strcpy2(char *s, char *b) {
    while((*s = *b) != '\0') {
        s++;
        b++;
    }
}

// pointer versino, concise version.
void strcpy3(char *s, char *b) {

    while(*s++=*b++)
        ;
}

