#pragma once
class Complex{
    private:
    double realPart;
    double imaginaryPart;

    public:
    Complex(double = 0, double = 0);
    Complex operator+ (const Complex&)const;
    Complex operator- (const Complex&) const;
    Complex operator* (const Complex&) const;
    bool operator== (const Complex&)const;
    bool operator!= (const Complex&)const;

    void print() const;


    friend std::ostream& operator<<(std::ostream&, const Complex& );
    friend std::istream& operator>>(std::istream&, const Complex& );

};