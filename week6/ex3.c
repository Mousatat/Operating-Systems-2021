#include <stdio.h>

int processes[10000][4];
int t[3];

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int arrivalTime,burstTime;
        printf("Arrival time of process %d: ",i+1);
        scanf("%d",&arrivalTime);

        printf("Burst time of process %d: ",i+1);
        scanf("%d",&burstTime);
        processes[i][0] = arrivalTime;
        processes[i][1] = burstTime;
        processes[i][2] = i+1;
        processes[i][3] = burstTime;
    }
    int quantum;
    printf("Enter quantum number: ");
    scanf("%d",&quantum);
    //running the processes
    int currentTime=0;

    float totalTaT=0,totalWT=0;

    int cnt=0,doneSth=0;
    printf("P# CT TAT WT\n");
    while(cnt<quantum){
        doneSth=0;
        for(int i=0;i<n;i++){
            if(processes[i][1]>0&&currentTime>=processes[i][0]){
                doneSth=1;
                processes[i][1]--;
                currentTime++;
                if(processes[i][1]==0){
                    cnt++;
                    printf("P%d ",processes[i][2]);
                     printf("%d ",(currentTime));
                    printf("%d ",(currentTime-processes[i][0]));
                    printf("%d \n",(currentTime-processes[i][0]-processes[i][3]));
                    totalTaT+=(currentTime-processes[i][0]);
                    totalWT+=(currentTime-processes[i][0]-processes[i][3]);
                }
            }
        }
        if(!doneSth&&cnt<quantum)currentTime++;
    }
    totalTaT/=n;
    totalWT/=n;
    printf("Average Turnaround time :%f \n",totalTaT);
    printf("Average waiting time :%f \n",totalWT);
}
