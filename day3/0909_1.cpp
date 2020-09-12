#include"iostream"
using namespace std;

class Test
{
private:
    int m_a;
    int m_b;
    
public:
    //无参数构造函数
    Test(){
        m_a=0;
        m_b=0;
        cout<<"I am a 0.I am running."<<endl;
    }
     //带参数构造函数
    Test(int a){
        m_a=a;
        m_b=0;
        cout<<"I am a 1.I am running."<<endl;
    }

    //带参数构造函数
    Test(int a,int b){
        m_a=a;
        m_b=b;
        cout<<"I am a 2.I am running."<<endl;
    }
    //拷贝/赋值构造函数
    Test(const Test& obj){

        cout<<"I am a 3.I am running."<<endl;
        m_a=obj.m_a+100;
        m_b=obj.m_b+100;
    }

    ~Test(){
        cout<<"I am a dead function.I am running."<<endl;
    }

    int GetX(){
        return m_a;
    }


};

//给对象一个舞台，展示生命周期,研究对象的行为
void objplay(){
    Test t1;
};

//形参只是一个元素
void function(Test t){
    cout<<"there is a test function"<<endl;
};

//返回一个匿名对象
Test function1(){
    Test t(1,2);
    cout<<"there is function1"<<endl;
    return t;

}

int main(){
/*
    Test T1;//1无参数构造函数调用
    Test T2(1,2);//带参数构造函数调用
    Test T0(3,4);
    T0=T2;//用T2给T0赋值
    Test T3 = (3,4);//2带参数构造函数调用,对+进行符号增强，最后一个值为输入值。

    Test T4 = Test(5,6);//3拷贝构造函数，用一个对象去初始化另一个对象//Test(5,6)匿名对象的去留
    Test T5 = T2;//用T2给T5初始化-第一种调用方法

    Test T6(T2);//给T6赋值-第二种调用时机
*/
    Test P;
    function(P);//第三种拷贝构造函数调用，P实参会调用来初始化形参
    //function1();//会被析构掉
    //Test ss=function1();//初始化另外的值，匿名对象转成有名字,不会被析构掉，应该是第四种拷贝构造的，但是并没有被观察到
    Test ee(2,3);
    ee=function1();//匿名对象被析构，传值给ee了。
    cout<<ee.GetX()<<endl;
    //objplay();
    cout<<"hello...."<<endl;
    system("pause");
}
