#pragma once

class Point{

public:
    void setPoint(int _x,int _y);
    int getPx();
    int getPy();
private:
    int P_x;
    int P_y;
};

class Circle{
public:
    void setCircle(int _r,int _x,int _y);
    int getCx();
    int getCy();
    int getCr();
    int Judge(Point &q);
private:
    int C_r;
    int C_x;
    int C_y;

};
