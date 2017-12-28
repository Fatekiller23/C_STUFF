/*
Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally

关键是要描述出a-c这种模式来，一个索引不够就上n个，总是可以获取足够的信息的。
*/

#include <stdio.h>
#include <ctype.h>

#define MAX 100000

void expand(char s1[],char s2[]);


int main() {
    char s1[MAX]="1.a-z  2.A-Z 3.0-9 4.-a-b-c- 5.a-z0-9-";
    // char s1[MAX]="0-9-";
    char s2[MAX]; 
    expand(s1,s2);
    return 0;
}


void expand(char s1[],char s2[]) {
    int i=0;
    // putchar('1');
    for(i=0;s1[i] != '\0';i++) {   
        int now = s1[i];
        int next = s1[i+1];
        int next_next = s1[i+2];
        // printf("now:%c,next %c,next_next %c\n", s1[i],s1[i+1],s1[i+2]);
        // 如果是数字，计算模式持续多久，开启数字打印循环，跳过若干
        if (next=='-'&& now >= 48 && now<=57 && next_next-now<=9) {
            int range=next_next-now;
            // printf("%d", range);
            int counter=0;
            for(int j=i+3;s1[j]=='-'&&s1[j+1]-now <=9&&isdigit(s1[j+1]);j+=2){
                // printf("%d %c     %d",,now);
                range = s1[j+1] - now;
                counter++;
            }

            for(int s=0;s<=range;s++)
                putchar(now+s);
            // putchar('\n');
            i+=(2*counter)+2;
            continue;
        }
        
        // 如果是字母，计算模式持续多久，开启字母打字循环，跳过若干
        if (next=='-'&& now >= 65 && next_next-now<=26) {
            int range=next_next-now;
            int counter=0;
            for(int j=i+3;s1[j]=='-'&&s1[j+1]-now <=26&&isalpha(s1[j+1]);j+=2){
                range = s1[j+1] - now;
                counter++;
            }

            for(int s=0;s<=range;s++)
                putchar(now+s);
            // putchar('\n');
            i+=(2*counter)+2;
            continue;
        }

        // 都不是则打印这个
        // i++;
        putchar(now);
        // putchar('\n');
    }
}