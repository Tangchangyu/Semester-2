#include<stdexcept>
#include<iostream>
#include<string>


using std::runtime_error;
using std::string;
using std::cout;

class TestException: public runtime_error{
    public:
    TestException(const string &s):runtime_error(s){
    }



};

void g(){
    try{
        throw TestException("an TestException.");
    }
    catch (...){
        cout<<"Exception caught in function g(). Rethrowing... \n";
        throw ;
    }
}

int main(){
    try{
        g();
    }

    catch (const runtime_error& ex){
        cout<<"Excetion caught in function main()\n";
        cout<<ex.what();
    }
}