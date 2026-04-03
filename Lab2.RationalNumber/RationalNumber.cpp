#include"RationalNumber.h"
#include <iostream>
#include <stdexcpt.h>

RationalNumber::RationalNumber(int numer,int deno):numerator(numer),denominator(deno)
{
    if (denominator == 0){
        throw std::invalid_argument("Using 0 as denominator.");
    }

    else if (denominator < 0){
        denominator = - denominator;
        numerator = - numerator;
    }

reduction();
};//构造函数列表初始化的顺序只与声明顺序有关；

void RationalNumber::reduction(){
    int co = 1;
    for (int a = 1;a<=denominator;a++){
        if(numerator % a == 0&& denominator % a == 0){
            co = denominator;
        }
    }

    numerator = numerator / co;
    denominator = denominator / co;
}

RationalNumber RationalNumber::operator+(const RationalNumber& other) const{
    return RationalNumber(numerator*other.denominator+denominator*other.numerator,denominator*other.denominator);
}

RationalNumber RationalNumber::operator-(const RationalNumber& other) const{
    return RationalNumber(numerator*other.denominator-denominator*other.numerator,denominator*other.denominator);
}

RationalNumber RationalNumber::operator*(const RationalNumber& other) const{
    return RationalNumber(numerator*other.numerator, denominator*other.denominator);
}

RationalNumber RationalNumber::operator/(const RationalNumber& other) const{
    if (other.numerator == 0){ 
        throw std::invalid_argument("devided by 0");
        return *this;
    }


    else return RationalNumber(numerator*other.denominator, denominator*other.numerator);
}

bool RationalNumber::operator<(const RationalNumber& other)const{
    RationalNumber sub = *this - other;
    return (sub.numerator< 0 );
}

bool RationalNumber::operator==(const RationalNumber& other)const{
    return( numerator==other.numerator && denominator==other.denominator);
}

bool RationalNumber::operator!=(const RationalNumber& other)const{
    return !(*this == other);
}

bool RationalNumber::operator<=(const RationalNumber& other)const{
    return (*this ==  other|| *this<other);
}

bool RationalNumber::operator>(const RationalNumber& other)const{
    return !(*this <= other);
}

bool RationalNumber::operator>=(const RationalNumber& other)const{
    return !(*this < other);
}

void RationalNumber::printRational() const{
    std::cout <<numerator <<"/" <<denominator;
}