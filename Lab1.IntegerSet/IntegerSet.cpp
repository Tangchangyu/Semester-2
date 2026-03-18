#include"IntegerSet.h"
#include<stdexcept>
#include<iostream>
bool validEntry(int a){
    if (a >=0 && a <101) return 1;
    else throw std::invalid_argument("Not a valid integer!");
    return 0;

}

IntegerSet::IntegerSet():set{}{};//// set{} 会把数组所有元素初始化为该类型的默认值（bool 就是 false）
IntegerSet::IntegerSet(const int* a,const int & lenth){
    if (lenth <= 101){
        for (int i = 0; i < lenth;i++){
            if(validEntry(a[i])) set[a[i]] = 1;
        }
    }//数值范围检查，防止数组访问越界；
    else throw std::invalid_argument("too big array, the maximum of array size is 101");

}

IntegerSet IntegerSet::unionOfSets(const IntegerSet& a ,const IntegerSet& b)const{
    IntegerSet result;
    for (int i = 0 ; i <101; i++){
        if (a.set[i]==1||b.set[i]==1) result.set[i]=1;
    }

    return result;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& a ,const IntegerSet& b )const{
    IntegerSet result;
     for (int i = 0 ; i <101; i++){
        if (a.set[i]&&1||b.set[i]==1) result.set[i]=1;
    }

    return result;
}

void IntegerSet::insertElement(int k){
    if (validEntry(k)){
        set[k]=1;
    }

}

void IntegerSet::deleteElement(int k){
    if (validEntry(k)){
        set[k]=0;
    }
}

void IntegerSet::printSet()const{
    using std::cout;
    bool flag = 0;
    for (int i = 0;i<101;i++){
        if (set[i]==1){
            cout<<"i\a";
            flag = 1;
        }
    }
    if (flag == 0){
        cout<<"___";
    }
}

bool IntegerSet::isEqualto(const IntegerSet& other)const{
    bool flag = 1;
    for (int i = 0;i <101; i++){
        if (set[i]!= other.set[i]){
            flag = 0;
            break;
        }
    }
    return flag;
}


