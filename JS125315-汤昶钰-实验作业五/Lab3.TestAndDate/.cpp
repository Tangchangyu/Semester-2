#include <iostream>
#include <stdexcpt.h>
#include ".h"
Date::Date(short y ,short m,short d):year(y),month(m),day(d){
   check();
}

void Date::check(){
    if (!(2000<=year&&year<3000 && month>0&&month<13 &&day>0&&day<32)){
        throw std::invalid_argument("Invalide date\n");
        year = 2014;
        month = 1;
        day = 1;
    }
}
Date Date::setDate(Date newDate){
    *this = newDate;
    return *this;
}

void Date::print()const{
    using std::cout;
    cout<<year<<"-"<<month<<"-"<<day<<std::endl;
}

FinalTest::FinalTest(const char* a,const Date& d):date(d){
    const char* flag = a;
    while(*flag != '\0'){
        name[flag - a]= a [flag - a];
        flag ++;
        if (flag - a == 100) {
            throw std::invalid_argument("The name is too long.\n");
            break;
        }
    }

};

FinalTest::FinalTest(const char* a){
    
    Date def;
    date = def;
    const char* flag = a;
    while(*flag != '\0'){
        name[flag - a]= a [flag - a];
        flag ++;
        if (flag - a == 100) {
            throw std::invalid_argument("The name is too long.\n");
            break;
        }
    }
}

void FinalTest::setDue(const Date& d){
    date.setDate(d);
}

void FinalTest::print()const{
    std::cout<<"Title:" <<name <<"\nDate:";
    date.print();
}
