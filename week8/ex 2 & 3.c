#include<stdio.h>
#include <unistd.h>


int main(){
    for(int i=0;i<50;i++){
        memset(malloc(104857600),0,104857600);
        sleep(1);
    }
}
/*
Ex2
Ran the code on a VM but had to increase it to 100mb/s for 100s to fill the memory and start using swap, though it evetually filled everything and the process was killed.
*/

/*
Ex3
CPU usage of the process was low (~2.5%) but the memory usage kept increasing till it reach 70%+ and the VM froze then the process was killed.
*/
