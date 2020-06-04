
#ifndef ACCUMULATOR_H_INCLUDED
#define ACCUMULATOR_H_INCLUDED
#include "date.h"
class Accumulator
{
private:
    Date lastDate;
    double value;
    double sum;
public:
    Accumulator(const Date &date1,double value)
        :lastDate(date1),value(value),sum(0) {}

    double getsum(const Date &date)
    {
        return sum+(value*date.distance(lastDate));
    }

    void change(const Date &date,double value)
    {
        sum=getsum(date);
        lastDate = date;
        this->value = value;
        sum=0;
    }
    void reset(const Date &date,double value)
    {
        lastDate=date;
        this->value=value;
        sum=0;
    }
};


#endif
