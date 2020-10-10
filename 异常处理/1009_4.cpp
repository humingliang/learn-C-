#include"iostream"
using namespace std;
 





int main(){   //getline在空格时也不会中断
    int intchar;
    char buf1[256];
    char buf2[256];
    
    cin>>buf1;
    cin.ignore(20);//忽略两个空格
    int myint = cin.peek();
    cout<<"myint :  "<<myint<<endl;



    cin.getline(buf2,256);
    cout<<buf1<<endl;
    cout<<buf2<<endl;

    
 }


/*

int main(){   //getline在空格时也不会中断
    char buf1[256];
    char buf2[256];
    
    cin>>buf1;
    cin.getline(buf2,256);
    cout<<buf1<<buf2<<endl;
    
 }


/*
int main(){   //在缓冲区有数据，是从缓冲区获取的
    char a,b,c;
    cin.get(a);
    cin.get(b);
    cin.get(c);
    cout<<a<<b<<c<<endl;

    cin.get(a).get(b).get(c);

    cout<<a<<b<<c<<endl;
 }
/*
int main(){
    char ch;
    while((ch=cin.get()) != EOF){
        cout<<ch<<endl;
    }
 }
/*
 int main(){
    int myInt;
    long mylong;
    char mybuf[1024];
    cin>>myInt;
    cin>>mylong;
    cin>>mybuf;//有空格停止接受


    cout<<"myInt:"<<mylong<<"mylong:"<<mylong<<"mybuf:"<<mybuf<<endl;
    cout <<"\n input your string <255";
    }
*/
