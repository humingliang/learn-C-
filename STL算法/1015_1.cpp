#include "iostream"
#include "vector"
#include "string.h"
using namespace std;

class Teacher{
public:
    Teacher(const char *name,int age){
        m_pname = new char[strlen(name)+1];
        strcpy(m_pname,name);
        m_age = age;
    }
    ~Teacher(){
        delete [] m_pname;
        m_pname = NULL;
        m_age = 0;
    }
    Teacher(const Teacher &obj){
        m_pname = new char[strlen(obj.m_pname)+1];
        strcpy(m_pname,obj.m_pname);
        m_age = obj.m_age;
    }

    //重载=操作符
    //t3=t2=t1
    Teacher& operator=(const Teacher& obj){
        //释放旧内存
        if(m_pname != NULL){
            delete[] m_pname;
            m_pname = NULL;
            m_age = 0;
        }
        //分配大小
        m_pname = new char[strlen(obj.m_pname)+1];
        //copy数据
        strcpy(m_pname,obj.m_pname);
        m_age = obj.m_age;

        return *this;

    }

    void printT(){
        cout<<m_pname<<"\t"<<m_age<<endl;
    }
private:
    char* m_pname;
    int   m_age;
};

void main1(){
    Teacher t1("t1",31);
    t1.printT();
    vector<Teacher> v1;
    v1.push_back(t1);//拷贝t1进容器
}

int main(){
    main1();
    cout<<"hello..."<<endl;
    return 0;
}

