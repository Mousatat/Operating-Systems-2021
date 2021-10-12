#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>


int main(){
struct rusage r_usage;
for(int i=0;i<10;i++){
    memset(malloc(1048576),0,1048576);
    int ret = getrusage(RUSAGE_SELF,&r_usage);
    sleep(1);
    if(ret == 0)
         printf("Memory usage: %ld kilobytes\n",r_usage.ru_maxrss);
      else
         printf("Error in getrusage. errno = %d\n", errno);
    }
}
