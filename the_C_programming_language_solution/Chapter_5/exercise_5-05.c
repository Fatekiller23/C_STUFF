/*
Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.
*/
#include <stdio.h>

char *strncpy1(char *, char *, int);
char *strncat1(char *, char *, int);
int strncmp1(char *, char *, int);

int main()
{
    char s[100];
    char b[100] = "abcd";
    char a[100] = "ccc";
    strncpy1(s, b, 6);
    printf("the result should be abcd: %s\n", s);

    strncat1(a,b,3);
    printf("the result should be cccabc: %s\n", a);

    strncmp1(a,b,3);
    printf("the result should be 2: %d", strncmp1(a,b,3));

    return 0;
}


char *strncpy1(char *s, char *ct, int n)
/*
将字符串 ct 中最多 n 个字符复制到字符串 s 中，并
返回 s。如果 ct 中少于 n 个字符，则用'\0'填充
*/
{   
    int i=0;
    while((*s++ = *ct++)!='\0'){
        if (i>=n-1)
            break;
        i++;
    }
    *(s+1)='\0';
}

char *strncat1(char *s, char *ct, int n)
/*
将字符串 ct 中最多前 n 个字符连接到字符串 s 的尾
部，并以'\0'结束；该函数返回 s
*/
{
    while (*s != '\0') /* find end of s */
        s++;
    int i=0;
    while((*s++=*ct++)) // copy t to s.
    {
        if (i>=n-1)
            break;
        i++;
    }
    *(s+1)='\0';
}




int strncmp1(char *s, char *ct, int n) 
/*
将字符串 cs 中至多前 n 个字符与字符串 ct 相比较。
当 cs<ct 时，返回一个负数：当 cs==ct 时，返回
0；当 cs>ct 时，返回一个正数
*/
{

    for(int i=0;*s==*ct;s++,ct++,i++){
        if (i>=n-1)
            break;
        if (*s=='\0')
            return 0;


    }
    return *s - *ct;
}