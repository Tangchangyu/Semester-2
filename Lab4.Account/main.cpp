#include"Account.h"
#include<vector>
#include<iostream>


using std::vector;
int main(){
    Account* a1=new SavingAccount(1000,0.01);
    Account* a2 = new CheckingAccount(9000,10);

    vector<Account*> ptr = {a1,a2};   

    for (Account* accPtr: ptr){
        accPtr->debit(10);
        accPtr->credit(100);

        SavingAccount* savingsPtr = dynamic_cast<SavingAccount*>(accPtr);

        if (savingsPtr != nullptr){
            double interest = savingsPtr->calculateInterest();
            savingsPtr->credit(interest);
            std::cout <<"Credition has been done. \n";

        }

        std::cout <<"Balance: "<<accPtr->getBalance()<<std::endl;
        
    }

}