#include<stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    int *arr = (int*)calloc(N, sizeof(int));
    for(int i=0;i<N;i++)arr[i]=i;
    for(int i=0;i<N;i++)printf("%d \n",arr[i]);
    free(arr);
}
