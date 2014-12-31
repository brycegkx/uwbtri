#include "sslib.h"
#include "gkxlocate.h"
#include "ssuwb.h"

int main()
{

    int* dis;
    double* pos;
     gkxLocate locate(4);   //initial 4 points locate algo parameter
     ssUWB uwb;             //
    sstimer timer;
    //ssfile file("test1.txt");

    while(1)
    {

      //  timer.start();

        dis=uwb.measure();

        pos=locate.locate(dis);

//        for(int i=0;i<4;i++)
//            dis[i]=i;
//        for(int i=0;i<3;i++)
//            pos[i]=0.0;e

        //timer.end("uwb position:");

        //file.add(dis,pos);
        //or you can set another file, then add something to it:
        //e.g,: file.setfile("tmp.txt"); file.add(dis,pos);
        //or you can add some flags to file. e.g. file.add("this is a new record!")
    }

    return 0;
}

