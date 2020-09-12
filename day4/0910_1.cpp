#include "iostream" 
using namespace std; 
class C1{ 
public: 
    C1(int a=0,int b=0){
        this->i=a;
        this->j=b;
    }
    
    //成员函数
    C1 add_C(C1 &c1){
        C1 tem(this->i+c1.i,this->j+c1.j);
        return tem;
    }

    //返回一个引用/自身
    C1& add_C1(C1 &c1){
        this->i=this->i+c1.i;
        this->j=this->j+c1.j;
        return *this;
    }

    void print(){
        cout<<"a:"<<i<<endl;
    }
    
public: 
    int i; 
    int j;
};

//成员变量转化为全局函数
void print(C1 *pT){
        cout<<"a:"<<pT->i<<endl;
    }

//全局函数
C1 addC(C1 &c1,C1 &c2){
    C1 tem;
    return tem;
};

int main() 
{ 
    C1 c1(1,2);
    C1 c2(3,4);

    C1 c3;
    c3=addC(c1,c2);

    C1 c4;//赋值
    c4=c1.add_C(c2);
    c4.print();

    C1 c5=c1.add_C(c2);//匿名对象直接转化有名
    c5.print();

    //c1=c1+c2
    c1.add_C1(c2);
    c1.print();
    //printf("c1:%d \n", sizeof(C1)); 
    system("pause"); 
}
