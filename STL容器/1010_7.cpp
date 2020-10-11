#include "iostream"
#include "algorithm"
#include "list"
using namespace std;

//list基本操作
void main71(){
    list<int> l;
    cout<<"list'size:"<<l.size()<<endl;
    for(int i = 0;i<10;i++){
        l.push_back(i+1);//尾插法
    }
    cout<<"list'size:"<<l.size()<<endl;

    list<int>::iterator it = l.begin();
    while(it != l.end()){
        cout<<*it<<" ";
        it++;
    }
    
    //不能随机访问 it = it + 5
    it = l.begin();
    it++;
    it++;
    it++;
    l.insert(it,100);//链表结点从0号开始，3号插入，后退一位

    for(list<int>::iterator it = l.begin();it != l.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    
}

//删除
void main72(){
    list<int> l;
    cout<<"list'size:"<<l.size()<<endl;
    for(int i = 0;i<10;i++){
        l.push_back(i+1);//尾插法
    }
    cout<<"list'size:"<<l.size()<<endl;

    for(list<int>::iterator it = l.begin();it != l.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    list<int>::iterator it1 = l.begin();
    list<int>::iterator it2 = l.begin();
    it2++;
    it2++;
    it2++;
    l.erase(it1,it2);//左闭右开的删除
    for(list<int>::iterator it = l.begin();it != l.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    l.insert(l.begin(),100);
    l.insert(l.begin(),100);
    l.insert(l.begin(),100);
    for(list<int>::iterator it = l.begin();it != l.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    l.remove(100);
    for(list<int>::iterator it = l.begin();it != l.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    
}


int main(){

    //main71();
    main72();
   


    cout<<"hello..."<<endl;
    return 0;
}
