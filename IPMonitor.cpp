//ipmonitor implement
#include "IPMonitor.h"
#include <iostream>
using namespace std;
IPMonitor::IPMonitor(nic_device nd)
{
    devname = nd.name.c_str();
    netmask = (int)nd.subnet_mask;
}
IPMonitor::~IPMonitor()
{

}
void IPMonitor::OpenDev()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    if(handle = pcap_open_live(devname, 65535, PCAP_OPENFLAG_PROMISCUOUS, 1000, errbuf) == NULL)
    {
        cout << "open adapter error!" << endl;
    }
}
void IPMonitor::compilefilter()
{
    char packet_filter[] = "ip";
    struct bpf_program fcode;
    pcap_compile(handle, &fcode, packet_filter, 1, netmask);
    pcap_setfilter(handle, &fcode);
}
void IPMonitor::Monitor()
{
    int res;
    struct pcap_pkthdr* header;
    unsigned char* pkt_data;
    unsigned char ipproto;
    unsigned long ipsrc = 0;
    unsigned long ipdes = 0;
    while((res = pcap_next_ex(handle, &header, &pack_data)) >= 0)
    {
        if(time > limittime)
        {
            break;
        }
        if(res == 0)
        {
            continue;
        }
        memcpy(&ipproto, pkt_data+23, 1);
        memcpy(&ipsrc, pkt_data+26, 4);
        memcpy(&ipdes, pkt_data+30, 4);

    }

}
