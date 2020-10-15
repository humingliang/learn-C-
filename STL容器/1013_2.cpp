#include "iostream"
#include "map"
#include "string"
using namespace std;

//1 个key值可以对应多个 valude = 分组
// 公司有销售部 sale （员工 2名）、技术研发部 development （1人）、财务部 Financial （2人）
// 人员信息有：姓名，年龄，电话、工资等组成
// 通过 multimap 进行信息的插入、保存、显示
// 分部门显示员工信息
class Person{
    public:
        string name;
        int    age;
        string tel;
        double sale;
};

void main1(){
    Person p1,p2,p3,p4,p5;
    p1.name = "wang 1";
    p1.age  = 31;
    p2.name = "wang 2";
    p2.age  = 32;
    p3.name = "zhang 3";
    p3.age  = 33;
    p4.name = "zhang 4";
    p4.age  = 34;
    p5.name = "zhao 5";
    p5.age  = 35;
    multimap<string,Person> map1;
    map1.insert(make_pair("sale",p1));
    map1.insert(make_pair("sale",p2));

    map1.insert(make_pair("development",p3));
    map1.insert(make_pair("development",p4));

    map1.insert(make_pair("Financial",p5));

    for(multimap<string,Person>::iterator it = map1.begin();it!=map1.end();it++){
        cout<<it->first<<"\t"<<it->second.name<<endl;
    }
    cout<<"output is over."<<endl;

    int num = map1.count("development");
    cout<<"development'person :"<<num<<endl;
    multimap<string,Person>::iterator it2=map1.find("development");

    int tag = 0;
    while(it2!=map1.end()&&tag<2){
        cout<<it2->first<<"\t"<<it2->second.name<<endl;
        it2++;
        tag++;
    }
}

//age为32修改名字
void main2(){
    Person p1,p2,p3,p4,p5;
    p1.name = "wang 1";
    p1.age  = 31;
    p2.name = "wang 2";
    p2.age  = 32;
    p3.name = "zhang 3";
    p3.age  = 33;
    p4.name = "zhang 4";
    p4.age  = 34;
    p5.name = "zhao 5";
    p5.age  = 35;
    multimap<string,Person> map1;
    map1.insert(make_pair("sale",p1));
    map1.insert(make_pair("sale",p2));

    map1.insert(make_pair("development",p3));
    map1.insert(make_pair("development",p4));

    map1.insert(make_pair("Financial",p5));

    for(multimap<string,Person>::iterator it = map1.begin();it!=map1.end();it++){
        cout<<it->first<<"\t"<<it->second.name<<endl;
        if(it->second.age == 32){
            it->second.name="name32";
        }
    }
    cout<<"output is over."<<endl;

    for(multimap<string,Person>::iterator it = map1.begin();it!=map1.end();it++){
        cout<<it->first<<"\t"<<it->second.name<<endl;
    }
    cout<<"output is over."<<endl;

}

int main(){
    //main1();
    main2();
    cout<<"hello..."<<endl;
    return 0;
}
