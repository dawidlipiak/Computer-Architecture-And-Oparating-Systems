#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int signalCounter = 0;

void signal_handler(int signum)
{
    printf(" Recieved signal %d\n", signum);
    signalCounter++;
}

int main(void)
{
    signal(SIGUSR1, signal_handler);

    for(int i = 0; i < 5; i++)
    {
        printf("Sending signal SIGUSR1\n");
        raise(SIGUSR1);
        sleep(1);
    }

    printf("Recieved %d signals SIGUSR1\n", signalCounter);

    return 0;
}

