#include"shape2.h"
#include<stdexcept>
#include<string>
#include <iostream>
using std::string;
using std::cout;

shape::shape(const string &s):id(s){
}

double shape::getArea()const{
}

void shape::print() const{
    cout<<id<<":\n";
}

shape::~shape(){};

twoDimensionShape::twoDimensionShape(const string &s):shape(s){};
twoDimensionShape::~twoDimensionShape(){};

void twoDimensionShape::print()const{
    cout <<"area: "<<getArea()<<"/n";
}

double twoDimensionShape::getArea()const{};

threeDimensionShape::threeDimensionShape(const string &s):shape(s){};




triangle::triangle(const string& s,const double a[2],const double b[2] ,const double c[2]):twoDimensionShape(s){
    // 或者用最基础的写法：
     A[0] = a[0]; A[1] = a[1];
     B[0] = b[0]; B[1] = b[1];
     C[0] = c[0]; C[1] = c[1];
}


