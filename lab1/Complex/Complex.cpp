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
    if (realPart==other.realPart && imaginaryPart== other.imaginaryPart) return 1;
    else return 0;
}

bool Complex::operator!=(const Complex& other)  const{
    return (1-(*this==other));
}
void Complex::print() const{
    using std::cout;
    cout<<"("<<realPart<<","<<imaginaryPart<<")";

}

std::ostream& operator<<(std::ostream& os,const Complex& c){
    os << "("<<c.realPart <<"," <<c.imaginaryPart <<")";
    return os;
}

std::istream& operator>>(std::istream& is, const Complex& c){
    is.ignore(100,'(');
    is >> c.realPart;
    is.ignore(100,',');
    is.ignore(100,')');
    return is;
}//**


