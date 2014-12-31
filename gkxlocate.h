#ifndef GKXLOCATE_H
#define GKXLOCATE_H

class gkxLocate
{
public:
    double* locate(const int* dis);
    gkxLocate(int n);
private:

    double xr[4];//=new double;
    double yr[4];//=new double;
    double zr[4];//=new double;


    double d21_sqr;
    double d31_sqr;
    double d41_sqr;

    double a1;	//a1=xr2-xr1
    double a2;	//a2=xr3-xr1
    double a3;	//a3=xr4-xr1

    double b1;	//b1=yr2-yr1
    double b2;	//b2=yr3-yr1
    double b3;	//b3=yr4-yr1

    double c1;	//c1=zr2-zr1
    double c2;	//c2=zr3-zr1
    double c3;	//c3=zr4-zr1

    double uwb_pos[3];
    int num;


};


#endif // GKXLOCATE_H
