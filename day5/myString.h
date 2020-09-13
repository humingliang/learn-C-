#pragma once
#include <iostream>
using namespace std;

class myString {
public:
    myString(int len=0);
    myString(const char* p);
    myString(const myString& S);
    ~myString();

public://重载等号操作符
    myString& operator=(const char* p);
    myString& operator=(const myString& s);
    char& operator[](int index);
    friend ostream& operator<<(ostream& out, myString& s);
    friend istream& operator>>(istream& inc, myString& s);

public:    //等于/不等于重载
    bool operator==(const char* p) const;
    bool operator==(const myString& s)const;
    bool operator!=(const char* p)const;
    bool operator!=(const myString& s)const;

public:
    int operator>(const char* p) const;
    int operator<(const char* p)const;
    int operator>(const myString& s)const;
    int operator<(const myString& s)const;

public://把类的私有属性露出来
    char  *c_str() {
        return m_p;
    }

    const char* c_str2() {
        return m_p;
    }

    int length() {
        return m_len;
    }
    
private:
    int m_len;
    char* m_p;

};
