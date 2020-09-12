#include"iostream"
#include"cstring"
using namespace std;

class Name{
    public:
        Name(const char *myp){
            len = strlen(myp);
            p = (char *)malloc(len+1);
            strcpy(p,myp);
        }

        //重写拷贝函数，完成深拷贝即可
        Name(const Name& obj){
            len = obj.len;
            p = (char *)malloc(len+1);
            strcpy(p,obj.p);
        }

        ~Name(){
        if(p!=NULL){
            free(p);
            p=NULL;
            len=0;
        }
        cout<<"I am a dead function.I am running."<<endl;
    }

    private:
        char *p;
        int len;

};

void objplay(){
    Name N1("abcde");
    Name N2=N1;//拷贝构造函数，使用默认浅拷贝，只是把原来空间多加一个名字，不会再堆中再新开辟内存空间。//两次析构出错
}

int main(){
    objplay();
    cout<<"helllo..."<<endl;
    system("pause");
}
