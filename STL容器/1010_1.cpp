#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
//基础类型
void main11(){
    vector<int> v1;  //容器：把元素copy进容器
    v1.push_back(-1);
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(3);

    //迭代器：相当于一个指针
    for (vector<int> ::iterator it = v1.begin();it != v1.end();it++){
        cout<<*it<<" "<<endl;
    }

    //算法：算法和迭代器能无缝连接
    int num1 = count(v1.begin(),v1.end(),3);//统计数据：为3的数
    cout<<"num1:"<<num1<<endl;
}

class Teacher{
    public:
        void printT(){
            cout<<" age: "<<age<<endl;
        }
    public:
        int age;
        char name[64];
};
//容器中装 元素
void main12(){
    Teacher t1,t2,t3;
    t1.age=31;
    t2.age=32;
    t3.age=33;
    vector<Teacher> v1;  //容器：把元素copy进容器//实现数据类型和算法的有效分离
    v1.push_back(t1);
    v1.push_back(t2);
    v1.push_back(t3);

    //迭代器：相当于一个指针
    for (vector<Teacher> ::iterator it = v1.begin();it != v1.end();it++){
        cout<<it->age<<" "<<endl;
    }

    //算法：算法和迭代器能无缝连接
    //int num1 = count(v1.begin(),v1.end(),3);//统计数据：为3的数
    //cout<<"num1:"<<num1<<endl;
}

//装入指针
void main13(){
    Teacher t1,t2,t3;
    t1.age=31;
    t2.age=32;
    t3.age=33;
    Teacher *p1,*p2,*p3;
    p1 = &t1;
    p2 = &t2;
    p3 = &t3;
    vector<Teacher *> v1;  //容器:把t1,t2,t3内存首地址copy给容器
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);

    //迭代器：相当于一个指针
    for (vector<Teacher *> ::iterator it = v1.begin();it != v1.end();it++){
        cout<<(*it)->age<<" "<<endl;
    }

    //算法：算法和迭代器能无缝连接
    //int num1 = count(v1.begin(),v1.end(),3);//统计数据：为3的数
    //cout<<"num1:"<<num1<<endl;
}

//stl算法容器迭代器
int main(){
    //main11();
    //main12();
    main13();

    cout<<"hello..."<<endl;
    return 0;
}
