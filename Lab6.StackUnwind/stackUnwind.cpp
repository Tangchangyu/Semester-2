#include <stdexcept>
#include<string>
#include<iostream>

using std::runtime_error;
using std::string;
using std::cout;

static int time = 0;

class TestException: public runtime_error{
    public:
    TestException(const string& s):runtime_error(s){};

};

void f(){
    cout<<"function f() has been called\n";
    throw TestException("this is an exception.");
    time++;
}

void g(){
    cout <<"function g() has been called.\n";
    try{
        f();
    }

    catch(...){
       cout<<"Caught TestException in g().\n";
       cout<<"time:"<<time<<std::endl;
    };
}

void h(){
    cout<<"function h() has been called.\n";
    try{
        f();
        g();
    }
    catch(...){
        cout<<"Caught TestException in h().\n";
               cout<<"time:"<<time<<std::endl;
    }
}

int main(){
    g();
    h();
}