#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int COUNT = 0;
int KKKK = 1;

void *Threader(void *vargp)
{
    printf("This is thread #%d \n",COUNT);
    KKKK=1;
}

int main()
{

    int n;
    scanf("%d",&n);
    pthread_t ;

    for (int i = 0; i < n; i++)
    {
        while(!KKKK);
        KKKK = 0;
        printf("Thread #%d got created \n",++COUNT);
        pthread_create(&, NULL, Threader, (void *)&);
    }

    pthread_exit(NULL);
    return 0;
}
