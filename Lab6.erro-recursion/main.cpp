#include<iostream>
#include<stdexcept>
#include<string>

using std::string;
using std::runtime_error;

class recurssion:public std::runtime_error{
public:
    recurssion(const string& message):runtime_error(message){}
};

int main(){
try{
    std::cout<<"This is a test\n";
    throw recurssion("abnormal program termination.\n");
}

catch(recurssion anError){
        throw recurssion("abnormal program termination.\n");

}
}