#pragma once

#include<iostream>
#include<string>
#include<stdexcept>
using std::string;
using std::cout;

class Employee{
private:
    string firstname;
    string lastname;
    string socialSecurityNumber;
    string birsday;
public:

    Employee(const string& fn,const string &ln,const string& ssn ,const string& bir):firstname(fn),lastname(ln),socialSecurityNumber(ssn),birsday(bir){

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

    virtual void print()const{
        using std::cout;
        cout<<getFirstname()<<" "<<getLastname()<<std::endl<<"social secirity number: "<<getSocialSecurityNumber();
    }
    
    virtual double earnings()const = 0;

};

class SalariedEmployee : public Employee{
private:
    double weeklySalary;
    void check() {
         if (weeklySalary <= 0 ){
            throw std::invalid_argument("salary must be >= 0.");
        }
    }
public:
    SalariedEmployee(const string& fn ,const string& ln, const string& ssn,const string &bir,double s = 0.0 ):Employee(fn,ln, ssn,bir),weeklySalary(s){
       check();
    };

    virtual ~SalariedEmployee(){};

    void setWeeklySalary(double s ){
        weeklySalary = s;
    }

    double getWeeklySalary()const{
        return weeklySalary;
    }

    virtual double earnings ()const override{return getWeeklySalary();}

    virtual void print() const override{
        std::cout<<"salaried employed:";
        Employee::print();
        std::cout <<"\nweekly salary: "<<getWeeklySalary();
    }
};

class CommissionEmployee: public Employee{
private:
    double grossSales;
    double commissionRate;
public:
    CommissionEmployee(const string& fn,const string &ln,const string& ssn,const string &bir,double a = 0.0,double b = 0.0):Employee(fn,ln, ssn,bir){
        setComissionrate(b);
        setGrossSales(a);
    }

    void setGrossSales(double s){
        if (s < 0 ){
            throw std::invalid_argument("gross sales must be >= 0 ");
        }
        else grossSales = s;
    }

    double getGrossSales()const{
        return grossSales;
    }

    void setComissionrate(double s){
        if (s < 0 ){
            throw std::invalid_argument("commission rate must be >= 0 ");
        }
        else commissionRate = s;
    }

    double getCommissionrate()const{
        return commissionRate;
    }

    virtual double earnings()const override{
        return getCommissionrate()*getGrossSales();
    }

    virtual void print ()const override{
        std::cout <<"commission employee: ";
        Employee::print();
        std::cout<< "\ngross sales: "<<getGrossSales()<<"; commission rate: "<<getCommissionrate();

    }

};

class hourlyEmployee: public Employee{
private:
    double hourlyWage;
    double hoursWorked;
public:
    hourlyEmployee(const string & fn,const string & ln,const string &ssn,const string &b,double hm=0.0,double h = 0.0):Employee(fn,ln,ssn,b){
        setHourlyWage(hm);
        setHoursWorked(h);
    }

    void setHourlyWage(double a ){
        if (a<=0){
            throw std::invalid_argument("hourly wage mustbe >= 0");
        }
        else hourlyWage = a;
    }
     void setHoursWorked(double a ){
         if (a<=0){
            throw std::invalid_argument("work hour mustbe >= 0");
        }
        else hoursWorked = a;
    }

    double getHourlyWage()const{
        return hourlyWage;
    }

    double getHoursWored()const{
        return hoursWorked;
    }

    virtual double earnings()const override{
        return hourlyWage*hoursWorked;
    }

    virtual void print()const override{
        std::cout <<"\nhourly employee: ";
        Employee::print();
        cout<<"hourly wage: "<<getHourlyWage()<<"; hours worked: "<<getHoursWored()<<"\n"
    }

}
