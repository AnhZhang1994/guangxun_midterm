
#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Date{
private:
    int year,month,day;
    int totaldays;
public:
    Date(int y,int m,int d);
    int getyear()const
    {
        return year;
    }
    int getmon()const {return month;}
    int getday()const {return day;}
    int getmaxday()const;
    bool isleapyear()const
    {
        return (year%4==0&&year%100!=0)||(year%400==0);
    }
    void show()const;
    int distance(const Date &date)const
    {
        return abs(totaldays-date.totaldays);
    }
};

#endif 
