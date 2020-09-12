#include"iostream"

using namespace std;


//定义数据类型
class MyClass
{
public:
    
    double radius;

    double pi=3.1415926;
    double area=pi*radius*radius;//初始化的时候执行，在调用时出现乱码，之后不会再执行。
};


//类是一个数据类型，定义一个类并不会有内存，实例化时才会。
int main()
{
    MyClass c1;//实例化，用类定义变量
    double r;
    cout<<"please input c1's radius:";
    cin>>c1.radius;

    cout<<"c1's area is "<<c1.area<<endl;
    system("pause");
}
