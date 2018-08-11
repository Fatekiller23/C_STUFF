/*
Exercise 5-7. Rewrite readlines to store lines in an array supplied by main, rather than
calling alloc to maintain storage. How much faster is the program?

i'm a dumass, you know?  i fucked up twice in the same hole.  

right:
if ((nlines=my_readlines(lineptr, MAXLINE))>0)
wrong:
if (nlines=my_readlines(lineptr, MAXLINE)>0)

这个问题首先要问，为什么 calling alloc 会慢？
查询了网上答案 说是malloc 会调用系统kernel的指令，所以会消耗cpu，让程序变慢。
在我们这个例子中，速度的插值可能来源于指针的不断运算吧。
*/
#include <stdio.h>
#include <string.h>
#define MAXLINE 5
#define MAXSTORE 10000
char * lineptr[MAXLINE];



#define ALLOCSIZE 10000
static char allocbuff[ALLOCSIZE];
static char *allocp = allocbuff;
char * alloc(int );

#define MAXLEN 1000 /* max length of any input line */
int getline(char *, int);
char *alloc(int);
void writelines(char *lineptr[], int nlines);
int my_readlines(char *lineptr[], int maxlines, char *);
void qsort(char *lineptr[], int left, int right);

int main() {
    int nlines;
    char line_storage[10000];

    if ((nlines=my_readlines(lineptr, MAXLINE, line_storage))>0){
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else{
        printf("error, too big to sort lines");
        return 1;
    }


}

int my_readlines(char *lineptr[], int maxlines, char* line_storage)
{   
    int len;
    char *p = line_storage;
    
    // find adddres of the end of line_storage.
    char *end =line_storage+MAXSTORE;
    char line[MAXLEN];
    int nlines=0;
    while((len = getline(line, MAXLEN))>0) {
        
        if (nlines>maxlines || (end-p)<len) {
            return -1;
        }
        else{
            line[len-1] = '\0'; // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
            p=p+len;
        }
    }
    return nlines;
}


void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}



int getline(char * s, int lim) {
    int c;
    char *t=s;

    while (--lim>-1 && ( (c=getchar())!= EOF && c!='\n')){
       *s++ = c;
    }
    if (c == '\n')
       *s++ = c;
    *s = '\0';
    return s - t;
}


char * alloc(int n){
    if (n <= allocbuff + ALLOCSIZE-allocp){
        allocp  =  allocp + n;
        return allocp - n;
    }
    else{
        printf("no enough room.\n");
        return NULL; // C guarantees that zero never weii be an address of data.
    }
}

// qsort: sort v[left]...v[right] into increasing order
void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)      // do nothing if array contains
        return;             // fewer than two elements
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}