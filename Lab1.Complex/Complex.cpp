#include"Complex.h"
#include<iostream>

Complex::Complex(double a,double b):realPart(a),imaginaryPart(b){};
Complex Complex::operator+(const Complex& other) const{
    return Complex(other.realPart+realPart, other.imaginaryPart+imaginaryPart);
}

Complex Complex::operator-(const Complex& other) const{
    return Complex(realPart-other.realPart,imaginaryPart-other.imaginaryPart);
}

void Complex::print() const{
    using std::cout;
    cout<<"("<<realPart<<","<<imaginaryPart<<")";

}