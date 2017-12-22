/*
Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full
generality.)


解法：
    我是这么思考的。
    括号的性质：
        1. 对称   2. 不能互相乱插（你懂的）
    所以得寻找一个满足这两种性质的建模的模型。
    我记得应该用 二叉树，或 stack 来实现，但是我决定不用这些magic tool。
    这就意味着我必须用数组（我只有这个模型）自己设计一种机制，满足以上性质。
    偶数数组对半分，满足 |对称性| 。
    对称位置符号一样满足 |不乱插| 。

    对待非括号型字符，就跳过不予录入。
    "" '' 同理，懒得写了。
*/

#include <stdio.h>
#define MAXLEN 10
#define RIGHT 1
#define WRONG 0
int main() {
    // char *right_test = "(({{}}))\0";
    // char *wrong_test = "([({]}))";
    char *wrong_test = "(({{}}))";
    char result[MAXLEN];
    int i = 0;
    int k = 0;
    int j = MAXLEN /2;

    
    while (wrong_test[i] != '\0') {
        // putchar(wrong_test[i]);
        if (wrong_test[i]=='(' || wrong_test[i]=='[' || wrong_test[i]=='{'){
            result[k] = wrong_test[i];
            k++;
            
        }
        else if(wrong_test[i]==')' || wrong_test[i]==']' || wrong_test[i]=='}' ) {
            result[j] = wrong_test[i];
            j++;
        }
        else {
            continue;
        }
        i++;

    }
    for(int i=0;i<MAXLEN;i++)
        printf("%c", result[i]);

    // check 
    int state = RIGHT;
    int reverse = MAXLEN / 2 + (k-1);
    printf("k is %d\n", k);
    for(int index=0;index < k; index++) {
        // printf("%c",result[index+delta]);
        int left = result[index];
        int right = result[reverse - index];
        
        if (left=='(') {
            if((left+1) != right)
                state = WRONG;
        }
        else if(left=='[') {
            if((left+2) != ']')
                state = WRONG;
        }
        else if(left=='{'){
            if((left+2) != '}')
                state =WRONG;
        }

        // if (result[index] != result[reverse - index]){
        //     printf("left is %c,    right is %c \n", result[index], result[reverse - index]);
        //     state = WRONG;
        // }

    }

    if (state == RIGHT) {
        printf("Right!");
    }
    else{
        printf("Wrong!");
    }

    return 0;
}