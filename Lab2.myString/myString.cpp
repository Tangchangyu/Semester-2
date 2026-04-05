#include "myString.h"
#include <iostream>

ostream& operator<<(ostream& os,const String& s){
    os<<s.sPtr;//*表示第一个字符；
    return os;
}//j记得返回值

String::String(const char* const s ){
    const char* end = s;
    while(*end != '\0'){
        end ++;
    }
    length = end - s +1;
    sPtr = new char [length];
    for(int i = 0; i < length; i ++){
        sPtr[i]= *(s+i);
    }

}

String::String(const String& s){
    length = s.length;
    sPtr = new char[length];
    for(int i = 0;i < length;i ++){
        sPtr[i]= s.sPtr[i];
    }
}

String::~String(){
    delete []sPtr;
}

const String& String::operator=(const String& s){
    if(this == &s) return *this;//检查地址是否相同，相同就返回自身：

    length = s.length;
    delete []sPtr;
    sPtr = new char[length];
    for(int i = 0; i < length;i++){
        sPtr[i]= s.sPtr[i];
    }

    return *this;
}//有指针的类，构造、析构、= 需要重载；

String String::operator+(const String& s)const{
    using namespace std;
    //char rPtr[length+s.length-1] =*sPtr+*s.sPtr;
    //1.此处加，代表把两个字符的acsii码相加；
    //2.在标准 C++ 中，数组的大小必须是编译期常量。[length+s.length-1]不合规;

    //解决方案1，将rPtr放在堆上，同时采用循环分别录入;

    int newLength = s.length+length - 1;
    char * result = new char[newLength];
    strcpy(result , sPtr);
    strcat(result , s.sPtr);
    String rst(result);
    delete[]result;

    return rst;
};

