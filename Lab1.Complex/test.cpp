#include<iostream>
#include"Complex.h"

void print(Complex a,const char* cha,Complex b,Complex c){
    a.print();
    std::cout<<cha;
    b.print();
    std::cout<<" = ";
    c.print();
    std::cout <<"\n";
}
int main(){
    Complex a (1,7);
    Complex b (9,2);
    Complex c (a+b);
    Complex d (10,1);
    Complex e(11,5);
    Complex f (d-e);
    print(a," + ",b,c);
    print(d," - ",e,f);

}