/*

Exercise 4-4. Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack.

thinking:
    print stop, get top index
    duplicate ?
    swap two
    clear stack
    i forget what is stack.......
*/



#include <stdio.h>
#define SIZE 100
int STACK[SIZE];
int position =0;

void show(int []);
void duplicate( int []);
void swap( int []);
void clear( int []);


int main() {
    for (; position < 10;position++)
        STACK[position] = position;

    printf("show commands should show value 9 \n");
    show(STACK);

    printf("duplicate commands shoud show value 9 9\n");
    duplicate(STACK);
    printf("%d  %d\n", STACK[position-1], STACK[position-2]);

    printf("swap commands shoud show value 9 9\n");   
    printf("%d  %d\n", STACK[position-2], STACK[position-1]);

    printf("clear commands shoud show value cooresponding value in that storage.\n");   
    printf("%d\n ", STACK[position-1]);


    return 0;
}

void show(int s[]) {
    printf("%d\n", s[position-1]);
}

void duplicate( int s[]){
    s[position] = s[position-1];
    position++;
}

void swap( int s[]) {
    int c = s[position-1];
    s[position-1] = s[position-2];
    s[position -2] = c; 
}


void clear( int s[]) {
    position = 0;
}
