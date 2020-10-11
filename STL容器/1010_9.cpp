#include "iostream"
#include "algorithm"
#include "set"
#include "string.h"
using namespace std;

//集合，元素唯一  自动排序  默认从小到大 不能按[]插入元素
//红黑书
void main91(){
    set<int> s1;

    for(int i=0;i<5;i++){
        int tmp = rand();
        s1.insert(tmp);
    }
    s1.insert(100);
    s1.insert(100);
    s1.insert(100);

    for(set<int>::iterator it=s1.begin();it!=s1.end();it++){
        cout<<*it<<endl;
    }

    while(!s1.empty()){
        set<int>::iterator it = s1.begin();
        cout<<*it<<" ";
        s1.erase(s1.begin());
    }
    cout<<endl;
}

void main92(){
    set<int> s1;
    set<int,less<int>> s2;//从小到大
    set<int,greater<int>> s3;//从大到小

    for(int i=0;i<5;i++){
        int tmp = rand();
        s3.insert(tmp);
    }
    s3.insert(100);
    s3.insert(100);
    s3.insert(100);

    for(set<int,greater<int>>::iterator it=s3.begin();it!=s3.end();it++){
        cout<<*it<<endl;
    }
}

class Student{
    public:
        Student(const char *name,int age){
            strcpy(this->name,name);
            this->age=age;
        }

    public:
        int age;
        char name[64];
};
//仿函数
struct FuncStudent
{
    bool operator()(const Student &left,const Student &right){
        if(left.age<right.age){
            return true;
        }
        else{
            return false;
        }
    }
};

//自定义类型
void main93(){
    
    Student s1("s1",31);
    Student s2("s2",32);
    Student s3("s3",33);
    Student s4("s4",34);

    set<Student,FuncStudent> set1;
    set1.insert(s1);
    set1.insert(s2);
    set1.insert(s3);
    set1.insert(s4);

    //遍历
    for(set<Student,FuncStudent>::iterator it = set1.begin();it != set1.end();it++){
        cout<<it->age<<"\t"<<it->name<<endl;
    }

}

//如何判断insert的返回值
void main94(){
    Student s1("s1",31);
    Student s2("s2",32);
    Student s3("s3",33);
    Student s4("s4",34);
    Student s5("s5",31);

    set<Student,FuncStudent> set1;
    pair<set<Student,FuncStudent>::iterator,bool> pair1 = set1.insert(s1);
    if(pair1.second=true){
        cout<<"s1 success!!!"<<endl;
    }
    else{
        cout<<"s1 failure!!!"<<endl;
    }
    set1.insert(s2);
    set1.insert(s3);
    set1.insert(s4);
    pair<set<Student,FuncStudent>::iterator,bool> pair5 = set1.insert(s5);
    if(pair1.second=true){
        cout<<"s5 success!!!"<<endl;
    }
    else{
        cout<<"s5 failure!!!"<<endl;
    }
}

void main95(){
    set<int> s1;

    for(int i=0;i<10;i++){
        s1.insert(i+1);
    }
    for(set<int,greater<int>>::iterator it=s1.begin();it!=s1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    set<int>::iterator it1 = s1.find(5);
    cout<<"it1:"<<*it1<<endl;

    int num = s1.count(5);
    cout<<"num:"<<num<<endl;

    set<int>::iterator it2 = s1.lower_bound(5);//大于等于5的
    cout<<"it2:"<<*it2<<endl;
    set<int>::iterator it3 = s1.upper_bound(5);//大于等于5的
    cout<<"it3:"<<*it3<<endl;

    s1.erase(5);
    pair<set<int>::iterator,set<int>::iterator> pr1 = s1.equal_range(5);
    set<int>::iterator it4 = pr1.first;
    set<int>::iterator it5 = pr1.second;
    cout<<"it4:"<<*it4<<endl;
    cout<<"it5:"<<*it5<<endl;

}


int main(){
    
    //main91();
    //main92();
    //main93();
    //main94();
    main95();
    
    
    cout<<"hello..."<<endl;
    return 0;
}
