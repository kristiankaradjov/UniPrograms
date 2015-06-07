#ifndef _Bank_H
#define _Bank_H

#include <iostream>
#include <string>

using namespace std;

class Bank
{
	friend std::ostream& operator << (std::ostream&, const Bank&);
	friend std::istream& operator >> (std::istream&, Bank&);
	friend bool operator<(Bank const &, Bank const &);
public:
	Bank(string = " ", string = " ", string = " ", double  = 0., bool = true);
	Bank(const Bank &);
	~Bank();
	void operator += (int);
	double  getBalance()const;
	void  drawFromBalance(double);
	double frozeBankAccount();
	void AddRandomSum();
private:
	string number;
	string name;
	string EGN;
	double balance;
	bool active;
};

std::ostream& operator << (std::ostream&, const Bank&);
std::istream& operator >> (std::istream&, Bank&);
bool operator<(Bank const &, Bank const &);

#endif