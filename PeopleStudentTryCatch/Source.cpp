#include <iostream>
#include "Header.h"
#include <cassert>
#include <string>
People::People(char * n, char * e){
	name = new char[strlen(n) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(n) + 1, n);

	egn = new char[strlen(e) + 1];
	assert(egn != NULL);
	strcpy_s(egn, strlen(e) + 1, e);
}

People::People(const People & p){
	name = new char[strlen(p.name) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(p.name) + 1, p.name);

	egn = new char[strlen(p.egn) + 1];
	assert(egn != NULL);
	strcpy_s(egn, strlen(p.egn) + 1, p.egn);
}

People::~People(){
	delete[] egn;
	delete[] name;
}

void People::read()
{
	char nameTemp [256] ;
	char egnTemp[256];
	std::cout << "Enter name : ";
	std::cin.getline(nameTemp,256);
	name = new char[strlen(nameTemp) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(nameTemp) + 1, nameTemp);
	std::cout << "Enter EGN : ";
	std::cin.getline(egnTemp, 256);
	egn = new char[strlen(egnTemp) + 1];
	assert(egn != NULL);
	strcpy_s(egn, strlen(egnTemp) + 1, egnTemp);
}
void People::set_name(char * n){
	if (name != NULL) delete[] name;
	name = new char[strlen(n) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(n) + 1, n);
}

void People::set_egn(char * e){
	if (egn != NULL) delete[] egn;
	egn = new char[strlen(e) + 1];
	assert(egn != NULL);
	strcpy_s(egn, strlen(e) + 1, e);

}

char * People::get_name() const{
	return name;
}

char * People::get_egn() const{
	return egn;
}

void People::print() const{
	std::cout << "Name: " << name << std::endl;
	std::cout << "EGN: " << egn << std::endl;
}

std::ostream & operator << (std::ostream & out, const People & p){
	out << "Name: " << p.name << " EGN: " << p.egn << std::endl;
	return out;
}

std::istream & operator >> (std::istream & in, People & p){
	in >> p.name >> p.egn;
	return in;
}


Student::Student(char * n, char * e, char * f, double g) :People(n, e){
	fnum = new char[strlen(f) + 1];
	assert(fnum != NULL);
	strcpy_s(fnum, strlen(f) + 1, f);

	if (g >= 2 && g <= 6) grade = g;
	else if (g < 2) grade = 2;
	else grade = 6;
}

Student::Student(const Student & s) :People(s){
	std::cout << "Student(const & )\n";
	fnum = new char[strlen(s.fnum) + 1];
	assert(fnum != NULL);
	strcpy_s(fnum, strlen(s.fnum) + 1, s.fnum);

	grade = s.grade;
}

Student::~Student(){
	delete[] fnum;
}

void Student::set_fnum(char * f){
	if (fnum != NULL) delete[] fnum;
	fnum = new char[strlen(f) + 1];
	assert(fnum != NULL);
	strcpy_s(fnum, strlen(f) + 1, f);

}

void Student::set_grade(double g){
	if (g >= 2 && g <= 6) grade = g;
	else if (g < 2) grade = 2;
	else grade = 6;

}

void Student::read()
{
	People::read();
	char tempFnum[256];
	std::cout << "Enter Faculty number :";
	std::cin.getline(tempFnum, 256);
	fnum = new char[strlen(tempFnum) + 1];
	assert(fnum != NULL);
	strcpy_s(fnum, strlen(tempFnum) + 1, tempFnum);
	std::cout << "Enter grade :";
	std::cin >> grade;
	if (grade < 2 || grade > 6)
	{
		throw std::logic_error("Wrong value of the grade");
	}
	std::cin.ignore(256, '\n');
	
}
char * Student::get_name() const{

	return People::get_name();
}

char * Student::get_egn() const{
	return People::get_egn();
}

char * Student::get_fnum() const{
	return fnum;

}

double Student::get_grade() const{
	return grade;

}

void Student::print() const{
	People::print();
	std::cout << "Faculty number: " << fnum << std::endl;
	std::cout << "Grade: " << grade << std::endl;
}

std::ostream & operator << (std::ostream & out, const Student & s){
	out << "Name: " << s.get_name() << " EGN: " << s.get_egn() << std::endl
		<< " Faculty number: " << s.fnum << " Grade: " << s.grade << std::endl;
	return out;
}

std::istream & operator >> (std::istream & in, Student & s){
	in >> s.get_name() >> s.get_egn() >> s.fnum >> s.grade;
	return in;
}

void BestStudent()
{
	const int studentsNum = 3;
	
	Student all[studentsNum];
	int i = 0;
	int testTry = 0;
	while (i < studentsNum)
	{
		try
		{
			all[i].read();
			i++;
		}
		catch (std::logic_error &e)
		{
			std::cout << "Logic error has occured: " << e.what();
			std::cout << "Do you want to try again ? y/n ";
			std::string input;
			std::cin >> input;
			std::cin.ignore(256, '\n');
			if (input == "y")
			{
				all[i].read();
			}
			i++;
		}
	}
	double bestGrade = all[0].get_grade();
	int position = 0;
	for (int i = 1; i < 3; i++)
	{
		if(all[i].get_grade() > bestGrade)
			{
				bestGrade = all[i].get_grade();
				position = i;
			}
	}
	std::cout << "Best student is : " << all[position].get_name() <<"  with grade "<<all[position].get_grade()<<std::endl;
}