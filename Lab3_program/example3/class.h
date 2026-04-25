#pragma once
#include <iostream>

using std::cout;
using std::endl;

class MyBase3
{
protected:
int x;
void fun1() { cout << "MyBase3-- - fun1()" << endl; }
protected:
int y;
void fun2() { cout << "MyBase3-- - fun2()" << endl; }
public:
int z;
MyBase3(int a = 0, int b = 1, int c = 2) { x = a; y = b; z = c; }
int getX() { cout << "MyBase3-- - x:" << endl; return x; }
int getY() { cout << "MyBase3-- - y:" << endl; return y; }
int getZ() { cout << "MyBase3-- - z:" << endl; return z; }
void fun3() { cout << "MyBase3-- - fun3()" << endl; }
};

class MyDerived1 : public MyBase3 
{
int p;
public:
MyDerived1(int a): p(a)
{ cout << "MyDerived-- - p:" << endl;}
int getP() { return p; }
void display()
{
cout << p << " " << x << " " << y << " " << z <<" " << endl
<< fun1() << endl << fun2() << endl << fun3() << endl;
}
};

class MyDerived2 : private MyBase3 {
int p;
public:
MyDerived2(int a) : p(a)
{
cout << "MyDerived-- - p:" << endl;
}
int getP() { return p; }
int display()
{
cout << p << " " << x << " " << y << " " << z << " " << endl
<< fun1() << endl << fun2() << endl << fun3() << endl;
}
};

class MyDerived21 : public MyBase3 {
int p;
public:
MyDerived21(int a) : p(a)
{
cout << "MyDerived-- - p:" << endl;
}
int getP() { return p; }
int display1()
{
cout << p << " " << x << " " << y << " " << z << " " << endl;
}
};

class MyDerived2 : private MyBase3 {
int p;
public:
MyDerived2(int a) : p(a)
{
cout << "MyDerived-- - p:" << endl;
}
int getP() { return p; }
int display()
{
cout << p << " " << x << " " << y << " " << z << " " << endl
<< fun1() << endl << fun2() << endl << fun3() << endl;
}
};

class MyDerived21 : public MyBase3 {
int p;
public:
MyDerived21(int a) : p(a){
cout << "MyDerived-- - p:" << endl;
}
int getP() { return p; }
int display1()
{
cout << p << " " << x << " " << y << " " << z << " " << endl;
}
};