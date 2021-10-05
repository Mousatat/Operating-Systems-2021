#include<stdio.h>

int ar[40];

int main(){
    ar[0]=1;
    ar[1]=1;
    for(int i=2;i<40;i++){
        ar[i]=ar[i-1]+ar[i-2];
    }
    for(int i=0;i<40;i++)printf("%d\n",ar[i]);
}
