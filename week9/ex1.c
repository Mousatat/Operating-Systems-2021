#include<stdio.h>


int pNum[500];
int pAge[500];

int main(){
    printf("Enter Buffer size: ");
    int bSize;
    scanf("%d",&bSize);
    FILE *fp;
    fp = fopen("test1.txt", "r");
    int x;
    int cnt=0;
    float hit=0,miss=0;
    while(fscanf(fp,"%d ",&x)!=EOF){
        for(int i=0;i<cnt;i++)pAge[i]>>=1;
        int fnd = 0;
        for(int i=0;i<cnt;i++)if(pNum[i]==x){
            fnd = 1;
            pAge[i]+=(1<<8);
            hit++;
            break;
        }
        if(!fnd){
            miss++;
            if(cnt<bSize){
                pNum[cnt]=x;
                pAge[cnt]=1<<8;
                cnt++;
            }
            else{
                int minInd,minAge = 1<<10;
                for(int i=0;i<cnt;i++){
                    if(pAge[i]<minAge){
                        minInd = i;
                        minAge = pAge[i];
                    }
                }
                pNum[minInd]=x;
                pAge[minInd]=(1<<8);
            }
        }
    }
    float ratio = hit/miss;
    printf("Hit/Miss : %f",ratio);
}
