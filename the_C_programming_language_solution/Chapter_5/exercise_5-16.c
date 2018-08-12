/*
Exercise 5-16. Add the -d (``directory order'') option, which makes comparisons only on
letters, numbers and blanks. Make sure it works in conjunction with -f.
a-zA-z,0-9,' ', no #$%^&*()_ 

-d 只在 这些范围内比较，其他不比，不比的意思是绝对大？永远放到最后面，还是说有错误输入，退出循环？
思考良久，我觉得应该是将那些符号类的直接略过，拼成新的字符串。

不做了不做了，下一道。没求意思。

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXSTORE 10000
#define MAXLEN 1000 /* max length of any input line */


int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp( char *,  char *, int ,int);
int strcmp1( char *s, char *b, int r, int);

void swap(void *v[], int i, int j);

char *lineptr[MAXLINES]; /* pointers to text lines */

int derectory=0;

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    int rreverse=0;
    int fold=0;
    int c;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) {
                case 'r':
                    rreverse = 1;
                    break;
                case 'n':
                    numeric = 1;
                    break;
                case 'f':
                    fold=1;
                    break;
                case 'd':
                    derectory =1;
                    break;
                
                default:
                printf("find: illegal option %c\n", c);
            }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        myqsort((void**) lineptr, 0, nlines-1, (int (*)(void*,void*)) (numeric ?numcmp:strcmp1)); 
        // 这块一直提示 pointer type mismatch， 也不知道什么原因。后来发现一个参数是strcmp官方的，而书上是自己写的，自己写的，参数没加const。
        // 综合来讲前面是一个类型转换，即便转了也不会使信息丢失，但是我不知道为什么要转呢？
        // 在上面那句话卡了下半天。。。。
        writelines(lineptr, nlines);
        return 0;
    } 
    else {
        printf("input too big to sort\n");
        return 1;
    }
}


/* qsort: sort v[left]...v[right] into increasing order */
void myqsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    myqsort(v, left, last-1, comp);
    myqsort(v, last+1, right, comp);
}


#include <stdlib.h>
/* numcmp: compare s1 and s2 numerically */
int numcmp( char *s1,  char *s2, int r, int f)
{
    double v1, v2;

    if (f==1) {
    strlwr(s1);
    strlwr(s2);
    }

    v1 = atof(s1); // 表明比较的字符串都得是数字。
    v2 = atof(s2);

    if (r==1){
        if (v1 < v2)
            return 1;
        else if (v1 > v2)
            return -1;
        else
            return 0;        
    }
    else {
        if (v1 < v2)
            return -1;
        else if (v1 > v2)
            return 1;
        else
            return 0;
    }
}

int strcmp1( char *s, char *b, int r, int f) {
    if (f==1) {
        strlwr(s);
        strlwr(b);
    }    
    int i=0;
    for(;s[i]==b[i];i++)
        if (s[i]=='\0')
            return 0;
    if (r==1){
        return b[i]-s[i];
    }
    else
    return s[i] - b[i];
}

void swap(void *v[], int i, int j)
{
    // 在不涉及指动作的时候，指针还是应该以变量来考虑。
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

