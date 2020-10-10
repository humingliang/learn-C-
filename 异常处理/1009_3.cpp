#include "iostream"
using  namespace std;

class MyArray{
public:
    MyArray(int len);
    ~MyArray();
public:
    int &operator[](int index);
    int getlen();

    class eSize{
    public:
        eSize(int size){
            m_size =size;
        }
        virtual void printErr(){
            cout<<"size:"<<m_size<<endl;
        }
    protected:
        int m_size;
    };
    class eNegative:public eSize{
    public:
        eNegative(int size):eSize(size){
            ;
        }
        virtual void printErr(){
            cout<<"eNegative::size:"<<m_size<<endl;
        }
    };//index<0
    class eZero:public eSize{
    public:
        eZero(int size):eSize(size){
            ;
        }
        virtual void printErr(){
            cout<<"eZero::size:"<<m_size<<endl;
        }
    };//index=0
    class eTooBig:public eSize{
    public:
        eTooBig(int size):eSize(size){
            ;
        }
        virtual void printErr(){
            cout<<"eTooBig::size:"<<m_size<<endl;
        }
    };//index>1000
    class eTOOSmall:public eSize{
    public:
        eTOOSmall(int size):eSize(size){
            ;
        }
        virtual void printErr(){
            cout<<"eTOOSmall::size:"<<m_size<<endl;
        }
    };//index<10
    

private:
    int *m_space;
    int m_len;
};

MyArray::MyArray(int len){
    if(len<0){
        throw eNegative(len);
    }
    else if(len == 0){
        throw eZero(len);
    }
    else if(len > 1000){
        throw eTooBig(len);
    }
    else if(len < 3){
        throw eTOOSmall(len);
    }
    else if(len < 3){
        throw out_of_range("yyy");
    }
    m_len = len;
    m_space = new int[m_len];
}

MyArray::~MyArray(){
    if(m_space != NULL){
        delete [] m_space;
        m_space = NULL;
        m_len = 0;
    }
}


int& MyArray::operator[](int index){
    return m_space[index];
}

int MyArray::getlen(){
    return m_len;
}


class myexcept : public exception{
public:
    myexcept(const char* p){
        this->m_p = p;
    }
    virtual const char* what(){
        cout<<"myexcept:"<<m_p<<endl;
        return m_p;
    }

private:
    const char* m_p;
};

void testMyExcept(){
    throw myexcept("error");
}


int main(){

    try
    {
       testMyExcept();
    }
    catch(myexcept &e){
        e.what();
    }
    catch(...){
        cout<<"don't know"<<endl;
    }
    
    cout<<"hello..."<<endl;
    return 0;
}
/*
int main(){

    try
    {
       MyArray a(-5);
       for(int i=0;i<a.getlen();i++){
        a[i] = i+1;
        printf("%d \n",a[i]);
        }
    }
    catch(MyArray::eSize &e){
        //cout<<"len's size"<<e.eSize()<<endl;
        e.printErr();
    }
    
    cout<<"hello..."<<endl;
    return 0;
}

/*
int main01(){

    try
    {
       MyArray a(-5);
       for(int i=0;i<a.getlen();i++){
        a[i] = i+1;
        printf("%d \n",a[i]);
    }
    }
    catch(MyArray::eNegative &e)
    {
       cout<<"eNegative is wrong."<<endl;
    }
    catch(MyArray::eTooBig &e)
    {
       cout<<"eTooBig is wrong."<<endl;
    }
    catch(MyArray::eTOOSmall &e)
    {
       cout<<"eTOOSmall is wrong."<<endl;
    }
    catch(MyArray::eZero &e)
    {
       cout<<"eZero is wrong."<<endl;
    }
    catch(...)
    {
       cout<<"eSize is wrong."<<endl;
    }
    
    
    cout<<"hello..."<<endl;
    return 0;
}
*/
