
#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include "date.h"
#include "accumulator.h"
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
static string myto_string(int x)
{
    string s;
    if(x == 0) s += '0';
    while(x)
    {
         s += (x%10)+'0';
         x /= 10;
    }
    reverse(s.begin(),s.end());
    return s;
}

class Account
{
private:
    string id;
    double balance;
    static double total1,total2;
    vector<string>rec;
protected:
    Account(const Date &date,const string &id);
    void record(const Date &date,double amount,const string &desc);
    void error(const string &msg)const;
public:
    const string &getid()
    {
        return id;
    }
    void changetotal1(double amount)
    {
        total1+=amount;
    }
    void changetotal2(double amount)
    {
        total2+=amount;
    }
    double getbalance()const
    {
        return balance;
    }
    static double gettotal1()
    {
        return total1;
    }
    static double gettotal2()
    {
        return total2;
    }
    void show()const;
};
class SavingAccount:public Account
{
private:
    Accumulator acc;
    double rate[5];
    int index;

public:
    SavingAccount(const Date&date,const string &id,int index);
    double getrate(int i)
    {
        return rate[i];
    }
    void changerate(double rate1,int i)
    {
        rate[i]=rate1;
    }
    void changekind(int i)
    {
        index=i;
    }
    void deposit(const Date &date,double amount,const string &desc);
    void withdraw(const Date&date,double amount,const string &desc);
    void settle(const Date &date);
};

class CreditAccount:public Account
{
private:
    Accumulator acc;
    double credit;
    double rate;
    double fee;
    double getDebt()const
    {
        double balance=getbalance();
        return (balance<0?balance:0);
    }
public:
    CreditAccount(const Date&date,const string &id,double credit,double rate,double fee);
    double getcredit()const
    {
        return credit;
    }
    double getrate()const
    {
        return rate;
    }
    double getfee()const
    {
        return fee;
    }
    double getAvailableCredit()const
    {
        if(getbalance()<0)
        {
            return credit+getbalance();
        }
        else return credit;
    }
    void deposit(const Date &date,double amount,const string &desc);
    void withdraw(const Date &date,double amount,const string &desc);
    void settle(const Date &date);
    void show()const;
};

#endif
