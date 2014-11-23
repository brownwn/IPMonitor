#include <unistd.h>
#include <signal.h>
#include <iostream>
using namespace std;

void sigalarm_handler(int signal_number)
{
    cout << "Hello world\n";
}

int main()
{
    sigset(SIGALRM, sigalarm_handler);
    alarm(10);
    while (1);
    return 0;
}

