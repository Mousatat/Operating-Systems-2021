#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int ipid = getpid();
    for(int i=0; i<5; i++)
    {
        fork();
        if(getpid()==ipid)
        {
            printf("\n");
            char command[50];
            int error = 0;
            strcpy( command, "pstree -c");
            error = system(command);
        }
    }
}
