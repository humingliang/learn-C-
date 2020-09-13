#include"iostream"
using namespace std;

class F{
public:
    int operator()(int a,int b){
        return a*a+b*b;
    }
};

int main(){
    F f;
    f(2,4);
    cout<<"hello..."<<endl;
    system("pause");
}
