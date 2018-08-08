#include <stdio.h>

#define ALLOCSIZE 10000
static char allocbuff[ALLOCSIZE];
static char *allocp = allocbuff;
// 说白了，alloc 就是一个 现需的内存，发现c里面不管多么复杂的数据结构，数组都是原型。
// 在网上的数据结构，都是数组的变形，或者演化。是为了满足一定的特性而存在的。


char * alloc(int );
void afree(char *);


char * alloc(int n){
    if (n <= allocbuff + ALLOCSIZE-allocp){
        allocp  =  allocp + n;
        return allocp - n;
    }
    else{
        printf("no enough room.\n");
        return 0; // C guarantees that zero never weii be an address of data.
    }
}

void afree(char *p){
    if (allocbuff < p < allocbuff + ALLOCSIZE){
        allocp = p;
    }
}