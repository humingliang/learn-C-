#include"iostream"
using namespace std;
class A{
public:
    A(int _a){
        a=_a;
        cout<<"a"<<a<<endl;
        cout<<"Creater A"<<endl;
    }

    ~A(){
        cout<<"destory A"<<endl;
    }

private:
    int a;
};

/*
//构造函数初始化列表，解决：在B类中组合了一个A类对象（A类设计了构造函数）
Constructor::Contructor() : m1(v1), m2(v1,v2), m3(v3) 
{ 
 some other assignment operation 
}

*/
class B{
public:
    //也可用来给const变量初始化
    B(int _b1,int _b2) :a1(1),a2(2),a(0){
        cout<<"Creater B_1"<<endl;
    }

    B(int _b1,int _b2, int m, int n):a1(m),a2(n),a(0){
        cout<<"Creater B_2"<<endl;
    }

    ~B(){
        cout<<"destory B"<<endl;
    }

private:
    int b1;
    int b2;
    A a1;
    A a2;
    const int a;
};

void TT(){
    B obj1(1,2,3,4);
}



int main(){
    //A a1(10);
    //B obj(1,2);
    TT();
    //B obj1(1,2,3,4);
    cout<<"helleo...."<<endl;
    system("pause");
}
