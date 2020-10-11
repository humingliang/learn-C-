#include "iostream"
#include "algorithm"
#include "queue"
using namespace std;

void main81(){

    priority_queue<int> p1;//默认最大值优先级队列
    priority_queue<int,vector<int>,less<int>> p2;//提前定义好的预定义函数，谓词
    priority_queue<int,vector<int>,greater<int>> p3;//最小值优先级队列
    p1.push(33);
    p1.push(11);
    p1.push(55);
    p1.push(44);

    cout<<"the head:"<<p1.top()<<endl;
    cout<<"the size:"<<p1.size()<<endl;

    while(p1.size()>0){
        cout<<p1.top()<<" ";
        p1.pop();
    }
    cout<<endl;
}

int main(){
    
    main81();
    
    cout<<"hello..."<<endl;
    return 0;
}
