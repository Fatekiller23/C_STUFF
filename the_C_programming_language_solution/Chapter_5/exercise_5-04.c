/*
Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise.

思路就是，先把t的数量算出来
然后把指针调到相同位置
挨个进行比较，完了。

*/

#include <stdio.h>

int strend(char * , char * );

int main(int argc, char const *argv[])
{
    /* code */
    char s[100] ="qwertyu";
    char t[100] ="yu";
    // putchar(;

    int i = strend(s,t);
    printf("the result should be 1-----%d\n", i);
    return 0;
}

int strend(char * s, char * t) {
    //1. caculate t number.
    int i=0;
    while(*t != '\0'){
        i++;
        t++;
    }
    //2. put s pointer right place
    while(*s != '\0'){
        s++;
    }
    *s=*(s-i); // 分清楚，很重要！！！！很重要！！！！ 我在这卡了 半个小时！！！ 没有意识到，回去面壁，思过。
    *t=*(t-i);
    while(*s==*t)
    {   
        if (*s=='\0'){
            return 1;
        }
        s++;
        t++;
    } 
    return 0;
}

