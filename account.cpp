#include "account.h"
double Account::total1 = 0;
double Account::total2 = 0;
Account::Account(const Date &date, const string &id) :id(id), balance(0)
{
	date.show();
	cout << "\t#" << id << " created" << endl;
}
void Account::record(const Date &date, double amount, const string &desc)
{
	amount = floor(amount * 100 + 0.5) / 100;
	balance += amount;
	//total1+=amount;
	date.show();
	cout << "\t#" << id << "\t" << amount << "\t  " << balance << "\t" << desc << endl;
	string t;
	t = t + myto_string(date.getyear()) + "-" + myto_string(date.getmon()) + "-" + myto_string(date.getday()) + ": ";
	t = t + " #" + id + "    " + myto_string(amount) + "    " + myto_string(balance) + " " + desc;
	rec.push_back(t);
}
void Account::show()const
{
	cout << id << "\tBalance:" << balance << endl;;
	for (int i = 0; i<rec.size(); i++)
	{
		cout << rec[i] << endl;
	}
}
void Account::error(const string &msg)const
{
	cout << "Error(#" << id << "):" << msg << endl;
}

SavingAccount::SavingAccount(const Date &date, const string &id, int index)
:Account(date, id), index(index), acc(date, 0) {
	rate[0] = 0.0;
	rate[1] = 0.35*0.01 / 365.0;
	rate[2] = 1.5*0.01 / 365.0;
	rate[3] = 2.10*0.01 / 365.0;
	rate[4] = 2.75*0.01 / 365.0;
}

void SavingAccount::deposit(const Date&date, double amount, const string &desc)
{
	changetotal1(amount);
	record(date, amount, desc);
	acc.change(date, getbalance());
}
void SavingAccount::withdraw(const Date&date, double amount, const string &desc)
{
	if (amount>getbalance())
	{
		error("not enough money");
	}
	else
	{
		changetotal1(-amount);
		record(date, -amount, desc);
		acc.change(date, getbalance());
	}
}
void SavingAccount::settle(const Date &date)
{
	double interest = acc.getsum(date)*rate[index];
	// cout<<interest<<endl;
	if (interest != 0)
	{
		record(date, interest, "interest");
		changetotal1(interest);
	}
	acc.reset(date, getbalance());
}


CreditAccount::CreditAccount(const Date&date, const string &id, double credit, double rate, double fee)
:Account(date, id), credit(credit), rate(rate), fee(fee), acc(date, 0){}
void CreditAccount::deposit(const Date&date, double amount, const string &desc)
{
	changetotal2(-amount);
	record(date, amount, desc);
	acc.change(date, getDebt());
}
void CreditAccount::withdraw(const Date&date, double amount, const string &desc)
{
	if (amount - getbalance()>credit)
	{
		error("not enough credit");
	}
	else
	{
		changetotal2(amount);
		record(date, -amount, desc);
		acc.change(date, getDebt());
	}
}
void CreditAccount::settle(const Date &date)
{
	double interest = acc.getsum(date)*rate;
	if (interest != 0)
	{
		record(date, interest, "interest");
		changetotal2(interest);
	}
	if (date.getmon() == 1)
	{
		record(date, -fee, "annual fee");
		changetotal2(fee);
	}
	acc.reset(date, getDebt());
}
void CreditAccount::show()const
{
	Account::show();
	cout << "\tAvailable credit:" << getAvailableCredit();
}