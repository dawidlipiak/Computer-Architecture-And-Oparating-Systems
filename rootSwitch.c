#include <unistd.h>	
#include <sys/types.h>
#include <grp.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (setuid(0) != 0) {
        perror("Setuid failed");
        return 1;
    }
    system("/bin/bash");

    return 0;
}
