/*
Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and
measure the difference in run-time.

我深深觉得此题有毒！！！！
应该是在目前的笔记本上，速度已经快到分不出来了。但是不理解为什么超过MAX超过100000,应该是一个int
数组一次只让分配这么多的内存。超过了就溢出了。

经测试，循环内少判断，所用时间反而较长。
我认为可能的解释是：因为循环内判断少，所以让每一次循环的递进更慢，因此造成循环次数更多的现象。
in couter 16 次循环 
out counter 17次循环，且外面还有若干判断语句。所以会较慢。
*/
#include <stdio.h>
#include <time.h>

#define MAX 100000
#define TIMES 1000000
int binsearch_in_test(int x, int v[], int n);
int binsearch_out_test(int x, int v[], int n);

int main() {
    // initialization.
    clock_t time_taken_1, time_taken_2;
    int test_data[MAX];
    for(int i=0;i<MAX;i++)
        test_data[i] = i;

    // times
    int index_in,index_out;
    int i,j;
    for (i=0,time_taken_1=clock();i<TIMES;i++) {
        index_in = binsearch_in_test(-1, test_data, MAX);

    }
    time_taken_1 = clock() - time_taken_1;
    
    for (j=0,time_taken_2=clock();j<TIMES;j++) {
         index_out = binsearch_out_test(-1, test_data, MAX);
    }
    time_taken_2 = clock() - time_taken_2;

    // results
    printf("index is %d,  many test inside loop used: %lu clocks, seconds:%f\n", index_in,(unsigned long)time_taken_1,(double)time_taken_1/CLOCKS_PER_SEC);
    printf("index is %d,  less test inside loop used: %lu clocks, seconds:%f\n", index_out,(unsigned long)time_taken_2,(double)time_taken_2/CLOCKS_PER_SEC);
    return 0;
    // int some[10] = {0,1,2,3,4,5,6,7,8,9};
    // int index = binsearch_out_test(9,some,10);
    // printf("%d", index);
}




/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch_out_test(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    int counter=0;
    while (low < high) {
        mid = (low+high)/2 + 1;
        if (x < v[mid]){
            high = mid -1 ;
        }
        else {
             low = mid;
        }
        counter++;
    }
    // printf("out counter: %d\n", counter);
    if (x == v[mid]) {
        return mid;
    }
    else
        return -1; /* no match */
}



/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch_in_test(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    int counter=0;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */{
            // printf("in counter: %d\n", counter);
            return mid;
        }
 
        counter++;
    }
    // printf("in counter: %d\n", counter);
    return -1; /* no match */
}