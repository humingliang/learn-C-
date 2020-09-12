#pragma once
class Array{ 
private: 
    int mLength; 
    int* mSpace; 
public: 
    Array(int length); 
    Array(const Array& obj); 
    ~Array(); 

    int length(); 
    void setData(int index, int value); 
    int getData(int index); 
    int& operator[](int i);//中括号重载
    Array& operator=(Array &a1);//等号操作符重载
    bool operator==(Array &a1);//==操作符重载
    bool operator!=(Array &a1);//==操作符重载
}; 


Array::Array(int length){
        if(length<0){
            length = 0;
        }
        mLength = length;
        mSpace = new int[mLength];
    }

    Array::Array(const Array& obj){
        this->mLength = obj.mLength;
        this->mSpace  = new int[this->mLength];//分配内存空间-深拷贝
        for(int i=0; i<this->mLength; i++){//元素复制
            this->mSpace[i]=obj.mSpace[i];
        }
    }

    Array::~Array(){
        if (mSpace!=nullptr){
            delete[]mSpace;
            mLength = 0;
        }
    }

    int Array::length(){
        return mLength;
    }

    void Array::setData(int index, int value){
        mSpace[index]=value;
    }

    int Array::getData(int index){
        return mSpace[index];
    }

    int& Array::operator[](int i){
        return mSpace[i];
    }

    Array& Array::operator=(Array &a1){
        //释放原来的内存空间
        if(this->mSpace!=NULL){
            delete [] this->mSpace;
            this->mLength=0;
        }

        //按照a1大小，分配内存
        mLength = a1.mLength;
        mSpace = new int [a1.mLength];

        //拷贝赋值
        for ( int i=0;i<a1.mLength;i++){
            //mSpace[i]=a1.mSpace[i];
            mSpace[i]=a1[i];
        }

        return *this;
    }

    bool Array::operator==(Array &a1){
        if(this->mLength!=a1.mLength){
            return false;
        }

        for (int i; i<this->mLength; i++){
            if(this->mSpace[i]!=a1[i]){
                return false;
            }
        }
        return true;
    }

    bool Array::operator!=(Array &a1){
        if(*this == a1){
            return false;
        }
        else{              
            return false;
        }

    }
