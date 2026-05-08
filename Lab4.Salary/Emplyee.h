#pragma once

#include<iostream>
#include<string>
using std::string;

class Employee{
private:
    string firstname;
    string lastname;
    string socialSecurityNumber;
public:

    Employee(const string& fn,const string &ln,const string& ssn ):firstname(fn),lastname(ln),socialSecurityNumber(ssn){

    }

    void setFirstname(const string &name){
        firstname = name;
    }

    void setLastname(const string &name){
        lastname = name;
    }

    void setSocialSecurityNumber(const string &name){
        socialSecurityNumber = name;
    }

    string getFirstname()const{
        return firstname;
    }

     string getLastname()const{
        return lastname;
    }

     string getSocialSecurityNumber()const{
        return socialSecurityNumber;
    }

    void print()const{
        using std::cout;
        cout<<getFirstname()<<" "<<getLastname()<<std::endl<<"social secirity number: "<<getSocialSecurityNumber();
    }
    
};