#include "iostream"
#include "vector"
#include "string.h"
#include "string"
#include "list"
#include "set"
#include "algorithm"
#include "functional"
using namespace std;

void main1(){
    plus<int> intadd;
    int x=10;
    int y=20;
    int z=intadd(x,y);
    cout<<"z:"<<z<<endl;

    plus<string> stringAdd;

    string s1="aaa";
    string s2="bbb";
    string s3=stringAdd(s1,s2);
    cout<<"s3:"<<s3<<endl;

    vector<string> v1;
    v1.push_back("aaa");
    v1.push_back("bbb");
    v1.push_back("ccc");
    v1.push_back("ddd");
    v1.push_back("ccc");
    v1.push_back("ccc");

    sort(v1.begin(),v1.end(),greater<string>());

    for(vector<string>::iterator it= v1.begin();it !=v1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //求ccc出现的次数
    string sc = "ccc";
    //bind2nd函数适配器:预定义函数对象和第二个参数进行绑定
    //int num = count_if(v1.begin(),v1.end(),bind2nd(equal_to<string>(),sc));
    //cout<<"num:"<<num<<endl;
}


struct IsGreat
{
    int m_num;
    IsGreat(int i){
        m_num = i;
    }
    bool operator()(int &num){
        if(num>m_num){
            return true;
        }
        else{
            return false;
        }
    }
};

void main2(){
    vector<int> v1;
    for(int i=0;i<10;i++){
        v1.push_back(i+1);
    }
    for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    int num1 = count(v1.begin(),v1.end(),3);
    cout<<"num1:"<<num1<<endl;
    
    //通过谓词求大于二的个数
    int num2 = count_if(v1.begin(),v1.end(),IsGreat(2));
    cout<<"num2:"<<num2<<endl;

    //通过预定义的函数对象求大于二的个数
    //bind2nd左来自容器，右来自固定的2
    //int num3 = count_if(v1.begin(),v1.end(),bind2nd(greater<int>(),2));
    //cout<<"num3:"<<num3<<endl;

    //求奇数个数
    //int num4 = count_if(v1.begin(),v1.end(),bind2nd(modulus<int>(),2));
    //cout<<"num4:"<<num4<<endl;

    //求偶数个数
    //int num5 = count_if(v1.begin(),v1.end(),not1(bind2nd(modulus<int>(),2)));
    //cout<<"num5:"<<num5<<endl;
}

int main(){
    //main1();
    main2();
    cout<<"hello..."<<endl;
    return 0;
}
