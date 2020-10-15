#include "iostream"
#include "vector"
#include "string.h"
#include "string"
#include "list"
#include "set"
#include "algorithm"
#include "functional"
#include "iterator"
using namespace std;

void printV(vector<int> &v){
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
}

void printL(list<int> &v){
    for(list<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
}

void showElem(int &n){
    cout<<n<<" ";
}

class CMyShow{
    public:
        CMyShow(){
            num = 0;
        }
        void operator()(int &n){
            num++;
            cout<<n<<" ";
        }
        void printNum(){
            cout<<"num:"<<num<<endl;
        }

    private:
        int num;
};



void main1(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    printV(v1);
    cout<<endl;
    //函数对象 回调函数入口地址
    for_each(v1.begin(),v1.end(),showElem);
    cout<<endl;

    //for_each(v1.begin(),v1.end(),CMyShow());
    //cout<<endl;

    CMyShow mya;
    CMyShow show1 = for_each(v1.begin(),v1.end(),mya);
    cout<<endl;
    mya.printNum();
    show1.printNum();
}

int increase(int i){
    return i+100;
}

void main2_transform(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    printV(v1);
    cout<<endl;

    //使用回调函数
    transform(v1.begin(),v1.end(),v1.begin(),increase);
    printV(v1);
    cout<<endl;

    //使用预定义的函数对象
    transform(v1.begin(),v1.end(),v1.begin(),negate<int>());
    printV(v1);
    cout<<endl;

    //函数适配器
    list<int> mylist;
    mylist.resize(v1.size());

    transform(v1.begin(),v1.end(),mylist.begin(),bind2nd(multiplies<int>(),10));
    printL(mylist);
    cout<<endl;

    //输出结果直接到屏幕
    transform(v1.begin(),v1.end(),ostream_iterator<int>(cout," "),negate<int>());
    cout<<endl;
}

void main3_transform_pk_foreach(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    vector<int> v2 = v1;
    //函数对象 回调函数入口地址
    for_each(v1.begin(),v1.end(),showElem);//不需要返回值
    cout<<endl;

    transform(v1.begin(),v1.end(),v1.begin(),increase);//函数需要有返回值
    printV(v1);
    cout<<endl;
}

int main(){
    //main1();
    //main2_transform();
    main3_transform_pk_foreach();
    cout<<"hello..."<<endl;
    return 0;
}
