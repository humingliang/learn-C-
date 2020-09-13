#define _CRT_SECURE_NO_WARNINGS
#include"iostream"
#include"myString.h"
using namespace std;


int main() {
    myString s1;
    myString s2("s2");
    myString s2_2 = NULL;
    myString s3 = s2;
    myString s4 = "s4444444";

    s4 = s2;
    s4 = "s222444";
    s4[1] = '4';
    printf("%c \n", s4[1]);
    cout << s4 << endl;

    myString s5 = s2;
    if (s2 == "s2222") {
        printf("相等\n");
    }
    else {
        printf("不相等 \n");
    }

    if (s3 == s2) {
        printf("相等 \n");
    }
    else {
        printf("不相等\n");
    }

    if (s3 < "bbbb") {
        printf("小于\n");
    }
    else {
        printf("大于\n");
    }

    if (s3 < s2 ) {
        printf("小于\n");
    }
    else {
        printf("大于\n");
    }

    myString s6 = "aaaaafffff";
    strcpy(s6.c_str(), "aa111");//MFC
    cout << s6 << endl;

    myString s7(128);
    cout << "\n请输入字符串（回车结束）";
    cin >> s7;
    cout << s7 << endl;

    cout << "hello..." << endl;
    system("pause");
 }
