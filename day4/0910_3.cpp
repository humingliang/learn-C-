#include "iostream" 
#include "cstring"
using namespace std; 

class Complex{
private:
    int a;
    int b;
    char *m_p;
    friend Complex my_add(Complex &c1,Complex &c2);
    friend Complex operator+(Complex &c1,Complex &c2);
    friend Complex& operator++(Complex &c1);//重载前置++,需要使用取地址&
    friend Complex operator++(Complex &c1,int);//占位符后置++，--
    friend ostream& operator<<(ostream &out,Complex &c1);
public:
    Complex(int a=0,int b=0){
        this->a=a;
        this->b=b;
    }

    Complex operator-(Complex &c1){
        Complex tmp1(this->a-c1.a,this->b-c1.b);
        return tmp1;
    }
    //不需要使用取地址&，临时变量tmp1内存空间消失
    Complex operator--(){
        Complex tmp1(this->a--,this->b--);
        return tmp1;
    }

    Complex operator--(int){
        Complex tmp = *this;
        this->a--;
        this->b--;
        return tmp;
    }
    
    void printComplex(){
        cout<<a<<" + "<<b<<"i"<<endl;
    }

};

//全局函数法实现
Complex my_add(Complex &c1,Complex &c2){
    Complex tmp1(c1.a+c2.a,c1.b+c2.b);
    return tmp1;
}
//函数名升级
Complex operator+(Complex &c1,Complex &c2){
    Complex tmp1(c1.a+c2.a,c1.b+c2.b);
    return tmp1;
}
//前置++
Complex& operator++(Complex &c1){
    c1.a++;
    c1.b++;
    return c1;
}
//后置++,采用占位符
Complex operator++(Complex &c1,int){
    Complex tem=c1;//提前拷贝
    c1.a++;
    c1.b++;
    return tem;
}
//这样可以支持链式编程
ostream& operator<<(ostream &out,Complex &c1){
    out<<"i am fine, thank you!"<<endl;
    out<<c1.a<<"+"<<c1.b<<"i"<<endl;
    return out;
}


int main(){
    int a=0;
    int b=0;
    int c;
    c=a+b;//编译器是知道int的“+”是如何计算的

    //a+bi复数运算法则
    Complex c1(1,2),c2(3,4);
    Complex c3;
    //c3=c1+c2;//自定义数据类型C++默认情况下是不知道如何运算的。

    Complex c4;
    c4=c1+c2;//可以进行直接加法运算了。
    c4.printComplex();

    Complex c5=c4 - c1;//减法的重载
    c5.printComplex();

    ++c5;
    c5.printComplex();

    --c5;
    c5.printComplex();

    c5++;
    c5.printComplex();

    c5--;
    c5.printComplex();
    //函数返回值作为左值，需要返回一个引用
    cout<<c5<<endl;;

    cout<<"hello..."<<endl;
    system("pause"); 
}
