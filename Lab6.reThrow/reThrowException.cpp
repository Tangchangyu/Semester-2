#include<stdexcept>
#include<iostream>
#include<string>


using std::runtime_error;
using std::string;
using std::cout;

class TestException: public runtime_error{
    public:
    TestException(const string &s):runtime_error(s){
        cout<<"catch an exception."<<std::endl;
    }



};

void g(){
    try{
        throw TestException("an TestException.");
    }
    catch (const TestException& ex){
        ex.what();
        throw ex;
    }
}