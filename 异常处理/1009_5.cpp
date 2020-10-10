#include"iostream"
#include"fstream"
using namespace std;
 
int main(){   
    char* fname = "2.txt";
    ofstream outfile(fname);//输出流,和文件关联
    outfile<<"hello....1"<<endl;
    outfile<<"hello....2"<<endl;
    outfile<<"hello....3"<<endl;
    outfile.close();
   
    //读文件
    ifstream fin(fname);//建立输入流
    char ch;
    while (fin.get(ch)){
        cout<<ch;
    }

    fin.close();
    
    cout<<"hello..."<<endl;
 }
