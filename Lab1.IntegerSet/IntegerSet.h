#pragma once

class IntegerSet{
    private:
    bool set [101]={0};//为什么要在构造函数初始化？

public:
    IntegerSet();//初始化列表会将所有元素初始化为默认值，bool———false;
    IntegerSet(const int *, const int &);

    IntegerSet unionOfSets(const IntegerSet&,const IntegerSet&)const;
    IntegerSet intersectionOfSets(const IntegerSet&,const IntegerSet&)const;
    void insertElement(int k);
    void deleteElement(int k);
    void printSet()const;
    bool isEqualto(const IntegerSet&)const;

    void inputSet();
    
};