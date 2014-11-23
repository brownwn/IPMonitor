#ifndef IPMONITOR_H
#define IPMONITOR_H

//ipmonitor class header

#include "common.h"
#include <map>
//using namespace std;
typedef map<string, ipmon::record> MY_MAP;
class IPMonitor
{
private:
    MY_MAP myHash;
    const char* devname;
    int netmask;
    unsigned long ipaddress;
    pcap_t* handle;
public:
    IPMonitor(ipmon::nic_device nd);
    ~IPMonitor();
    void OpenDev();
    void compilefilter();
    void Monitor();
};

#endif // IPMONITOR_H
