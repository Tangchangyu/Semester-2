#pragma once

#include<iostream>
#include<stdexcept>
#include<ctime>
#include<string>

class date{
    int year;
    int month;
    int day;

public:
    date(int m=1,int d = 1 ,int y = 2000):year(y),month(m),day(d)
    {
        
    }

    int getMonth()const{
        return month;
    }

    void print()const{
        static const std::string monthNames[]={"January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"};

        std::cout <<monthNames[month - 1]<<" "<<day<<", "<<year<<std::endl;
    }

    static date nowTime() {
        time_t now = time(0);
        struct tm* ptm = localtime(&now);
        int currentMonth = ptm->tm_mon + 1;
        int currentDay = ptm->tm_mday ;

        date NOW (currentMonth,currentDay);
        return NOW;
    }

    bool operator==(const date& other )const{
        if (month == other.month&& day == other.day) return true;
        else return false;
    }


};