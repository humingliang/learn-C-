#include"0908_C.h"
#include"iostream"
using namespace std;


    void Point::setPoint(int _x,int _y){
        P_x=_x;
        P_y=_y;
    }

    int Point::getPx(){
        return P_x;
    }

    int Point::getPy(){
        return P_y;
    }


    void Circle::setCircle(int _r,int _x,int _y){
        C_r=_r;
        C_x=_x;
        C_y=_y;
    }

    int Circle::getCx(){
        return C_x;
    }

    int Circle::getCy(){
        return C_y;
    }

    int Circle::getCr(){
        return C_r;
    }

    int Circle::Judge(Point &q){
        
        int ef=q.getPx()-C_x;
        int ed=q.getPy()-C_y;
        int f=ef*ef+ed*ed;
        int d=C_r*C_r;
        if(f<d){
            return 1;
        }
        else{
            return 0;
        }
        

    }

