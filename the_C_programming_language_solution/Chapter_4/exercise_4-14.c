/*
Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t.
(Block structure will help.)

从这个练习能看出来 宏，就是替换字符，把前一种表达替换成后一种表达。其他什么也没做。是在文件字符替换上面，不是在语义level上。
使用这个model，比较容易使用宏。
*/

#include <stdio.h>
#define swap(t,x,y) {t temp=x; x=y;y=temp;}

int main() {
    int x=1,y=2;
    swap(int,x,y);
    printf("x is 2:%d, y is 1:%d\n", x, y);
    return 0;
}