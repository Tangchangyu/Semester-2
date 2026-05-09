#include<iostream>
#include<stdexcept>
#include<ctime>

class date{
    
    int month;
    int day;

public:
    date(int m=1,int d = 1 ):month(m),day(d)
    {
        
    }

    int getMonth()const{
        return month;
    }

    date nowTime() const{
        time_t now = time(0);
        struct tm* ptm = localtime(&now);
        int currentMonth = ptm->tm_mon + 1;
        int currentDay = ptm->tm_mday ;

        date NOW (currentMonth,currentDay);
        return NOW;
    }
};