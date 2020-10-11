#include "iostream"
#include "algorithm"
#include "queue"
using namespace std;

void main61(){
    queue<int> q;
    q.push(1);
    q.push(3);
    q.push(5);

    cout<<"the head :"<<q.front()<<endl;
    cout<<"the size :"<<q.size()<<endl;
    while( !q.empty()){
        int tmp = q.front();
        cout<<tmp<<" ";
        q.pop();
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

void main62(){

    Teacher t1,t2,t3;
    t1.age = 31;
    t2.age = 32;
    t3.age = 33;
    queue<Teacher> q;

    //入栈
    q.push(t1);
    q.push(t2);
    q.push(t3);
    cout<<"s1'size: "<<q.size()<<endl;

    //出栈
    while( !q.empty()){
        Teacher tmp = q.front();//获取栈顶元素
        cout<<"top:"<<tmp.age<<endl;
        q.pop();//弹出栈顶元素
    }

}

void main63(){

    Teacher t1,t2,t3;
    t1.age = 31;
    t2.age = 32;
    t3.age = 33;
    queue<Teacher *> q;

    //入栈
    q.push(&t1);
    q.push(&t2);
    q.push(&t3);
    cout<<"s1'size: "<<q.size()<<endl;

    //出栈
    while( !q.empty()){
        Teacher *tmp = q.front();//获取栈顶元素
        tmp->printT();
        q.pop();//弹出栈顶元素
    }

}

int main(){

    //main61();
    //main62();
    main63();


    cout<<"hello..."<<endl;
    return 0;
}
