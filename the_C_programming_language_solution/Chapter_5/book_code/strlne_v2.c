#include <stdio.h>

size_t strlen(char *s) {
    char *p = s;
    for(;*p!='\0';p++)
    ;
    return p-s;
}