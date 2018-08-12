#define ALLOCSIZE 10000
static char allocbuff[ALLOCSIZE];
static char *allocp = allocbuff;

#include <stdio.h>

char * alloc(int n){
    if (n <= allocbuff + ALLOCSIZE-allocp){
        allocp  =  allocp + n;
        return allocp - n;
    }
    else{
        printf("%s","no enough room.\n");
        return 0; // C guarantees that zero never weii be an address of data.
    }
}