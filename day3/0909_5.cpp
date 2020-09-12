#include"iostream"
using namespace std;

class Test{
public:
    void getC(){
        cout<<"c:"<<c<<endl;
    }    

    void addC(){
        c=c+1;
    }
    //静态成员函数中，不能使用普通变量。
    static void get_C(){      //静态成员函数
        cout<<"c:"<<c<<endl;
    }  

    ~Test(){
        cout<<"destory Test"<<endl;
    }
private:
    int a;
    int b;
    static int c;//静态成员变量
};

int Test::c=10;//静态成员变量初始化

int main(){
    Test t1,t2,t3;
    t1.getC();
    t2.addC();
    t3.getC();
    t1.get_C();//方法一
    Test::get_C();//方法二
    cout<<"hello..."<<endl;
    system("pause");
}
