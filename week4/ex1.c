#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
    int n=10;
    int ipid = getpid();
    printf("\n");
    fork();
    if(getpid()==ipid)printf("Hello from parent %d \n",(getpid()-n));
    else printf("Hello from child %d \n",(getpid()-n));
}
