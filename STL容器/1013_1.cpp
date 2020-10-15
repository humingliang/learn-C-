#include "iostream"
#include "map"
#include "string"
using namespace std;

//map的添加/遍历/删除等基本操作
void main1(){
    map<int,string> m1;
    //1
    m1.insert(pair<int,string>(1,"teacher01"));
    m1.insert(pair<int,string>(2,"teacher02"));

    //2
    m1.insert(make_pair(3,"teacher03"));
    m1.insert(make_pair(4,"teacher04"));

    //3
    m1.insert(map<int,string>::value_type(5,"teacher05"));
    m1.insert(map<int,string>::value_type(6,"teacher06"));

    //4
    m1[7]="teacher07";
    m1[8]="teacher08";

    for(map<int,string>::iterator it=m1.begin();it!=m1.end();it++){
        cout<<it->first<<"\t"<<it->second<<endl;
    }
    cout<<"output is over."<<endl;

    while(!m1.empty()){
        map<int,string>::iterator it1=m1.begin();
        cout<<it1->first<<"\t"<<it1->second<<endl;
        m1.erase(it1);
    }
}
//始终插入方法的不同
//前三种返回一个pair
void main2(){
    map<int,string> m1;
    //1
    pair<map<int,string>::iterator,bool> myp1 = m1.insert(pair<int,string>(1,"teacher01"));
    m1.insert(pair<int,string>(2,"teacher02"));

    //2
    pair<map<int,string>::iterator,bool> myp3 =m1.insert(make_pair(3,"teacher03"));
    m1.insert(make_pair(4,"teacher04"));

    //3
    pair<map<int,string>::iterator,bool> myp5 =m1.insert(map<int,string>::value_type(5,"teacher05"));
    if(myp5.second != true){
        cout<<"key5 is failure."<<endl;
    }
    else{
        cout<<myp5.first->first<<"\t"<<myp5.first->second<<endl;
    }
    pair<map<int,string>::iterator,bool> myp6 =m1.insert(map<int,string>::value_type(5,"teacher06"));
    if(myp6.second != true){
        cout<<"key6 is failure."<<endl;
    }
    else{
        cout<<myp6.first->first<<"\t"<<myp6.first->second<<endl;
    }

    m1[7]="teacher07";
    m1[7]="teacher77";

    for(map<int,string>::iterator it=m1.begin();it!=m1.end();it++){
        cout<<it->first<<"\t"<<it->second<<endl;
    }
    cout<<"output is over."<<endl;
}
//map查找
void main3(){
    map<int,string> m1;
    //1
    m1.insert(pair<int,string>(1,"teacher01"));
    m1.insert(pair<int,string>(2,"teacher02"));

    //2
    m1.insert(make_pair(3,"teacher03"));
    m1.insert(make_pair(4,"teacher04"));

    //3
    m1.insert(map<int,string>::value_type(5,"teacher05"));
    m1.insert(map<int,string>::value_type(6,"teacher06"));

    //4
    m1[7]="teacher07";
    m1[8]="teacher08";

    for(map<int,string>::iterator it=m1.begin();it!=m1.end();it++){
        cout<<it->first<<"\t"<<it->second<<endl;
    }
    cout<<"output is over."<<endl;

    map<int,string>::iterator it = m1.find(3);
    if(it == m1.end()){
        cout<<"key 3 isn't in."<<endl;
    }
    else{
        cout<<it->first<<"\t"<<it->second<<endl;
    }

    pair<map<int,string>::iterator,map<int,string>::iterator> mypair = m1.equal_range(5);//返回两个迭代器
    //第一个>=5
    //第二个>5
    if(mypair.first == m1.end()){
        cout<<"key >=5 isn't in."<<endl;
    }
    else{
        cout<<mypair.first->first<<"\t"<<mypair.first->second<<endl;
    }

    if(mypair.second == m1.end()){
        cout<<"key >5 isn't in."<<endl;
    }
    else{
        cout<<mypair.second->first<<"\t"<<mypair.second->second<<endl;
    }

}

int main(){

    //main1();
    //main2();
    main3();

    cout<<"hello..."<<endl;
    return 0;
}
