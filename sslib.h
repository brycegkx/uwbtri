#ifndef SSLIB_H
#define SSLIB_H

#define SS_DEBUG

#include <time.h>
#include <sys/time.h>
#include <iostream>
#include<fstream>
using namespace std;

class sstimer
{
public:
    void start();
    double end(char *);
private:
    timeval starttime,endtime;
    double timeuse;
};


class ssfile
{
public:
    ssfile(char *);
    void setfile(char *);
    void add(int*, double*);
    void add(char *);
private:
    ofstream ofile;
    const char* name;
    //int counter;
    void record();
};


#endif // SSLIB_H
