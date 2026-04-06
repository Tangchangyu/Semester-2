#include <iostream>
#include "HUgeInt.h"
using std::cout;

void printNum(const HugeInt& num,const char* name){
    cout<< name <<"is "<<num <<"\n";
}

int main(){
    HugeInt n1 = 7654321;
    HugeInt n2 = 7891234;
    HugeInt n3 = "9999999999999999999999999999";
    HugeInt n4 = 1;
    HugeInt n5 = 12341234;
    HugeInt n6 = 7888;
    HugeInt result = 0L;
    printNum(n1,"n1");
    printNum(n2,"n2");
    printNum(n3,"n3");
    printNum(n4,"n4");
    printNum(n5,"n5");
    printNum(n6,"n6");
    printNum(n1,"n1");
    printNum(result,"result");

    cout <<" n1 is "<<((n1 == n2)?"":"not")<<"equal to n2\n";
    cout <<" n1 is "<<((n1 < n2)?" ":"not")<<"less than n2\n";
    cout <<" n1 is "<<((n1 <= n2)?"":"not")<<"less than or equal to n2\n";

    cout <<"\n"<<n1<<" + "<<n2 <<" = "<<n1+n2 <<std::endl;
    cout <<"\n"<<n3<<" + "<<n4 <<" = "<<n3+n4 <<std::endl;

    cout <<n1 <<" + 9 = " <<n1+9<<"\n";
    cout <<n2 <<" + 10000 = "<<n2 + 10000<<"\n";
    cout <<n5 << "* 7888 "<< "= "<< n5*7888<<"\n";
    cout <<n5 << "- 7888 "<< "= "<< n5-7888<<"\n";
    cout <<n5 << "/ 7888 "<< "= "<< n5/7888<<"\n";
}  

