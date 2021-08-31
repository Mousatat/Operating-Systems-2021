#include<stdio.h>

int main(){
    char S[1009];
    scanf("%s",S);
    char rS[1009];
    for(int i=0;i<strlen(S);i++){
        rS[i] = S[strlen(S)-i-1];
    }
    printf("%s \n",rS);
}
