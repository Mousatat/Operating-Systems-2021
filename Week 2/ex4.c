#include<stdio.h>


void defNotSwap(int *x, int *y)
{
    int z = *y;
    *y = *x;
    *x = z;
}


int main()
{
    int A;
    int B;
    scanf("%d %d",&A,&B);
    defNotSwap(&A,&B);
    printf("%d %d\n",A,B);
}
