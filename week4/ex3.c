#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    while(true)
    {
        char command[50];
        scanf("%s\n", command);
        system(command);
    }
}
