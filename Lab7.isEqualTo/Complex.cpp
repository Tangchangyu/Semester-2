#include"Complex.h"
#include<iostream>

Complex::Complex(double a,double b):realPart(a),imaginaryPart(b){};
Complex Complex::operator+(const Complex& other) const{
    return Complex(other.realPart+realPart, other.imaginaryPart+imaginaryPart);
}

Complex Complex::operator-(const Complex& other) const{
    return Complex(realPart-other.realPart,imaginaryPart-other.imaginaryPart);
}


Complex Complex::operator*(const Complex& other) const{
    return Complex(realPart*other.realPart-imaginaryPart*other.imaginaryPart,realPart*other.imaginaryPart+imaginaryPart*other.realPart);
}

bool Complex::operator==(const Complex& other ) const{
    return (realPart==other.realPart && imaginaryPart== other.imaginaryPart);
}

bool Complex::operator!=(const Complex& other)  const{
    return (!(*this==other));
}
void Complex::print() const{
    using std::cout;
    cout<<"("<<realPart<<","<<imaginaryPart<<")";

}

std::ostream& operator<<(std::ostream& os,const Complex& c){
    os << "("<<c.realPart <<"," <<c.imaginaryPart <<")";
    return os;
}

std::istream& operator>>(std::istream& is,Complex& c){
    is.ignore(10,'(');
    is >> c.realPart;
    is.ignore(10,',');
    is >> c.imaginaryPart;
    is.ignore(10,')');
    return is;
}//**


