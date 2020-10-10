#include"iostream"
using namespace std;


void my_strcpy2(char *to,char *from){
    if(from == NULL){
        throw "buf1 is worry.";
    }

    if(to == NULL){
        throw "buf2 is worry.";
    }

    if(*from == 'a'){
        throw  "copy is worry!";
    }

    //copy时的场景检查
    while(*from != '\0'){
        *to = *from;
        to++;
        from++;
    }
    *to = '\0';
}




int main2(){

    int ret = 0;
    char buf1[]="abcdefg";
    char buf2[1024];

    try
    {
        my_strcpy2(buf2,buf1);
    }
    catch(int e)
    {
        cout<<e<<"int mode is worry."<<endl;
    }
    catch(const char *e)
    {
        cout<<e<<"char mode is wrong"<<endl;
    }
    catch(...)
    {
        cout<<"don't know."<<endl;
    }
    
    cout<<"hello.."<<endl;
    return 0;
}

//传统的错误处理机制
int my_strcpy(char *to,char *from){
    if(from == NULL){
        return 1;
    }

    if(to == NULL){
        return 2;
    }

    if(*from == 'a'){
        return 3;
    }

    //copy时的场景检查
    while(*from != '\0'){
        *to = *from;
        to++;
        from++;
    }
    *to = '\0';
    return 0;

}




int main1(){

    int ret = 0;
    char buf1[]="zbcdefg";
    char buf2[1024];

    ret = my_strcpy(buf2,buf1);
    if(ret != 0){
        switch (ret)
        {
        case 1:
            printf("buf1 is worry.");
            break;
        case 2:
            printf("buf2 is worry.");
            break;
        case 3:
            printf("copy is worry!\n");
            break;
        default:
            printf("don't know");
            break;
        }
    }

    printf("buf2:%s \n",buf2);


    cout<<"hello.."<<endl;
    return 0;
}
