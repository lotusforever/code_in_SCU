#include <iostream>
#include <string>
using namespace std;
int mystrlen(const char* str){
    if (str==NULL) {
        return 0;
    }
    const char*temp=str;
    while (*temp!='\0') {
        temp++;
    }return temp-str;
}
int my_strlen(const char* str) {
    int length=0;
    if (str==NULL) {return 0;}
    while (*str!=0) {
        str++;
        length++;
    }return length;
}
char* my_strcpy(char* dest, const char* src){
    while (*src!='\0') {
        *dest++=*src++;
    }return dest;
}
int main() {
    //实现c语言中的strlen、strcat函数
    char* s1="abcd",*s2="efg";
    cout<<mystrlen(s1)<<endl;
    cout<<my_strlen(s2)<<endl;
    while (*s1!='\0') {
        cout<<*s1++<<" ";
    }cout<<endl;
    return 0;
}