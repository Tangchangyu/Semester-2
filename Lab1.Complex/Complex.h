#pragma once
class Complex{
    private:
    double realPart;
    double imaginaryPart;

    public:
    Complex(double = 0, double = 0);
    Complex operator+ (const Complex&)const;
    Complex operator- (const Complex&) const;
    void print() const;

};