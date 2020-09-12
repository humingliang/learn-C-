#include"iostream"
using namespace std;

class myCircle
{
public://属性-成员变量
    double m_r;
    double m_s;

public:

    double getR(){
        return m_r;
    }

    void setR(double r){
        m_r=r;
    }

    double getS(){
        m_s=3.14*m_r*m_r;
        return m_s;
    }
//访问控制函数

protected:


private:
    double p;

};

//通过类的指针可以调用
void printCircle01(myCircle *pC){
    cout<<"r:"<<pC->getR()<<endl;
    cout<<"S:"<<pC->getS()<<endl;
}

//通过引用调用
void printCircle02(myCircle &pC){
    cout<<"r:"<<pC.getR()<<endl;
    cout<<"S:"<<pC.getS()<<endl;
}

//直接引用
void printCircle03(myCircle pC){
    cout<<"r:"<<pC.getR()<<endl;
    cout<<"S:"<<pC.getS()<<endl;
}

int main()
{
    myCircle c1,c2;
    c1.setR(10);
    cout<<"area:"<<c1.getS()<<endl;
    printCircle01(&c1);

    c2.setR(20);
    printCircle01(&c2);

    cout<<"hello...."<<endl;
    system("pause");
}
