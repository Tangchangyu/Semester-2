#include"shape2.h"
#include<stdexcept>
#include<string>
#include <iostream>
using std::string;
using std::cout;
void shape::printDot(const double A[2])const{
        cout<<"("<<A[0]<<","<<A[1]<<") ";
    }

shape::shape(const string &s):id(s){
}

double shape::setArea(double s) { return area = s; }
double shape::getArea()const{
    return area;
}

void shape::print() const{
    cout<<id<<":\n";
}

shape::~shape(){};

twoDimensionShape::twoDimensionShape(const string &s):shape(s){};
twoDimensionShape::~twoDimensionShape(){};


threeDimensionShape::threeDimensionShape(const string &s):shape(s){};
 threeDimensionShape::~threeDimensionShape(){};
double threeDimensionShape::getVolume() const{
    return volume;
}
void threeDimensionShape::setVolume(double a){
    volume = a;
}
triangle::triangle(const string& s,const double a[2],const double b[2] ,const double c[2]):twoDimensionShape(s){
    // 或者用最基础的写法：
     A[0] = a[0]; A[1] = a[1];
     B[0] = b[0]; B[1] = b[1];
     C[0] = c[0]; C[1] = c[1];
    double S =0.5*( (A[0]-B[0])*(A[1]- C[1])-(A[1]- B[1])*(A[0]-C[0]));
    if(S==0){
        throw std::invalid_argument("Invalid triangle");
    }
    if (S<0){
        S=-S;
    }
    setArea(S);
}
triangle::~triangle(){};
void triangle::print()const{
    shape::print();
    cout<<"three point: ";
    printDot(A);
    printDot(B);
    printDot(C);
    cout<<"\narea: "<<getArea()<<std::endl;
}

square::square(const string& s,double a[2],double l):twoDimensionShape(s){
    leftTopDot[0]=a[0];leftTopDot[1]=a[1];
    l=l;
    setArea(l*l);
}

square::~square (){};
void square::print()const{
    shape::print();
    cout<<"lefttop: ";printDot(leftTopDot);
    cout<<"l: "<<l;
    cout<<"\narea: "<<getArea()<<std::endl;

}

circle::circle(const string& s, double o[2],double r):twoDimensionShape(s){
      if(r<=0){
            throw std::invalid_argument("Invalid circle");
    }
    else{
        R=r;
        Dot[0]= o[0];Dot[1]=o[1];
        setArea(3.14*r*r);
    }
}
circle::~circle(){};
void circle::print()const{
    shape::print();
    cout<<"O: ";printDot(Dot);cout<<"\nR: "<<R<<std::endl;
    cout<<"area: "<<getArea()<<std::endl;
}

sphere::sphere(const string& s, double o[2],double r):threeDimensionShape(s),R(r){
      if(r<=0){
            throw std::invalid_argument("Invalid circle");
    }
    else{
        Dot[0]= o[0];Dot[1]=o[1];
        setArea(4*3.14*r*r);
        setVolume(4*3.14*r*r*R/3);
    }
}
sphere::~sphere(){};
void sphere::print()const{
    shape::print();
    cout<<"O: ";printDot(Dot);cout<<"\nR: "<<R<<std::endl;
    cout<<"area: "<<getArea()<<"\nvolume: "<<getVolume();
}


