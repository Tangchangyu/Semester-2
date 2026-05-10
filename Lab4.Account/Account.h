#pragma once 

class Account{
    double balance;

public :
    Account(double  = 0);
    virtual void credit(double);
    virtual bool debit(double);
    double getBalance()const;
    virtual ~Account()=0;
};

class SavingAccount:public Account{
    double rate;

public:
    SavingAccount(double =0,double = 0);
    double calculateInterest() const;
};

class CheckingAccount:public Account{
    double cost;

public:
    CheckingAccount(double =0,double = 0);
    void credit(double) override;
    bool debit(double) override;
};