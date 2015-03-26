/*Source.cpp*/
#include <iostream>
#include "Employee.h"
#include <cassert>

Employee::Employee(char * n)
{
	firm = new char[strlen(n) + 1];
	assert(firm != NULL);
	strcpy_s(firm, strlen(n) + 1, n);
}

Employee::Employee(const Employee & e)
{
	firm = new char[strlen(e.firm) + 1];
	assert(firm != NULL);
	strcpy_s(firm, strlen(e.firm) + 1, e.firm);
}

Employee::~Employee()
{
	delete[] firm;
}

void Employee::setNameFirm(char * f)
{
	if (firm != NULL) delete[] firm;
	firm = new char[strlen(f) + 1];
	assert(firm != NULL);
	strcpy_s(firm, strlen(f) + 1, f);
}

const char* Employee::getNameFirm()const
{
	return firm;
}

std::ostream & operator << (std::ostream & out, const Employee & e)
{
	out << "Name of Firm: " << e.firm;
	return out;
}

Employee& Employee::operator=(const Employee& e)
{

	if (this != &e)
	{
		delete[] firm;
		firm = new char[strlen(e.firm)];
		assert(firm != NULL);
		strcpy_s(firm, strlen(e.firm) + 1, e.firm);
	}
	return *this;
}


Programmer::Programmer(char * f, char * n, double s) :Employee(f)
{
	name = new char[strlen(n) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(n) + 1, n);

	salary = s;
}

Programmer::Programmer(const Programmer &p)
{
	name = new char[strlen(p.name) + 1];
	assert(name!= NULL);
	strcpy_s(name, strlen(p.name) + 1, p.name);

	salary = p.salary;
}

Programmer::~Programmer()
{
	delete[] name;
}
void Programmer::setName(char *n)
{
	name = new char[strlen(n) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(n) + 1, n);
}

void Programmer::setSalary(double s)
{
	salary = s;
}

const char *Programmer::getName()const
{
	std::cout << "Hacker, Harry " << name <<std::endl;
	return name ;
}

double Programmer::getSalary()const
{
	return salary;
}

std::ostream & operator << (std::ostream & out, const Programmer & s){

	out << "Name: "<<s.name<<" "<<"Salary : "<<s.salary;
	return out;
}
