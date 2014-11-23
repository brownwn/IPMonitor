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
    char buffer[100];\
    struct sigaction act;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    if(sigaction(SIGINT, &act, NULL) == -1)
    {
        printf("sigaction error , exit now\n");
        exit(0);
    }
    printf("pid :%ld\n", (long)getpid());

    for(;;)
    {
        fgets(buffer, sizeof(buffer), stdin);
    }
    return 0;
}
