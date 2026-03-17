#ifndef TIME_H
#define TIME_H

class Time{
    public:
    explicit Time(int = 0,int = 0 ,int = 0);//default constructor;
    void setTime(int,int,int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    unsigned int getHour()const;
    unsigned int getMinute()const;
    unsigned int getSecond()const;

    void printUniversal() const;
    void printStandard() const;

    void tick();

private:
    unsigned int hour;
    unsigned int minute;
    unsigned int second;


};
#endif