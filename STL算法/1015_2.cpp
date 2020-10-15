#include "iostream"
#include "vector"
#include "string.h"
#include "string"
#include "list"
#include "set"
#include "algorithm"
#include "functional"
using namespace std;


template<typename T>
class ShowElent{//定义一元函数对象
public:
    ShowElent(){
        n = 0;
    }
    void operator()(T &t){
        n++;
        printS();
        cout<<t<<" ";
    }

    void printS(){
        cout<<"n:"<<n<<endl;
    }
private:
    int n;
};

template<typename F>
void FuncShowElemt(F &f){
    cout<<f<<" ";
}

void FuncShowElemt1(int &i){
    cout<<i<<" ";
}

//函数对象和普通函数的异同
void main1(){
    int a = 10;
    ShowElent<int> showElent;
    showElent(a);//执行很类似函数调用-故称仿函数

    FuncShowElemt<int>(a);
    FuncShowElemt1(a);
}


//函数对象属于类对象，可以突破函数的概念，保持调用的状态
//函数对象的好处
//for_each算法中，函数对象做函数参数，也做返回值
void main2(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    for_each(v1.begin(),v1.end(),ShowElent<int>());//匿名函数对象-匿名仿函数
    cout<<endl;
    for_each(v1.begin(),v1.end(),FuncShowElemt1);//通过回调函数，谁使用for_each谁去填回调函数入口地址
    cout<<endl;

    ShowElent<int> show1;
    //函数对象做函数参数
/*
    template <class _InIt, class _Fn>
    _CONSTEXPR20 _Fn for_each(_InIt _First, _InIt _Last, _Fn _Func) { // perform function for each element [_First, _Last)
    _Adl_verify_range(_First, _Last);
    auto _UFirst      = _Get_unwrapped(_First);
    const auto _ULast = _Get_unwrapped(_Last);
    for (; _UFirst != _ULast; ++_UFirst) {
        _Func(*_UFirst);
    }

    return _Func;
}
*/
    //for_each算法是函数对象的传递是元素值得传递，不是引用传递.可以通过返回值查看
    //看返回值是迭代器还是函数对象，元素
    show1 = for_each(v1.begin(),v1.end(),show1);
    show1.printS();

}

template<typename T>
class IsDiv{
    private:
        T divisor;
    public:
        IsDiv(const T& div){
            this->divisor = div;
        }

        bool operator()(T& t){
            return (t % divisor == 0);
        }
};

void main3(){
    vector<int> v1;
    for(int i=0;i<33;i++){
        v1.push_back(i+1);
    }
    cout<<"v1'size : "<<v1.size()<<endl;

    vector<int>::iterator it;
    int a=4;
    IsDiv<int> mydiv(a);
    it = find_if(v1.begin(),v1.end(),IsDiv<int>(a));
    if(it !=v1.end()){
        cout<<"the first number which is div by four is "<<*it<<endl;
    }
}

template<typename T>
class SumAdd{
    public:
        T operator()(T &t1,T &t2){
            return t1+t2;
        }
};

void main4(){
    vector<int> v1,v2;
    vector<int> v3;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);

    v3.resize(10);

    transform(v1.begin(),v1.end(),v2.begin(),v3.begin(),SumAdd<int>());

    for(vector<int>::iterator it=v3.begin();it!=v3.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

bool MyCompare(const int &a,const int &b){
    return a<b;
}
//二元谓词-比较大小
void main5(){
    vector<int> v(10);

    for(int i=0;i<10;i++){
        int tmp = rand()%100;
        v[i] = tmp;
    }

    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    for_each(v.begin(),v.end(),FuncShowElemt1);
    cout<<endl;

    sort(v.begin(),v.end(),MyCompare);//从小到大

    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;


}

struct CompareNoCase
{
    bool operator()(const string &str1,const string &str2){
        string str1_;
        str1_.resize(str1.size());
        transform(str1.begin(),str1.end(),str1_.begin(),::tolower);

        string str2_;
        str2_.resize(str2.size());
        transform(str2.begin(),str2.end(),str2_.begin(),::tolower);

        return (str1_<str2_);//从小到大排序
    }
};

void main6(){
    set<string> set1;
    set1.insert("bbb");
    set1.insert("aaa");
    set1.insert("ccc");
    set<string>::iterator it = set1.find("aaa");//find默认区分大小写
    if(it != set1.end()){
        cout<<"finded aaa!"<<endl;
    }
    else{
        cout<<"can't find aaa"<<endl;
    }

    cout<<"No Case "<<endl;
    set<string,CompareNoCase> set2;
    set2.insert("bbb");
    set2.insert("aaa");
    set2.insert("ccc");

    set<string>::iterator i2 = set2.find("aAa");//find默认区分大小写
    if(it != set2.end()){
        cout<<"finded aaa!"<<endl;
    }
    else{
        cout<<"can't find aaa"<<endl;
    }
}





int main(){
    //main1();
    //main2();
    //main3();
    //main4();
    //main5();
    main6();
    cout<<"hello..."<<endl;
    return 0;
}
