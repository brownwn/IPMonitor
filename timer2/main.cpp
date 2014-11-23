#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>

void set_timer()
{
    struct itimerval itv;
    itv.it_interval.tv_sec = 2;
    itv.it_interval.tv_usec = 0;
    itv.it_value.tv_sec = 2;
    itv.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &itv, NULL);
}
void sigalrm_handler(int sig)
{
    printf("alrm  signal\n");
    sleep(1);
    printf("finish alrm signal~!\n");
}

int main()
{
   struct sigaction sigact;
   sigact.sa_flags = 0;
   sigact.sa_handler = sigalrm_handler;
   sigemptyset(&sigact.sa_mask);
   sigaction(SIGALRM, &sigact, NULL);

   set_timer();

   while ( getchar()!='a' ) ;
   return 0;
}
