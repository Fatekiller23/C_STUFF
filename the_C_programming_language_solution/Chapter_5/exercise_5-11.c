/*
Exercise 5-11. Modify the program entab and detab (written as exercises in Chapter 1) to
accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.

接受一个 列表的 tab停，做为参数， 使用默认的，如果没参数。
啥意思。。。。
比如，如果有 entab a
就会把 空格换成 a+' '?
但是如果传了一个列表进来呢？ 不如 entab a b
那就是空格 换成 ab+' '? 关键还是要搞明白他所谓的 tab stop 是个什么。

从以前的练习来看，此处的tab stop 应该就是\t

啊，懂了。我理解意思是，detab 就是 以参数为 标志位。

*/

#define MAXLEN 100
#define SPACE 8
#include <stdio.h>
#include <string.h>

// detab.
int main(int argc, char* argv[]) {
    int c, last=0;    // last 用来记录上一个字符是否是\t, 如果是，就不重复输出空格了。
    char result[MAXLEN];
    int i = 0;
    int input;
    if (argc>1){
        input =1;
    }
    else
        input=0;

    while ( (c=getchar()) != EOF ){
        if (c != '\t'){
            result[i] = c;
            ++i;
            last = 0;
        }
        else {
            if (last == 0){

                if (input == 1){
                    int len = strlen(argv[1]);
                    strcpy(result+i, argv[1]);
                    i = i+ len;                    
                }
                else {
                    for (int j=0;j<SPACE;++j)
                    {
                        result[i] = ' ';
                        ++i;
                    }
                }
                last = 1;
            }
        }
    }
    printf("%s", result);
    return 0;
}

//=============================================================================================//

// // entab.
// int main(int argc, char* argv[]) {
//     char result[MAXLEN];
//     char c;
//     int index=0;
//     int spaces, tabs;

//     while ((c = getchar()) != EOF && c!='\n'){

//         if (c == ' ') {
//             int counts = 1;

//             while ((c=getchar()) == ' ' ){
//                 counts += 1;
//             }

//             if (argc>1){

//                 int tab_stop_len = strlen(argv[1]);
//                 spaces = counts % tab_stop_len;
//                 tabs = counts / tab_stop_len;
//                 printf("%d----user tabs \n%d ----- spaces\n", tabs, spaces);
//                 // add user tabs
//                 for (int i = 0; i < tabs; i++){
//                     strcpy(result+index, argv[1]);
//                     index=index+tab_stop_len;
//                 }

//                 // add user spaces
//                 for (int i = 0; i < spaces; i++){
//                     result[index] = ' ';
//                     index++;
//                 }

//             }
//             else{

//                 spaces = counts % SPACE;
//                 tabs = counts / SPACE;

//                 printf("%d----tabs \n%d ----- spaces\n", tabs, spaces);
//                 // add tabs
//                 for (int i = 0; i < tabs; i++){
//                     result[index] = '\t';
//                     index++;
//                 }

//                 // add spaces
//                 for (int i = 0; i < spaces; i++){
//                     result[index] = ' ';
//                     index++;
//                 }
                
//             }


//             result[index] = c;
//             index++;
//         }
//         else {

//             result[index] = c;
//             index++;
//         }
//     }
//     result[index] = '\0';
//     printf("%s\n", result);
// }

