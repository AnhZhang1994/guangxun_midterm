#include <iostream>
#include <vector>
#include "date.h"
#include "accumulator.h"
#include "account.h"
using namespace std;
vector<SavingAccount>st;
int main()
{
    Date day1(2016,1,1);
    printf("Choose your deposit method:\n");
    printf("1-Demand deposit\n2-Fixed deposit for one year\n");
    printf("3-Fixed deposit for two years\n");
    printf("4-Fixed deposit for three years\n");
    int n;
    cin>>n;
    SavingAccount a(day1,"1001",n);
    cout<<a.getrate(n)*100*365<<"%"<<endl;
    Date day2(2018,3,5);
    Date day3(2018,4,5);
    a.deposit(day2,1000,"saving 1000 ￥");
    a.withdraw(day3,20,"get 20 ￥");
    Date day8(2019,5,6);
    a.deposit(day8,8000,"salary");
    a.settle(day8);
    printf("This is the Student Credit account\n");
    CreditAccount b(day2,"1006",50000,0.006/365,20);
    Date day4(2019,9,1);
    b.withdraw(day4,5000,"tuition");
    b.getAvailableCredit();
    Date day5(2020,10,5);
    b.withdraw(day5,20000,"buy a cell");
    Date day6(2035,10,9);
    Date day7(2021,10,5);
    b.deposit(day7,1000,"get salary");
    b.settle(day6);
    printf("show the details of student A??\n");
    st.push_back(a);
    a.show();
    printf("Total deposit:\n");
    cout<<a.gettotal1()<<endl;
     printf("Total loans:\n");
     cout<<a.gettotal2()<<endl;
	 system("pause");
    return 0;
}
