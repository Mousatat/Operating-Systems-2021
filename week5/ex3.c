#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int COUNT = 0;
int PC = 0;
int CM = 10;
int KKKK = 1;
int PA=0;
int CS=0;

void *producer(void *vargp)
{
    printf("started producer\n");
    while(1)
    {
        PC++;
        if(PC>100)
        {
            printf("100 iterations complete\n");
            PC=0;
        }
        if(COUNT==CM)PA=1;
        while(PA)
        {
            if(PA&&CS)
            {
                printf("dead lock reached\n");
                return 0;
            }
        }
        COUNT++;
        if(COUNT>0)CS = 0;
    }
}

void *consumer(void *vargp)
{
    printf("started consumer\n");
    while(1)
    {
        if(COUNT==0)CS=1;
        while(CS)
        {
            if(PA&&CS)
            {
                printf("dead lock reached\n");
                return 0;
            }
        }
        COUNT--;
        if(COUNT<CM)PA = 0;
    }
}

int main()
{
    pthread_t TID;
    pthread_t TID1;
    pthread_create(&TID, NULL, producer, (void *)&TID);
    pthread_create(&TID, NULL, consumer, (void *)&TID);
    pthread_exit(NULL);
    return 0;
}
