#include "sslib.h"

void sstimer::start()
{
    gettimeofday(&starttime,0);
}

double sstimer::end(char * flag)
{
    gettimeofday(&endtime,0);
    timeuse = 1000000*(endtime.tv_sec - starttime.tv_sec) + endtime.tv_usec - starttime.tv_usec;
    timeuse /=1000;
    cout<<flag<<"Frequency: "<<1000/timeuse<<endl;
    return timeuse;
}

void ssfile::setfile(char * s)
{
    name=s;
    //counter=1;
    record();
}

void ssfile::add(int *dis, double *pos)
{
    ofile.open(name,ios::app);
    for (int i=0;i<4;i++)
        ofile<<dis[i]<<' ';
    for (int i=0;i<3;i++)
        ofile<<pos[i]<<' ';
    ofile<<endl;
    ofile.close();
}
ssfile::ssfile(char * s)
{
    name=s;
    //record();
}
void ssfile::record()
{

    ofile.open(name,ios::app);
    ofile<<"This is a new record!"<<endl;
    ofile.close();
}
void ssfile::add(char *flags)
{
    ofile.open(name,ios::app);
    ofile<<flags<<endl;
    ofile.close();
}
