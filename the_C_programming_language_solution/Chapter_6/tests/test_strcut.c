/*
测试struct的基本使用方法
*/

#include <stdio.h>


int main() {
    // have storage. and one define way
    struct point {
        int x;
        int y;
    } one;
    one.x = 3;
    one.y = 4;
    printf("%d\n", one.x);

    // show nested.
    struct rectangle {
        struct point left_down;
        struct point right_up;
    };


    // struct function
    struct point makepoint(int x, int y)
    {
        struct point temp;
        temp.x=x;
        temp.y=y;
        return temp;
    }
    // struct point makepoint(int, int); // 给人感觉类似于一种声明，但是并没有什么卵子用啊。

    // add two points
    struct point addpoint(struct point p1, struct point p2){
        p1.x += p2.x;
        p1.y += p2.y;
        return p1;
    }
    

    struct rectangle screen, *ss;

    ss = &screen;
    
    printf("%d", (*ss).left_down.x);

    screen.left_down = makepoint(4,8);

    // screen.left_down.x=1;
    printf("%d", screen.left_down.x);


    // another initialize define way 
    struct point two  = { 320, 200 };


    // just define a shape
    struct point p;



    return 0;
}


