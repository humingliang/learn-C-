#include "iostream"
using namespace std;

void divide(int x,int y){
    if(y==0){
        throw x;//抛出（int）异常//严格类型匹配
    }
    cout<<"the result is :"<<x/y<<endl;
}

//发生异常直接跨函数
void mydivide(int x,int y){
    try
    {
        divide(x,y);
    }
    catch(...)
    {
        cout<<"i get ,but i don't deal with it,so i send it."<<endl;
        throw ;//继续向外扔
    }
}

int main(){
    try
    {
        //divide(10,2);
        //divide(100,0);
        
        mydivide(10,2);
        mydivide(100,0);
    }
    catch(int e)//按照类型进行catch
    {
        cout<<"Y is a zero."<<endl;
    }
    catch(...)
    {
        cout<<"don't know"<<endl;
    }
    cout<<"hello.."<<endl;
    return 0;
}
