#include <iostream>
#include "string.h"
using namespace std;
int main() {
    const char* val="helloworld";
    const char* val2="123";
    CharString s1(val);
    cout<<"s1:"<<s1<<endl;
    cout<<"s1的长度是："<<s1.Length()<<endl;
    if (s1.Empty()) {
        cout<<"s1是空串"<<endl;
    }else {
        cout<<"s1不是空串"<<endl;
    }
    CharString s2(s1);
    cout<<"s2:"<<s2<<endl;
    CharString s3(val2);
    s2=s3;
    cout<<"赋值后s2:"<<s2<<endl;
    Cat(s1,s2);
    cout<<"把s2添加到s1后面:"<<s1<<endl;
    return 0;
}