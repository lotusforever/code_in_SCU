//
// Created by ASUS on 2025/11/12.
//

#ifndef STRING_H
#define STRING_H
#include <stdexcept>
#include <string.h>
using namespace std;
class CharString {
private:
    char* val;
    int length;
public:
    CharString();
    ~CharString();
    CharString(const CharString &);
    CharString(const char *);
    int Length()const;
    bool Empty()const;
    CharString & operator=(const CharString &);
    char &operator[](int pos)const;
    friend void Cat(CharString& target,const CharString& source);
    friend void Copy(CharString& target,const CharString& source);
    friend ostream& operator<<(ostream&, const CharString&);
};

CharString::CharString() {
    length=0;
    val=nullptr;
}

CharString::~CharString() {
    if(val!=nullptr) {
        delete[] val;
    }
    length=0;
}

CharString::CharString(const CharString&source) {
    length=source.length;
    val=new char[length+1];
    strcpy(val,source.val);
}

CharString::CharString(const char *source) {
    length=strlen(source);
    val=new char[length+1];
    strcpy(val,source);//不能使用val=source来浅拷贝，，否则析构时会重复释放同一块内存
}

int CharString::Length()const {
    return length;
}

bool CharString::Empty()const {
    return length==0;
}

CharString & CharString::operator=(const CharString &source) {
    if (this==&source) {
        return *this;
    }//自我赋值
    delete[]val;
    length=source.length;
    val=new char[length+1];
    strcpy(val,source.val);
    return *this;
}

char &CharString::operator[](int pos) const {
    if(pos<0||pos>length) {
        throw std::out_of_range("CharString::operator[]");
    }
    return val[pos];
}

void Cat(CharString& target,const CharString& source) {
    int   newLen = target.length + source.length;
    char* newVal = new char[newLen + 1];

    strcpy(newVal, target.val);      // 先把旧内容拷进来
    strcat(newVal, source.val);      // 再拼接 source

    delete[] target.val;             // 确保旧内存释放
    target.val    = newVal;
    target.length = newLen;
}

void Copy(CharString& target,const CharString& source) {
    delete[] target.val;
    target.val=new char[source.length+1];
    strcpy(target.val,source.val);
    target.length=source.length;
}

ostream& operator<<(ostream& os,const CharString& source) {
    return os<<source.val;
}

#endif //STRING_H
