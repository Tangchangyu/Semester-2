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

        SavingAccount* savingsPtr = dynamic_cast<SavingAccount*>(accPtr);//判断accPtr是否为<SavingsAccount*>（或其子类），若不是则返回nullptr;

        if (savingsPtr != nullptr)//如果转换成功
        {
            double interest = savingsPtr->calculateInterest();
            savingsPtr->credit(interest);
            std::cout <<"Credition has been done. \n";

        }

        std::cout <<"Balance: "<<accPtr->getBalance()<<std::endl;

    }
// 在循环处理完逻辑后
    for (Account* accPtr : ptr) {
        delete accPtr;
    }
// 建议清空 vector，防止出现悬空指针
    ptr.clear();
}

