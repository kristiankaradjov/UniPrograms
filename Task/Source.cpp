
#include "Task.h"
#include <cassert>

Task::Task(int num, char *n, int prior, int execution, bool finish)
{
	name = new char[strlen(n) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(n) + 1, n);
	number = num;
	priority = prior;
	executionTime = execution;
	completed = finish;
};

Task::Task(const Task &r)
{
	name = new char[strlen(r.name) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(r.name) + 1, r.name);
	number = r.number;
	priority = r.priority;
	executionTime = r.executionTime;
	completed = r.completed;
};

Task::~Task()
{
	delete[] name;
};

Task& Task::operator=(const Task &r)
{
	if (this != &r)
	{
		delete[] name;
		name = new char[strlen(r.name) + 1];
		assert(name != NULL);
		strcpy_s(name, strlen(r.name) + 1, r.name);
		number = r.number;
		priority = r.priority;
		executionTime = r.executionTime;
		completed = r.completed;
	}
	return *this;
}
char Task::setName(char *n)
{
	name = new char[strlen(n) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(n) + 1, n);
	return *name;
}
bool Task::finished(const Task &r)
{
	if (r.completed == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Task::doWork(Task &r)
{
	r.executionTime++;
	return 0;
}

bool Task::canStart(const Task &r)
{
	if (r.completed == false)
	{
		return true;
	}
	else
	{
		return false;
	}
};

std::ostream& operator << (std::ostream&out, const Task &r)
{
	out << "Number: " << r.number << std::endl;
	out << "Name: " << r.name << std::endl;
	out << "Priority: " << r.priority << std::endl;
	out << "Execution: " << r.executionTime << std::endl;
	out << "Completed: " << std::boolalpha << r.completed << std::endl;
	return out;
};

std::istream& operator >> (std::istream&in, Task&r)
{
	std::cout << "Name: ";
	std::cin.getline(r.name, 256);
	r.setName(r.name);
	std::cout << "Number: ";
	in >> r.number;
	std::cout << "Priority: ";
	in >> r.priority;
	std::cout << "Execution time: ";
	in >> r.executionTime;
	std::cout << "Completed : True or false ";
	in >> std::boolalpha >> r.completed;
	std::cin.ignore(256, '\n');
	return in;
};
bool operator < (Task const & a, Task const & b)
{
	return a.priority < b.priority;
};
