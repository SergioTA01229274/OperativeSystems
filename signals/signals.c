#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void  signalHandler(int signalNumber) {
    printf("Signal receieved %d \n", signalNumber);
}

int main(){
    int pid;
    signal(10, signalHandler);
    pid = fork();
    if(pid == 0){
        printf("Soy el hijo\n");

        for(;;);
    }else{
        printf("Soy el padre\n");
        kill(pid, 10);
        for(;;);
    }
}