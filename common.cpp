#include "common.h"

char* iptos(u_long in)
{
    static char output[12][3*4+3+1];
    static short which = 0;
    u_char* p = (u_char *)&in;
    which = (which + 1 == 12 ? 0 : which + 1);
    snprintf(output[which], sizeof(output[which]), "%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
    return output[which];
}

char* mactos(u_char* in)
{
    static char output[12][12*6+5+1];
    static short which = 0;
    which = (which + 1 == 12 ? 0 : which + 1);
    snprintf(output[which], sizeof(output[which]),
        "%02X-%02X-%02X-%02X-%02X-%02X", in[0], in[1], in[2], in[3], in[4], in[5]);
    return output[which];
}
