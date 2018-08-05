/*
Exercise 4-10. An alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach.

又是计算器题，不想写计算器了。。。。。 算了 继续
思路： 从一次读一个改成 一下读一行。 但其实 读完一行，还是要一个个字符读，判断数字，还是运算符号等等。
所以在原计算机程序上稍稍修改一下即可。

*/


#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int sp = 0; /* stack position */
double val[MAXOP];

#define LINESIZE 100
char line[LINESIZE];
int line_p;


int getline(char line[], int maxline);
int getop(char [], char[]);
void push(double);
double pop();
int getch(void);
void ungetch(int);
void debug(int d);

void duplicate(void);
void show(void);
void swap(void);
void clear(void);


int main() {
    int type;
    char s[MAXOP];
    double op2;
  
    while (getline(line, LINESIZE) != 0) {
        line_p =0;
        while((type = getop(s, line)) != '\0'){
            // printf("%c", type);
            switch (type) {
                case NUMBER:
                    // printf("%g\n", atof(s));
                    push(atof(s));
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0) {
                        push(pop() / op2);
                    }
                    else {
                        printf("zero divisor error!\n");
                    }
                    break;
                case '%':
                    op2 = pop();
                    if (op2 != 0.0) {
                        push( fmod(pop(), op2));
                    }
                    else {
                        printf("zero divisor error!\n");
                    }
                    break;

                case 's':
                    show();
                    break;

                case 'd':
                    duplicate();
                    break;

                case 'w':
                    swap();
                    break;

                case 'c':
                    clear();

                case '\n':
                    printf("result: \t%.8g\n", pop());
                    break;
            }
        }

    }

    return 0;
    }


/* push: push f onto value stack */
void push(double f) {

    if (sp < MAXOP)
        val[sp++] = f;
    else
        printf("error: stack is full, can't push %g\n", f);   

}

/* pop: pop and return top value from stack */
double pop() {
    if (sp == -1) {
        printf("error: stack is null, can't pop\n");
        return 0.0;
    }
    else
        return val[--sp];
}

int getop(char s[], char line[]) {
    int i, c, neg;
    while ( ((s[0] = c = line[line_p++]) == ' ') || c == '\t')
        ;

    s[1] = '\0';
    

    if (!isdigit(c) && c != '.' && c !='-'){
        // putchar(c);
    
        return c;
    }
    
    else if (c=='-' &&   isdigit(c = line[line_p]) )
    {
        // this is a negative number
        neg=1;
    }
    else if (c == '-') {
        return c;
    }
    i=0;
    if (isdigit(c))
        while(isdigit(s[++i] = c = line[line_p++]))
            ;
    if (c == '.')
        while(isdigit(s[++i] = c = line[line_p++]))
            ;
    s[i] = '\0';
    // putchar(s[0]);
    line_p--;
    return NUMBER;    // signal that a number is found.
}


int getch(void) {
    int i;
    // i = (buf > 0) ? buf[--bufp] : getchar();
    return (bufp > 0) ? buf[--bufp] : getchar();
    // return i;
}

void ungetch(int c) 
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    }
    else
        buf[bufp++] = c;
}

void debug(int d) {
    printf("running here! value is  %d \n", d);
}


void duplicate(void) {
    double temp = pop();
    push(temp);
    push(temp);
}
void show(void) {
    //show function.
    if (sp > 0)
    printf("show top elements in stack:    %.8g\n", val[sp-1]);
    else
        printf("the stack is empty! \n");
}
void swap(void) {
    double temp1 = pop();
    double temp2 = pop();
    push(temp1);
    push(temp2);
}
void clear(void) {
    sp=0;
}

/* getline: read a line into s, return length */
int getline(char s[],int lim) {
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}