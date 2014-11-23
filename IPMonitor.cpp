//ipmonitor implement
#include "IPMonitor.h"
#include <iostream>
using namespace std;
IPMonitor::IPMonitor(ipmon::nic_device nd)
{
    devname = nd.name.c_str();
    netmask = (int)nd.subnet_mask;
    ipaddress = nd.ip_addr;
    myHash.clear();
}
IPMonitor::~IPMonitor()
{

}
void IPMonitor::OpenDev()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    if(handle = pcap_open_live(devname, 65535, 1, 1000, errbuf))
    {
        cout << "open adapter success!" << endl;
    }else{
        cout << "open adpter failed!" << endl;
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
    const unsigned char* pkt_data;
    unsigned char ipproto;
    unsigned long ipsrc = 0;
    unsigned long ipdes = 0;
    while((res = pcap_next_ex(handle, &header, &pkt_data)) >= 0)
    {
        //if(time > limittime)
        //{
           // break;
        //}
        if(res == 0)
        {
            continue;
        }
        memcpy(&ipproto, pkt_data+23, 1);
        memcpy(&ipsrc, pkt_data+26, 4);
        memcpy(&ipdes, pkt_data+30, 4);
        if(ipaddress == ipsrc || ipaddress == ipdes)
        {
            MY_MAP::iterator itr;
            itr = myHash.begin();
            char c_ipproto[10];
            char c_ipsrc[10];
            char c_ipdes[10];
            sprintf(c_ipproto, "%c", ipproto);
            sprintf(c_ipsrc, "%lu", ipsrc);
            sprintf(c_ipdes, "%lu", ipdes);
            string s_ipproto = string(c_ipproto);
            string s_ipsrc = string(c_ipsrc);
            string s_ipdes = string(c_ipdes);
            string key = s_ipproto + s_ipsrc + s_ipdes;
            cout << key << endl;
            ipmon::record value;
            value.protocol = GetProtocol(ipproto);
            value.source = iptos(ipsrc);
            value.destination = iptos(ipdes);
            value.number = 1;
            cout << value.protocol  << endl;
            cout << value.source << endl;
            cout << value.destination << endl;

            itr = myHash.find(key);
            cout << "find" <<endl;
            if(itr != myHash.end())
            {
                cout << 222 << endl;
                //myHash[key] = value;
            }else{
                cout << 111 << endl;
                //myHash[key].number++;
            }
        }
    }
}
