#include <iostream>
using namespace std;



class Tree{

};



class Animal{
    public:
     virtual void cry()=0;
};

class Dog : public Animal{
    public:
        void cry(){
            cout<<"woowowoowowwo"<<endl;
        }

        void doHome(){
            cout<<"watch door"<<endl;
        }
};

class Cat : public Animal{
    public:
        void cry(){
            cout<<"momomomo"<<endl;
        }

        void doHome(){
            cout<<"catch mouse"<<endl;
        }
};


void playObj(Animal *base){
    base->cry();//发生多态
    //dynamic_cast运行时类型识别
    Dog *pDog = dynamic_cast<Dog *>(base);
    if(pDog != NULL){
        pDog->doHome();//做自己独有的工作
    }

    Cat *pCat = dynamic_cast<Cat *>(base);//父类对象向下转型
    if(pCat != NULL){
        pCat->doHome();//做自己独有的工作
    }
}

//让内存空间只读
void printbuf(const char *p){
    char *p1 = NULL;
    p1 = const_cast<char *>(p);//要记得转化前后的类型，把只读转化为可改
    p1[0] = 'z';  //用p1修改了
    cout << p1 << endl;
}

int main(){
    char buf[]="aaaaaaaaaaaag";

    char *myp = "aaaaaaaaaaaag";
     
    //要确保P指向的内存空间可读，否则会有很大问题
    printbuf(buf);
    //printbuf(myp);//无法运行

    cout<<"hello..."<<endl;
    return 0;
}


/*

int main(){
    Dog d1;
    Cat c1;

    playObj(&d1);
    playObj(&c1);

    Animal *pbase = NULL;

    pbase = &d1;
    pbase = static_cast<Animal *>(&d1);//让C++编译器在编译时类型检查
    pbase = reinterpret_cast<Animal *>(&d1);
    {
        Tree t1;
        //pbase = static_cast<Animal *>(&t1);//让C++编译器在编译时类型检查
        pbase = reinterpret_cast<Animal *>(&t1);
    }

    cout<<"hello..."<<endl;
    return 0;
}

/*


int main01(){

    double dPi = 3.1415926;
    int num1 = (int)dPi;//c类型转换
    int num2 = static_cast<int>(dPi);
    int num3 = dPi;

    char *pi = "hello...itcast";
    int *p2 = NULL; 
    //p2 = static_cast<int *>(pi);
    p2 = reinterpret_cast<int *>(pi);

    cout<<pi<<endl;//%s
    cout<<p2<<endl;//%d

    cout<<"hello..."<<endl;
    system("pause");
    return 0;
}
*/
