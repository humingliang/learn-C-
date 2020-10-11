#include "iostream"
#include "algorithm"
#include "set"
#include "string.h"
using namespace std;

void main10(){
    multiset<int> ms1;
    int tmp = 0;
    printf("please input:");

    scanf("%d",&tmp);
    while(tmp!=0){
        ms1.insert(tmp);
        printf("please input:");
        scanf("%d",&tmp);
    }

    for(multiset<int>::iterator it = ms1.begin();it !=ms1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    while(!ms1.empty()){
        multiset<int>::iterator it = ms1.begin();
        cout<<*it<<" ";
        ms1.erase(it);  
    }

}

int main(){

    main10();


    cout<<"hello..."<<endl;
    return 0;
}
