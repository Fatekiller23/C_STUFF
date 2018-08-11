/*
Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of
indexing.
*/
#include <stdio.h>
int day_of_year(int , int , int );
void month_day(int , int , int *, int *);

static char daytab[2][13] = {
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


int main()
{
    /* code */
    int some = day_of_year(1994, 1, 1);
    printf("result should be 1:\n%d\n", some);

    int yearday = 61; /* 2000-03-01 */
    int month, day;
    month_day(2000, yearday, &month, &day);
    printf("result should be 3 1:\nmonth_day: %d %d\n", month, day);

    return 0;
}




/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    // if (month<1 || month>12 || day<1 || day>daytab[leap][month] ){

    if (month<1 || month>12 || day<1 || day>*(*(daytab+leap)+month) ){
        return -1;
    }

    for (i = 1; i < month; i++)
        day += *(*(daytab+leap)+i);
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    if (year < 1) {
        printf("error!");
    return;
    }

    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (leap==0) {
        if (yearday<1||yearday>365){
            printf("error!");
        }

    }
    else {
        if (yearday<1||yearday>366) {
            printf("error!");
        }
    }

    for (i = 1; yearday > *(*(daytab+leap)+i); i++)
        yearday -= *(*(daytab+leap)+i); 
    *pmonth = i;
    *pday = yearday;
}