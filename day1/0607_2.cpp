#include"iostream"

using namespace std;

//面向过程
/*
int main()
{
    double radius=0;
    double area=0;

    cout<<"please input the Circle's radius: ";
    cin >> radius;
    cout<<"the Circle's radius is "<<radius<<endl;
    area=3.14*radius*radius;
    cout<<"the Circle's area is "<<area<<endl;
    system("pause");
}
*/

//面向对象求解

//定义数据类型，兼容C
struct Circle
{
    double area;
    double radius;
};

//定义数据类型
class MyClass
{
public:
    double area;
    double radius;

public:
    void set_radius(double s_r){//成员函数
        radius=s_r;
    }

    double get_radius(){
        return radius;
    }

    double get_area(){
        area=radius*radius*3.1415;
        return area;
    };
protected:

private:
};


//类是一个数据类型，定义一个类并不会有内存，实例化时才会。
int main()
{
    MyClass c1,c2,c3;//实例化，用类定义变量
    double r;
    cout<<"please input c1's radius:";
    cin>>r;
    c1.set_radius(r);

    cout<<"c1's area is "<<c1.get_area()<<endl;
    system("pause");
}
