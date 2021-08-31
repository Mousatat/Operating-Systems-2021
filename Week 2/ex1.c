#include<stdio.h>
#include<limits.h>
#include<float.h>

int main()
{
    int I;
    float F;
    double D;
    I = INT_MAX;
    F = FLT_MAX;
    D = DBL_MAX;
    printf("%d : %d\n%G : %d \n%G : %d \n",I,sizeof(I),F,sizeof(F),D,sizeof(D));
}
