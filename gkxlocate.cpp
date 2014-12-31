#include "gkxlocate.h"
#include "sslib.h"
#include <math.h>
#include <iostream>
using namespace std;

double* gkxLocate::locate(const int *dis)
{
    //Caculate different distances between anchors
    double d1=(double)dis[0]/1000;
    double d2=(double)dis[1]/1000;
    double d3=(double)dis[2]/1000;
    double d4=(double)dis[3]/1000;
    //For solving position
    double D1=0.0;
    double D2=0.0;
    double D3=0.0;

    double x=0.0;
    double y=0.0;
    double z=0.0;

    double DELTA;
    double DDELTA;  //DDELTA=1/DELTA
    double DELTA_X;
    double DELTA_Y;
    double DELTA_Z;

    D1 = 0.5*(pow(d1,2) - pow(d2,2) + d21_sqr);
    D2 = 0.5*(pow(d1,2) - pow(d3,2) + d31_sqr);
    D3 = 0.5*(pow(d1,2) - pow(d4,2) + d41_sqr);

    DELTA = a1*b2*c3 + a2*b3*c1 + a3*b1*c2 - a1*b3*c2 - a2*b1*c3 - a3*b2*c1;
    DDELTA = 1 / DELTA;

    DELTA_X = D1*b2*c3 + D2*b3*c1 + D3*b1*c2 - D1*b3*c2 - D2*b1*c3 - D3*b2*c1;
    DELTA_Y = a1*D2*c3 + a2*D3*c1 + a3*D1*c2 - a1*D3*c2 - a2*D1*c3 - a3*D2*c1;
    DELTA_Z = a1*b2*D3 + a2*b3*D1 + a3*b1*D2 - a1*b3*D2 - a2*b1*D3 - a3*b2*D1;

    x = xr[0] + DELTA_X * DDELTA;
    y = yr[0] + DELTA_Y * DDELTA;
    z = zr[0] + DELTA_Z * DDELTA;

    uwb_pos[0] = x;
    uwb_pos[1] = y;
    uwb_pos[2] = z;

#ifdef SS_DEBUG
    for (int i=0;i<3;i++)
        cout<<uwb_pos[i]<<" ";
    cout<<endl;
#endif

    return uwb_pos;
}

gkxLocate::gkxLocate(int n)
{
    num=n;

//    xr=new double(4);
//    yr=new double(4);
//    zr=new double(4);

    //Indoor test triangle
    //ID1
    xr[0]= -3.96;
    yr[0]= -3.442;
    zr[0]= 0.312;

    //ID2
    xr[1]= -3.512;
    yr[1]= 3.992;
    zr[1]= 2.27;

    //ID3
    xr[2]= 4.426;
    yr[2]= 2.448;
    zr[2]= 0.288;

    //ID4
    xr[3]= 3.5;
    yr[3]= -3.89;
    zr[3]= 2.258;

    a1=xr[1]-xr[0];	//a1=xr2-xr1
    a2=xr[2]-xr[0];	//a2=xr3-xr1
    a3=xr[3]-xr[0];	//a3=xr4-xr1

    b1=yr[1]-yr[0];	//b1=yr2-yr1
    b2=yr[2]-yr[0];	//b2=yr3-yr1
    b3=yr[3]-yr[0];	//b3=yr4-yr1

    c1=zr[1]-zr[0];	//c1=zr2-zr1
    c2=zr[2]-zr[0];	//c2=zr3-zr1
    c3=zr[3]-zr[0];	//c3=zr4-zr1


//    cout<<"a: "<<a1<<' '<<a2<<' '<<a3<<endl;
//    cout<<"b: "<<b1<<' '<<b2<<' '<<b3<<endl;
//    cout<<"c: "<<c1<<' '<<c2<<' '<<c3<<endl;

    d21_sqr = pow(a1,2) + pow(b1,2) + pow(c1,2);
    d31_sqr = pow(a2,2) + pow(b2,2) + pow(c2,2);
    d41_sqr = pow(a3,2) + pow(b3,2) + pow(c3,2);

}
