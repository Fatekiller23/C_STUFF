/*
Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.
*/

/*
怎样从文件中导入字符串？
cmd 中 用 < 重定向符
*/

#include <stdio.h>
#define MAXLEN 100000
#define BACKSLASH 47

int main(){
    int first, second, now;
    first = ' ';
    second = ' ';
    int inline_comment = 0;
    int multipli_comment = 0;
    int count =0 ;
    while ((now = getchar()) != EOF ) {
        // count += 1;
        // if (count < 2){
        //     continue;
        // }
        // 如果两个falg都是0，则打印该字符，若不是0 则跳过该字符。
        // printf("last : %c | c : %c | inline: %d | multiple: %d \n", last,c,inline_comment,multipli_comment);
        if (multipli_comment == 0 && inline_comment == 0) {
            // 判断 inline comment 的条件
            if (first == BACKSLASH && second == BACKSLASH ){
                inline_comment = 1;
            }
            // 判断  multipli comment  的 条件
            if (first == BACKSLASH && second == '*'){
                multipli_comment = 1;
            }
        }
        else if (multipli_comment == 1){
            if (first =='*' && second == BACKSLASH){
                multipli_comment = 0;
            }
        }
        else if (inline_comment == 1){
            
            if (second == '\n'){
                // printf("2\n");
                inline_comment =0;
                // last = getchar();
            }
        }


        // 如果两个falg都是0，则打印该字符，若不是0 则跳过该字符。
        if (multipli_comment == 0 && inline_comment == 0) {
            printf("%c", now);
            // printf("output!");
        }

        first = second;
        second = now;
    }
}