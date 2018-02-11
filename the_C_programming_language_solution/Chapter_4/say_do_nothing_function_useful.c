/*
why do-nothing-function is useful?
    as a place-holder during program development.
    but HOW  !? Show me the code.

    看起来是作为FAKE funciton的意思。
    比如有程序需要一个funciton ，但是这个function还没有写，于是就伪造一个do-nothing-function.
*/

#include <stdio.h>
int add();
int main() {
    add();
    return 0;
}

int add() {}