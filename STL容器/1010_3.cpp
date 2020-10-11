#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

//数组元素添加与删除
void main31(){
    vector<int> v1;

    cout<<"lenrth: "<<v1.size()<<endl;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    cout<<"lenrth: "<<v1.size()<<endl;

    //修改头部元素的值,函数返回值当左值，引用
    v1.front() = 11;
    v1.back() =55;


    while(v1.size()>0){
        cout<<v1.back()<<" ";//获取尾部元素
        v1.pop_back();//删除尾部元素
    }
}

//初始化
void main32(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);
    
    vector<int> v2 = v1;
    vector<int> v3(v1.begin(),v1.begin()+2);//初始化
}


void printV(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

//vector的遍历
void main33(){
    vector<int> v1(10);//提前准备好内存
    for(int i=0;i<10;i++){
        v1[i] = i+1;
    }

    //for(int i=0;i<10;i++){
    //    printf("%d",v1[i]);
    //}

    printV(v1);

    
    vector<int> v2 = v1;
    vector<int> v3(v1.begin(),v1.begin()+2);//初始化
}

//push_back的强化记忆
void main34(){
    vector<int> v1(10);//提前准备好内存
    v1.push_back(100);
    v1.push_back(200);
    cout<<"lenrth: "<<v1.size()<<endl;
    printV(v1);
}

//迭代器
//v1.end()遍历结束
void main35(){
    vector<int> v1(10);//提前准备好内存
    for(int i=0;i<10;i++){
        v1[i] = i+1;
    }

    //正向遍历
    for(vector<int>::iterator it = v1.begin();it != v1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //反向遍历
    for(vector<int>::reverse_iterator rit = v1.rbegin(); rit != v1.rend();rit++){
        cout<<*rit<<" ";
    }
    cout<<endl;
    
}

//v1.end()遍历结束
void main36(){
    vector<int> v1(10);//提前准备好内存
    for(int i=0;i<10;i++){
        v1[i] = i+1;
    }

    //区间删除
    v1.erase(v1.begin(),v1.begin()+3);
    printV(v1);
    printf("\n");

    //指定位置删除
    v1.erase(v1.begin());
    printV(v1);
    printf("\n");

    //根据元素的值
    v1[1]=2;
    v1[4]=2;
    printV(v1);
    printf("\n");
    for(vector<int>::iterator it = v1.begin();it != v1.end();){
        if(*it == 2){
            it = v1.erase(it);//当删除迭代器指向元素会自动下移
        }
        else{
            it++;
        }
    }
    printV(v1);
    printf("\n");

    v1.insert(v1.begin(),100);
    v1.insert(v1.end(),100);
    printV(v1);
    printf("\n");



    
}



int main(){

    //main31();
    //main32();
    //main33();
    //main34();
    //main35();
    main36();


    cout<<"hello.."<<endl;
    return 0;
}
