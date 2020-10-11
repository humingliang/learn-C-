#include "iostream"
#include "algorithm"
#include "stack"
using namespace std;

void main51(){
    stack<int> s1;

    //入栈
    for(int i=10;i<10;i++){
        s1.push(i+1);
    }
    cout<<"s1'size: "<<s1.size()<<endl;

    //出栈
    while( !s1.empty()){
        int tmp = s1.top();//获取栈顶元素
        cout<<"top:"<<tmp<<endl;
        //s1.pop();//弹出栈顶元素
    }

}

class Teacher{


public:
    int age;
    char name[32];
public:
    void printT(){
        cout<<"age:"<<age<<endl;
    }
};

void main52(){

    Teacher t1,t2,t3;
    t1.age = 31;
    t2.age = 32;
    t3.age = 33;
    stack<Teacher> s;

    //入栈
    s.push(t1);
    s.push(t2);
    s.push(t3);
    cout<<"s1'size: "<<s.size()<<endl;

    //出栈
    while( !s.empty()){
        Teacher tmp = s.top();//获取栈顶元素
        cout<<"top:"<<tmp.age<<endl;
        s.pop();//弹出栈顶元素
    }

}

void main53(){

    Teacher t1,t2,t3;
    t1.age = 31;
    t2.age = 32;
    t3.age = 33;
    stack<Teacher *> s;

    //入栈
    s.push(&t1);
    s.push(&t2);
    s.push(&t3);
    cout<<"s1'size: "<<s.size()<<endl;

    //出栈
    while( !s.empty()){
        Teacher *tmp = s.top();//获取栈顶元素
        tmp->printT();
        s.pop();//弹出栈顶元素
    }

}



int main(){

    //main51();
    //main52();
    main53();

    cout<<"hello..."<<endl;
    return 0;
}
