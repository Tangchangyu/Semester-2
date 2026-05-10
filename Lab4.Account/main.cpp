#include"Account.h"
#include<vector>

using std::vector;
int main(){
    Account* a1=new SavingAccount(1000,0.01);
    Account* a2 = new CheckingAccount(9000,10);

    vector<Account*> ptr = {a1,a2};   

    
}