#include<stdio.h>

int main(int argc, char** argv)
{
    int n;
    sscanf(argv[1],"%i",&n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)printf(" ");
        for(int j=0; j<i; j++)printf("*");
        printf("*");
        for(int j=0; j<i; j++)printf("*");
        printf("\n");
    }
}
