#include"iostream"
using namespace std;


struct Teacher { 
    char name[64]; 
    int age; 
}; 
int getTe(Teacher **myp ){ 
    Teacher *p = (Teacher *)malloc(sizeof(Teacher)); 
    if (p ==NULL){ 
        return -1; 
    } 
   // memset(p, 0, sizeof(Teacher)); 
    p->age = 33;
    *myp = p; // 
    return 0; 
} 
// 指针的引用而已
int getTe2(Teacher* &myp){ 
    //给myp赋值，就是给pT1赋值
    myp = (Teacher *)malloc(sizeof(Teacher)); 
    myp->age = 34; 
    return 0; 
} 


void FreeTe(Teacher *pT1){
    if(pT1==NULL){
        return ;
    }
    free(pT1);
}
int main(){ 
    Teacher *pT1 = NULL; 
    //C语言中的二级指针
    getTe(&pT1); 
    printf("age:%d \n", pT1->age); 
    FreeTe(pT1);
    //C++中的引用（指针的引用）
    getTe2(pT1); 
    printf("age:%d \n", pT1->age); 
    FreeTe(pT1);
    system("pause"); 
}
