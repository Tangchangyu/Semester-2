#include "time.h"
#include<iostream>
#include <iomanip>
#include <stdexcept>

Time::Time(int hour,int minute ,int second)
{
    setTime(hour ,minute ,second);
}

void Time::setTime(int h,int min,int s){
    setHour(h);
    setMinute(min);
    setSecond(s);

}

void Time::setHour(int h){
    if(0<=h && 24>h){
            hour = h;
    }
    else 
        throw std::invalid_argument("hour must be 0-23");

}

void Time::setMinute(int min){
    if (min>=0 && min<60)
        minute=min;
    else throw std::invalid_argument("minuet must be 0-59");

}

void Time::setSecond(int s){
    if (s>=0 && s<60)
        second = s;
    else throw std::invalid_argument("second must be 0-59");
};

unsigned int Time::getHour() const{
    return hour;
}

unsigned int Time::getMinute() const{
    return minute;
}

unsigned int Time::getSecond() const{
    return second;
}

void Time::printUniversal() const{
    std::cout<<std::setfill('0') <<std::setw(2) <<getHour() <<":" <<std::setw(2) <<getMinute()<<":"<<std::setw(2)<<getSecond();

}

void Time::printStandard() const{
    using namespace std;
    cout<<((getHour()==0||getHour()==12)?12:getHour()%12);//天才来的吧！！！
    cout<<":"<<setfill('0')<<setw(2)<<getMinute()<<":"<<setw(2)<<getSecond()<<(hour<12?"AM":"PM");

}

void Time::tick(){
    if (second!=59){
        second++;
    }
    else {
        second = 0;
        if(minute!=59) minute++;
        else{
            minute=0;
            if (hour!=23) hour++;
            else hour = 0;
            }
        }
    }

