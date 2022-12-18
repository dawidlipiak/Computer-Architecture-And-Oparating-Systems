#include <signal.h>
#include <stdio.h>
#include <string.h>

void signal_handler(int signum)
{
    printf(" Recieved signal %d (%s)\n", signum, strsignal(signum));
}

int main (void)
{
    for(int i = 1; i <= 64; i++)
    {
        signal(i, signal_handler);
    }
    
    pause();

    return 0;
}
