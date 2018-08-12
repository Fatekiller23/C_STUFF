/*
Exercise 5-12. Extend entab and detab to accept the shorthand
entab -m +n
to mean tab stops every n columns, starting at column m. Choose convenient (for the user)
default behavior.

我理解就是从底m列开始，往里面插tab？
算了算了，我觉得本题的意义就在于练习获得 -m +n 这两个参数的值，并且有个default behavior就行了。

将这个模式写出来，抽象成最简单的，就达到这个题的目的了吧。

这又是个鸡毛意思啊。。。。。。好烦呀。
*/



#define MAXLEN 100
#define SPACE 8
#include <stdio.h>
#include <string.h>


int main(int argc, char * argv[]) {
    char first[100];
    char last[100];

    if (argc-1 >0 ) {
        strcpy(first, *(argv+1));
        strcpy(last, *(argv+2));
    }

    printf("%s ", first);
    printf("%s", last);

}