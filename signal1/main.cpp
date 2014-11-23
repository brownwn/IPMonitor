#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void func(int sig)
{
    printf("I get a signal!\n");
}

int main()
{
    char buffer[100];
    if(signal(SIGINT, func) == SIG_ERR)
    {
        printf("signal error, exit now\n");
        exit(0);
    }
    printf("pid:%ld\n", (long)getpid());
    for(;;)
    {
        fgets(buffer, sizeof(buffer), stdin);
        printf("buffer:%s\n", buffer);
    }
    return 0;
}
