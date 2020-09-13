#define _CRT_SECURE_NO_WARNINGS

#include "myString.h" 
#include "string.h"


myString::myString(int len) {
    if (len == 0) {
        m_len = 0;
        m_p = new char[m_len + 1];
        strcpy(m_p, "");
    }
    else {
        m_len = len;
        m_p = new char[m_len + 1];
        memset(m_p, 0, m_len);
    }
}

myString::myString(const char* p) {
    if (p == NULL) {
        m_len = 0;
        m_p = new char[m_len + 1];
        strcpy(m_p, "");
    }
    else {
        m_len = strlen(p);
        m_p = new char[m_len + 1];
        strcpy(m_p, p);

    }


}
//拷贝构造函数
myString::myString(const myString& S) {
    m_len = S.m_len;
    m_p = new char[m_len + 1];
    strcpy(this->m_p, S.m_p);
}

myString::~myString() {
    if (m_p != NULL) {
        delete m_p;
        m_p = NULL;
        m_len = 0;
    }
}

myString& myString::operator=(const char* p){
    if (m_p != NULL) {
        delete[] m_p;
        m_len = 0;
    }

    //分配内存
    if (p == NULL) {
        m_len = 0;
        m_p = new char[m_len + 1];
        strcpy(m_p, "");

    }
    else {
        m_len = strlen(p);
        m_p = new char[m_len + 1];
        strcpy(m_p, p);
    }
    return *this;
}

myString& myString::operator=(const myString& s){
    if (m_p != NULL) {
        delete[] m_p;
        m_len = 0;
    }

    //分配内存
    m_len = s.m_len;
    m_p = new char[m_len + 1];
    strcpy(m_p, s.m_p);
 
    return *this;
}

char& myString::operator[](int index){
    return m_p[index];
}

bool myString::operator==(const char* p)const{
    if (p == NULL) {
        if (m_len == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        if (m_len == strlen(p)) {
            return !strcmp(m_p, p);
        }
        else {
            return false;
        }
    }
}

bool myString::operator!=(const char* p)const{
    return !(*this == p);
}

bool myString::operator==(const myString& s)const{
    if (m_len != s.m_len) {
        return false;
    }
    return !strcmp(m_p, s.m_p);
    
}

bool myString::operator!=(const myString& s)const{
    return !(*this== s);
}

ostream& operator<<(ostream& out, myString& s){
    out << s.m_p;
    return out;
}

istream& operator>>(istream& inc, myString& s)
{
    inc >> s.m_p;
    return inc;
}

int myString::operator>(const char* p) const{
    return strcmp(p,this->m_p);
}

int myString::operator<(const char* p) const{
    return strcmp(this->m_p,p);
}

int myString::operator>(const myString& s) const{
    return strcmp(s.m_p, this->m_p);
}

int myString::operator<(const myString& s) const{
    return strcmp(this->m_p, s.m_p);;
}

