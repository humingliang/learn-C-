#include "iostream"
#include "algorithm"
#include "deque"
using namespace std;

void printD(deque<int> &d){
    for(deque<int>::iterator it = d.begin(); it != d.end();it++ ){
        cout<<*it<<" ";
    }
}



void main41(){
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(3);
    d1.push_back(5);

    d1.push_front(-11);
    d1.push_front(-33);
    d1.push_front(-55);

    cout<<"the head: "<<d1.front()<<endl;
    cout<<"the tall: "<<d1.back()<<endl;
    printD(d1);
    printf("\n");

    d1.pop_front();
    d1.pop_back();
    printD(d1);
    printf("\n");

    //查找-33在数组的下标
   deque<int>::iterator it = find(d1.begin(),d1.end(),-33);
    if(it != d1.end()){
        cout<<"there is "<<distance(d1.begin(),it)<<endl;
    }
    else{
        cout<<"Don't find it "<<endl;
    }

}

int main(){

    main41();

    cout<<"hello..."<<endl;
    return 0;
}
