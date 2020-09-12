#include"iostream"
using namespace std;

class Point{

public:
    void setPoint(int _x,int _y){
        P_x=_x;
        P_y=_y;
    }

    int getPx(){
        return P_x;
    }

    int getPy(){
        return P_y;
    }

private:
    int P_x;
    int P_y;



};

class Circle{

public:
    void setCircle(int _r,int _x,int _y){
        C_r=_r;
        C_x=_x;
        C_y=_y;
    }

    int getCx(){
        return C_x;
    }

    int getCy(){
        return C_y;
    }

    int getCr(){
        return C_r;
    }

    int Judge(Point &q){
        
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


private:
    int C_r;
    int C_x;
    int C_y;

};





int main(){

    Circle C1;
    Point p1;
    C1.setCircle(7,5,5);
    p1.setPoint(15,15);
    if(C1.Judge(p1)==1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
        
    system("pause");
}
