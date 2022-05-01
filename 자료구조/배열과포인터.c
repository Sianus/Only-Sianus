#include <stdio.h>

void print1(int *ptr, int row){
    int i;
    for(i=0; i<row; i++){
        printf("%8u %5d\n", ptr+i, *(ptr+i));
    }
}

int main()
{
    int a[5]= {0,1,2,3,4};
    print1(a,5);
    return 0;
}