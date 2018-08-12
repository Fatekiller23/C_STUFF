/*
Exercise 5-13. Write the program tail, which prints the last n lines of its input. By default, n
is set to 10, let us say, but it can be changed by an optional argument so that
tail -n
prints the last n lines. The program should behave rationally no matter how unreasonable the
input or the value of n. Write the program so it makes the best use of available storage; lines
should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of
fixed size.

--argc > 0 && (*++argv)[0]=='-'
put this condition into a idiom.

我突然有个想法，比如说如果 n=22，那我直接从结尾符里面开始找，找到第22个，然后顺序打印出来不就行了，这我还
存个瘠薄？

正规解法，存到相应的数组指针里，数组里每一个指针指的是输入的一行。
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 100
#define MAXSTORE 10000
#define MAXLEN 1000 /* max length of any input line */
char * lineptr[MAXLINE];


int my_readlines(char *lineptr[], int maxlines, char* line_storage);
int getline(char * s, int lim);
void writelines(char *lineptr[], int nlines, int jump);

int main(int argc, char const *argv[])
{

    int c;
    char lines[100];
    char *p=lines;
    int last_lines;
    // get optional argument.
    if (--argc > 0 && (*++argv)[0]=='-'){
        int i=1;
        while(c=(*argv)[i++]) {
            if (isdigit(c)) {
                *p++ = c;
            }
            else if (c==' '){
                putchar('b');
                break;
            }
            else {
                printf("%s", "error, illegal arguments");
                return 0;
            }

        }
        *p='\0';
        last_lines = atoi(lines);

        // printf("%d", last_lines);
    }
    else {
        printf("%s", "error, no legal arguments");
        return -1;
    }

    // store input data.
    int nlines;
    char line_storage[10000];
    if ((nlines=my_readlines(lineptr, MAXLINE, line_storage))>0){
        ;
    }
    else{
        printf("wrong");
        return 1;
    }

    // show last n lines of input data.
    writelines(lineptr, nlines, last_lines);

    return 0;
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

void writelines(char *lineptr[], int nlines, int jump) {
    if (jump>nlines){
        jump=nlines;
    }
    int i;
    for (i = nlines-jump; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
