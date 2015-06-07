#include "BankAccount.h"

Bank::Bank(string m_name, string m_number, string m_egn, double m_balance, bool m_active) :name(m_name), number(m_number), EGN(m_egn),
balance(m_balance), active(m_active)
{

};
Bank::Bank(const Bank &r)
{
	name = r.name;
	number = r.number;
	EGN = r.EGN;
	balance = r.balance;
	active = r.active;
};
Bank::~Bank()
{

};
void Bank::operator += (int n)
{
	balance += n;
};
double  Bank::getBalance()const
{
	return balance;
};
void  Bank::drawFromBalance(double n )
{
	balance -= n;
};
double Bank::frozeBankAccount()
{
	double tempBalance = balance;
	balance = 0;
	active = false;
	return tempBalance;
}

ostream&  operator << (ostream& out, const Bank& r)
{
	out << "ID of bank account : " << r.number << endl;
	out << "Name : " << r.name << endl;
	out << "EGN : " << r.EGN << endl;
	out << "Balance: " << r.balance << endl;
	out << "Active : " << boolalpha << r.active << endl;
	return out;
}

istream&  operator >> (istream& in, Bank& r)
{
	
	cout << "Enter ID of bank account" << endl;
	getline(in, r.number);
	cout << "Enter Name" << endl;
	getline(in, r.name);
	cout << "Enter EGN" << endl;
	getline(in, r.EGN);
	cout << "Enter Balance " << endl;
	in >> r.balance;
	cin.ignore();
	return in;
}
void Bank::AddRandomSum()
{
	balance += rand() % 1001 + 100;
};

bool operator < (Bank const& a, Bank const& b)
{
	return a.balance > b.balance;
}