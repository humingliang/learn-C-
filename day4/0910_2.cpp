#include "iostream" 
#include "Array.h" 
using namespace std; 

int main(){
    Array a1(10); 
    for(int i=0; i<a1.length(); i++){ 
        //a1.setData(i, i); 
        a1[i]=i;//中括号重载，返回一个引用
    } 

    for(int i=0; i<a1.length(); i++){ 
        //printf("array %d: %d\n", i, a1.getData(i)); 
        cout<<a1[i]<<endl;//也可以作为引用出现
    } 

    Array a2 = a1; 

    for(int i=0; i<a2.length(); i++) { 
        printf("array %d: %d\n", i, a2.getData(i)); 
    } 

    Array a3(5);
    a3=a1;
    //a3=a2=a1;
    for(int i=0; i<a3.length(); i++){ 
        cout<<a3[i]<<endl;//也可以作为引用出现
    } 

    if (a3==a1){
        printf("YES\n");
    }
    else{
        printf("No\n");
    }

    if (a3!=a1){
        printf("YES\n");
    }
    else{
        printf("No\n");
    }

    system("pause"); 
    return 0; 
}
