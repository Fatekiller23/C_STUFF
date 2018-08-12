#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXSTORE 10000
#define MAXLEN 1000 /* max length of any input line */


int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);
void swap(void *v[], int i, int j);




char *lineptr[MAXLINES]; /* pointers to text lines */


/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        myqsort((void**) lineptr, 0, nlines-1, (int (*)(void*,void*)) (numeric ?numcmp:strcmp)); 
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
int numcmp(const char *s1, const char *s2)
{
    double v1, v2;

    v1 = atof(s1); // 表明比较的字符串都得是数字。
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}


void swap(void *v[], int i, int j)
{
    // 在不涉及指动作的时候，指针还是应该以变量来考虑。
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}







