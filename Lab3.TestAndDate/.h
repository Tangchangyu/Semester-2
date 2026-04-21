#pragma once
class Date{
    private:
    short year;
    short month;
    short day;
    public:
    Date(short = 2014,short =1 ,short = 1);
    Date setDate(Date);
    void check();
    void print()const;
};

class FinalTest{
    private:
    char name[100];
    Date date;
    
    public:
    void setDue(const Date&);
    void print() const;
    FinalTest(const char*,const Date&);
    FinalTest(const char*);
};
