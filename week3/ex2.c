#include <stdio.h>

void  bubble_sort(int arr[],int n){
    int d=0;
    while(!d){
        d=1;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                int t = arr[i];
                arr[i] = arr[i+1];
                arr[i+1]=t;
                d=0;
            }
        }
    }
}

int main(){
    int X;
    scanf("%d",&X);
    int a[10000];
    for(int i=0;i<X;i++){
        scanf("%d",&a[i]);
    }
    bubble_sort(a,X);
    for(int i=0;i<X;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
