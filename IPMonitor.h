#ifndef IPMONITOR_H
#define IPMONITOR_H

//ipmonitor class header

#include "common.h"
typedef map<string, record> MY_MAP;
class IPMonitor
{
private:
    MY_MAP myHash;
    char* devname;
    pcap_t* handle;
public:
    IPMonitor();
    ~IPMonitor();
    void OpenDev();
    void compilefilter();
    void Monitor();
};

#endif // IPMONITOR_H
