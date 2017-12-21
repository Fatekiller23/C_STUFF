/*
Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.

Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
in its input.

solution:
    i solved this problem by two step: 1. calculus. 2. draw.

vertical version is challenging, however, i choose to go ahead. i think using a nested arrray represents 
a printing-Matrix , which its value 0 is ' ', 1 is '#', should work.

*/

#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define W_LENGTH 26 /* the  range between counts per word */
#define SCALE 2.0   /* scale  SCALE times than original grapsh */ 
#define BAR_LENGTH 20 /* use how many bar to print full sclae */
#define PERCENT 100 /* change to percent% format */

/* count lines, words, and characters in input */
int main() {
    // declaration.
    int c,counter,state,sum;
    int characters_per_word[W_LENGTH];
    int standardization[W_LENGTH];
    float percent[W_LENGTH];
    
    // initialization.
    state = OUT;
    counter = 0;
    for (int i=0;i<W_LENGTH;i++)
        characters_per_word[i] = 0;

    // calculus
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
        state = OUT;
        characters_per_word[counter] += 1;
        counter = 0;
        continue;
        }
        else if (state == OUT) {
        state = IN;
        }
        ++counter;

    }

    sum = 0;
    for (int i=0; i< W_LENGTH; i++)
        sum = sum + characters_per_word[i];
    sum = sum / SCALE;

    // printf("%d", sum);
    
    // standardization
    for (int i=0;i<W_LENGTH;i++) {
        percent[i] = (characters_per_word[i]*1.0 / sum) * PERCENT;
        standardization[i] = (characters_per_word[i]*1.0 / sum) * BAR_LENGTH;
        // printf("|%d, sum %d, res: %f\n", characters_per_word[i], sum, characters_per_word[i]/(sum*1.0));
    }
    putchar('\n');

    // heading
    printf(" counts per word, by histogram ^_^\n\n");


    // drawing histogram graph.
    for (int i=0;i<W_LENGTH;i++) {
        if (standardization[i] == 0)
            continue;

        // print y-axis.
        int quotient, remainder_n;
        quotient = i / 10;
        remainder_n = i % 10;
        printf("    ");
        putchar('0'+ quotient);
        putchar('0' + remainder_n);
        printf(": ");

        // print bars.
        for (int j=0; j<standardization[i];j++){
            printf("#");
        }
        putchar(' ');
        printf("%2.2f%%", percent[i]);
        printf("\n\n");
    }
    return 0;
}