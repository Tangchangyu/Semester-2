#include "Complex.h"
#include<iostream>
using std::cout;

template<class T>
bool isEqualTo(T a,T b){
    if (a == b) return true;
    else return false;
}
//支持int ,double等。不支持char*  ?
template<class T>
void print(T a,T b){
    cout<<a<<(isEqualTo(a,b)?" is":" is not ")<<"equal to "<<b<<std::endl;
}//封装输出逻辑；

/*
//常见类型的isEqualTo调用；
int main(){
    int a=0, b = 1;
    double c =1.8;
    char d  = 'i';
    bool f = true;
   
    print( a ,b);
    print(c,1.8);
    print (d,'n');
    print(f,true);

}*/


//main for Complex test
int main(){
    cout<<isEqualTo(Complex(1,1),Complex(1,1));
}
    //若未定义==，报错：undefined reference to `Complex::operator==(Complex const&) const'


