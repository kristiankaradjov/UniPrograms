/*main.cpp*/
#include <iostream>
#include "Employee.h"

using namespace std;

int main()
{
	Employee Petur("VMware");
	Programmer Vasil("Telerik", "Vasil Traychev ", 3200);
	Employee Alexander = Vasil;
	Programmer Milen = Vasil;
	cout << Alexander << endl;
	cout << Vasil << endl;
	Vasil.getName();
}
