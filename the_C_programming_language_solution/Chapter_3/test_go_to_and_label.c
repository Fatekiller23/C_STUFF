/*
test go to and label syntax and its function.
*/
#include <stdio.h>


int main() {
    int some = 80;
    int array[10]={0,1,2,3,4,5,6,7,8,9};
    for (int i=0;i<10;i++)
        if (i==3){
            printf("now we are on a point of which i is 3\n");
            goto label;
        }


    label:
        printf("this is label statement!\n");
        printf("the scope is the whole function, some is %d\n", some);
    return 0;
}