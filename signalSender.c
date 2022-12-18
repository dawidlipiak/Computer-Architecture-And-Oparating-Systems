#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main (void){
    int pid;
    printf("Podaj pid procesu: ");
    scanf("%d",&pid);

    for(int i = 0; i <= 10000; i++){
        kill(pid, 10);

    }
    kill(pid, 9);
    return 0;
}
