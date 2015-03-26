/*Employee.h*/
#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <iostream>

class Employee
{
	friend std::ostream & operator << (std::ostream &, const Employee &);
public:
	Employee(char * = "No name of firm ");
	Employee(Employee const &);
	~Employee();

	void setNameFirm(char*);
	const char* getNameFirm()const;

	Employee& operator=(const Employee &);

private:
	char *firm;
};

class Programmer:public Employee
{
	friend std::ostream & operator << (std::ostream &, const Programmer &);
public:
	Programmer(char* = "No name of firm ", char* = "No name ", double = 0.);
	Programmer(Programmer const &);
	~Programmer();

	void setName(char *);
	void setSalary(double);

	const char * getName()const;
	double getSalary()const;

	Programmer& operator=(const Programmer &);
private:
	char *name;
	double salary;
};

std::ostream & operator << (std::ostream &, const Employee &);
std::ostream & operator << (std::ostream &, const Programmer &);

#endif

