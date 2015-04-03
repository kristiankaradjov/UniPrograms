#ifndef _TASK_H
#define _TASK_H

#include <iostream>

class Task
{
	friend std::ostream& operator << (std::ostream&, const Task&);
	friend std::istream& operator >> (std::istream&, Task&);
	friend bool operator<(Task const &, Task const &);
public:
	Task(int = 0, char * = "No name", int = 0, int = 0, bool = false);
	Task(const Task &);
	~Task();
	Task& operator = (const Task &);
	char setName(char *);
	bool finished(const Task &);
	int doWork(Task &);
	bool canStart(const Task &);
	bool checkComplete();
private:
	int number;
	char *name;
	int priority;
	int executionTime;
	bool completed;
};

std::ostream& operator << (std::ostream&, const Task&);
std::istream& operator >> (std::istream&, Task&);
bool operator<(Task const &, Task const &);

#endif
