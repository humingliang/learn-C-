#include"iostream"

using namespace std;

int main01()
{

    std::cout<<"namespace test"<<std::endl;
    system("pause");
}


//定义命名空间
namespace namespaceA
{
    int a=10;
}

namespace namespaceB
{
    int a=20;
    namespace namespaceC
    {
        struct Teacher
        {
            char name[32];
            int age;
        };
    }
}

//使用命名空间
int main02()
{
    using namespace namespaceA;
    using namespace namespaceB;
    std::cout<<namespaceB::a<<std::endl;

    namespaceB::namespaceC::Teacher t1;
    t1.age=33;



    using namespaceB::namespaceC::Teacher;
    Teacher T2;
    T2.age=36;
    char h;
    std::cin>>h;
   // T2.name=h;
    system("pause");
}


int main03() 
{ 
int a = 10; 
int b = 20; 
// 返回一个最小数并且给最小数赋值成 30
(a < b ? a : b )= 30; //*(a<b?&a:&b)=30返回内存空间
printf("a = %d, b = %d\n", a, b); 
system("pause"); 
return 0; 
}

int main() 
{ 
int a = 10; 
int &b = a; 
//b 是a的别名，请问 c++编译器后面做了什么工作？
b = 11;
cout<<"b--->"<<a<<endl;
printf("a:%d\n", a);
printf("b:%d\n", b);
printf("&a:%d\n", &a);
printf("&b:%d\n", &b); // 请思考：对同一内存空间可以取好几个名字吗？
system("pause");
return 0;
}


