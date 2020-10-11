#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
using namespace std;

void main21(){
    string s1="aaaabbbb";
    string s2("cccccddd");
    string s3 = s2;//copy
    string s4(10,'a');

    cout<<"s1: "<<s1<<endl;
    cout<<"s2: "<<s2<<endl;
    cout<<"s3: "<<s3<<endl;
    cout<<"s4: "<<s4<<endl;

}

//string 的遍历
void main22(){
    string s1 = "abcdefg";

    //数组方式
    for (int i=0;i<s1.length();i++){
        cout<<s1[i]<<" ";
    }
    cout<<endl;
    //迭代器
    for(string::iterator it = s1.begin();it != s1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    try{
        for (int i = 0;i<s1.length()+3;i++){
            cout<<s1.at(i)<<" ";//a't抛出异常
        }
        cout<<endl;
    }

    catch(...){
        cout<<"throw error"<<endl;
    }

    /*
    try{
        for (int i = 0;i<s1.length()+3;i++){
            cout<<s1[i]<<" ";//出现错误不抛出，程序中断
        }
        cout<<endl;
    }

    catch(...){
        cout<<"throw error"<<endl;
    }
    */
}

//字符指针和string的转换
void main23(){
    string s1 = "aaagggggg";
    //1 s1===>char*
    printf("s1:%s \n",s1.c_str());

    //2 char*===>string

    //s1的内容copy到buf中
    char buf1[128];
    s1.copy(buf1,5,0);//只给3个字符
    cout<<"buf1:"<<buf1<<endl;
}

//连接字符串
void main24(){
    string s1 = "aaa";
    string s2 = "bbb";
    s1 = s1 + s2;
    cout <<s1<<endl;

    string s3 = "111";
    string s4 = "222";
    s3.append(s4);
    cout <<s3<<endl;
}



//字符串查找和替换
void main25(){
    string s1 = "wbm hello wbm 111 wbm 222 hml 333";
    //第一次出现wbm index
    int index = s1.find("wbm",0);//位置下标从0开始
    cout<< "index: "<<index<<endl;

    //1 求wbm出现的次数和每一次出现的数组下标
    int offindex = s1.find("wbm",0);
    while(offindex != string::npos){
        cout<<"offindex: "<<offindex<<endl;
        offindex = offindex+1;
        offindex = s1.find("wbm",offindex);
    }

    //2 替换wbm换成WBM
    offindex = s1.find("wbm",0);
    while(offindex != string::npos){
        cout<<"offindex: "<<offindex<<endl;
        s1.replace(offindex,3,"WBM");
        offindex = offindex+1;
        offindex = s1.find("wbm",offindex);
    }
    cout<<"s1 after replace "<<s1<<endl;

}

//删除字符串
void main26(){
    string s1 = "hello1 hello2 hello3";
    string::iterator it = find(s1.begin(),s1.end(),'1');
    if(it != s1.end()){
        s1.erase(it);
    }
    cout<<"after delete "<<s1<<endl;
    s1.erase(s1.begin(),s1.end());
    cout<<"after delete "<<s1<<endl;
    cout<<"s1'length: "<<s1.length()<<endl;

    string s2 = "BBB";
    //插入
    s2.insert(0,"AAA");//头插
    s2.insert(s2.length(),"AAA");//尾插法

    cout<<"after insert "<<s2<<endl;
}

//调用算法
void main27(){
    string s1 = "AAAbbb";
    //1 函数入口地址/2函数对象/3 预定义的函数对象
    transform(s1.begin(),s1.end(),s1.begin(), ::toupper);
    cout<<"s1: "<<s1<<endl;

    string s2 = "AAAbbb";
    transform(s2.begin(),s2.end(),s2.begin(), ::tolower);
    cout<<"s2: "<<s2<<endl;

}


int main(){

    //main21();
    //main22();
    //main23();
    //main24();
    //main25();
    //main26();
    main27();


    cout <<"hello..."<<endl;
    return 0;
}
