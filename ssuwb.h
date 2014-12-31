#ifndef SSUWB_H
#define SSUWB_H
#include "sslib.h"
#include "rcmIf.h"
#include "rcm.h"


class ssUWB
{
   // double
public:
    int dis[4];
    int* measure();
    ssUWB(int n,const int* ID,const char* filename);//n->num
    ssUWB();
    void initial();
private:
    int* nodes;//nodesID of each node
    int num;//num of node in location network
    char* dev;

    rcmIfType   rcmIf;
    rcmConfiguration config;
    rcmMsg_GetStatusInfoConfirm statusInfo;
    rcmMsg_RangeInfo rangeInfo;
    rcmMsg_DataInfo dataInfo;
    rcmMsg_ScanInfo scanInfo;
    rcmMsg_FullScanInfo fullScanInfo;
    int uwb(int destNodeId);
};



#endif // SSUWB_H
