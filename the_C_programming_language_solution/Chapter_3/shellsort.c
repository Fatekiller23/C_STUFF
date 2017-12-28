/*
implement shell sort.

shell sort 的有效性就是保证每一个gap下的这一坨，都是增序的。
这样 当 gap为1的时候，就是一个简单的插值排序。
当gap大的时候，就可以提前比较大数，将其放到后面去。
*/
#include <stdio.h>

void shellsort(int v[], int n);
void shellsort_me(int v[], int n);

int main() {
    int array[9] = {23,30,14,29,40,18,11,37,19};
    // shellsort(array, 9);
    shellsort_me(array, 9);
    for(int i=0;i<9;i++)
        printf("%d,", array[i]);
    return 0;
}




/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}


void shellsort_me(int v[], int n) {
    int gap,i,j,temp;
    for (gap=n/2;gap>0;gap/=2) {
        // printf("gap is %d\n", gap);
        for (i=gap;i<n;i++){
            // printf("i is %d\n", i);
            for(j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){
                // printf("pair is (%d,%d)\n",v[j],v[j+gap]);
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }   
    }
}