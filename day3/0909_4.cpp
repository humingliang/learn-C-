#include"iostream"
using namespace std;

//new 基础类型、数组类型、类对象等

class Test{

public:
    Test(int _a){
        a=_a;
    }

    ~Test(){
        cout<<"destory Test"<<endl;
    }

private:
    int a;

};

int main(){
    //分配基础类型
    int *p = (int *)malloc(sizeof(int));
    *p=100;
    free(p);

    int *p2 = new int;
    *p2=20;
    free(p2);

    int *p3 = new int(30);
    printf("*p3:%d\n",*p3);
    delete(p3);


    //分配数组
    int *p4 = (int *)malloc(sizeof(int)*10);
    p4[0]=1;
    free(p4);

    int *p5=new int[10];
    p5[0]=10;
    //delete [] p5;//也可
    delete(p5);
    printf("*p5:%d\n",p5[0]);

    //分配对象
    //new能执行类构造函数，delete执行析构函数
    Test t1(0);
    Test *pT1 = (Test *)malloc(sizeof(Test));
    free(pT1);

    Test *pT2 = new Test(10);
    delete pT2;

    cout<<"hello..."<<endl;
    system("pause");
}
