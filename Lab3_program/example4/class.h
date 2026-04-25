#pragma once
#include <iostream>
using std::cout;
using std::endl;

class MyBase {
int x;
public:
MyBase(int a) :x(a) {}
int getX() { cout << " " << endl; return x; }
};

class MyDerived : public MyBase {
int y;
public:
MyDerived(int a) :y(a), MyBase(a + 4){}
int getY() { cout << " " << endl; return y; }
};