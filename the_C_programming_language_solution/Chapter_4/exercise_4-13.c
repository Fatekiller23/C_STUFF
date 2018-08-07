/*
Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the
string s in place.

解法比较简单。
如果在优化一下，我觉得可以让程序自己去数字符串的长度。
在一个，把接口改成一个入口，挺好的。

使用 static variable， 让变量得以在进入递归函数的同时，保存自己的值。
static 第一次会声明并赋值，后续在遇上时，应该是直接取值，而不会再赋值，这样的操作。

*/

#include <stdio.h>
#include <string.h>

void reverse(char [], int, int);
void reverse1(char s[]);
void reverse2(char s[]);


int main(void)
{
    /* code */
    char s[100] = "abcdefg";
    char b[100] = "12345";
    reverse(s, 0, 6);
    printf("%s\n", s);
    reverse1(b);
    printf("%s\n", b);
    reverse2(b);
    printf("%s\n", b);
    return 0;
}

void reverse(char s[], int left, int right) {
    if (left < right){
        reverse(s, left+1, right-1);
    }
    int temp = s[right];
    s[right] = s[left];
    s[left] = temp;

}


void reverse1(char s[])
{
    size_t len = strlen(s);
    static int offset = 0;
    char tmp;

    if (offset < (int) len / 2) {
        tmp = s[offset];
        s[offset] = s[len - (offset + 1)];
        s[len - (++offset)] = tmp;
        reverse1(s);
    } else {
        offset = 0; /* After last recursive call, reset for calls on new strings */
    }
    
}


void reverse2(char s[]) 
{
	static int i = 0, j = 0;
	char c;
	
	if (j == 0)
	    j = strlen(s) - 1;

   	if (i < j)
        {
            c = s[i];
            s[i++] = s[j];
            s[j--] = c;
            reverse2(s);
        }

        i = 0;
        j = 0;
}