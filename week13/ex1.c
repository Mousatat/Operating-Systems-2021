#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *file;
    file=fopen("input.txt", "r");
    int *A,*C,*E,*R;
    int Process=0,lol = 0;
    E=calloc(10,sizeof(int)*lol);
    A=calloc(10,sizeof(int)*lol);
    C=(int*)malloc(lol*Process*sizeof(int));
    R=(int*)malloc(lol*Process*sizeof(int));
    int *status =calloc(0,sizeof(int)*Process);
    fscanf(file,"%d %d",&lol,&Process);
    for (int i=0; i<lol; i++)
        fscanf(file,"%d",&E[i]);
    for (int i=0; i<lol; i++)
        fscanf(file, "%d", &A[i]);
    for (int i=0; i<Process; i++)
        for (int j=0; j<lol; j++)
            fscanf(file,"%d",(C+i*lol+j));

    for (int i=0; i<Process; i++)
        for (int j=0; j<lol; j++)
            fscanf(file,"%d",(R+i*lol+j));

    while(true)
    {
        int IS=0;
        for (int i=0; i<Process; i++)
            if (status[i]==0)
                IS=IS+1;
        for (int i = 0; i < Process; i++)
        {
            if (status[i] == 0)
            {
                for (int j = 0; j < lol; j++)
                {
                    if (*(R + i * lol + j) - *(C + i * lol + j) - A[j] <= 0)
                        status[i] = 1;
                    else
                    {
                        status[i] = 0;
                        break;
                    }
                }
                if (status[i] == 1)
                {
                    for (int j = 0; j < lol; j++)
                        A[j] = *(C + i * lol + j) + A[j];
                    printf("Process %d has finished \n", i);
                    break;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < Process; i++)
        {
            if (status[i] == 0)
                count = count + 1;
        }
        if (count == 0)
        {
            printf("All processes are terminated");
            break;
        }
        if (IS - count == 0)
        {
            printf("Deadlocks as I think");
            break;
        }
    }
    return 0;
}
