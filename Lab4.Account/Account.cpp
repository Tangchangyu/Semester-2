#include"Account.h";
#include <stdexcept>;
#include<iostream>
using std::cout;

Account::Account(double a):balance(a){
    if (a<=0){
        throw std::invalid_argument("Invalid balance, balance must be >= 0.");
        balance = 0;
    }
}

void Account::credit(double m){
    balance +=m;
}

bool Account::debit(double m){
    if (m>= balance){
        cout<<"\nDebit amount exceeded account balance.";
        return false;
    }
    else {
        balance -= m;
        return true;
    }
}

double Account::getBalance()const{
    return balance;
}

Account::~Account(){};

SavingAccount::SavingAccount(double a,double b):Account(a),rate(b){
    if(rate <= 0 ){
        throw std::invalid_argument("Invalid rate, rate must be >= 0.");
    }
}

double SavingAccount::calculateInterest() const{
    return getBalance()*rate;
}

CheckingAccount::CheckingAccount(double a,double b):Account(a),cost(b){
    if(cost <= 0 ){
        throw std::invalid_argument("Invalid cost, cost must be >= 0.");
    }
}

void CheckingAccount::credit(double a){
    if (getBalance() + a - cost>= 0){
        Account::credit(a);
        Account::debit(cost);
    }

    else {
        cout <<"\nCost exceeded credit and balance. Break\n";
    }

}

bool CheckingAccount::debit(double a ){
    return Account::debit(a+cost);
}

