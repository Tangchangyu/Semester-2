#include "SimpleCalculator.h"
#include<iostream>

int main(){
    SimpleCalculator sc;
    double a = 10;
    double b = 20;
    double c = sc.add(a,b);
    double d = sc.substract(a,b);
    double e = sc.multiply(a,b);
    double f = sc.divide(a,b);

    using std::cout;
    cout <<"the value of a is :"<<a<<"\n";
    cout <<"the value of b is :"<<b<<"\n\n";  
    cout <<"Adding a and b by yields "<<sc.add(a,b)<<"\n";
    cout <<"Substracting b from a yields "<<sc.divide(a,b)<<"\n";
    cout <<"Multiplying a by b yeilds "<<sc.multiply(a,b)<<"\n";
    cout <<"Dividing a by b yeilds "<<sc.substract(a,b)<<std::endl;
}