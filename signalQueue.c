#include <stdio.h>
#include <signal.h>
#include <unistd.h>

struct sigaction sig_act;

int signalCounter = 0;

void signal_handler(int signum)
{
    signalCounter++;
}
void sigFunctionSet(void(*f)(int sig)) {
    sig_act.sa_handler = signal_handler;
    if(sigaction(10, &sig_act, NULL) == -1){
        printf("Can't catch signal \n");
    }
}

int main(void)
{
    printf("pid: %d\n",getpid());

    sigFunctionSet(signal_handler);

    while(1)
    {
        pause();
        printf(" Recieved %d signals\n", signalCounter);
    }

    return 0;
}

