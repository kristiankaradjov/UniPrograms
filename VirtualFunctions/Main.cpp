#include "People.h"
#include <windows.h>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(0, "Bulgarian");
	SetConsoleOutputCP(866);

	People * arrPeople[3];
	arrPeople[0] = new People("Иван Иванов", "8904123648");
	arrPeople[1] = new Student("Мария Георгиева", "9206066055", "F32324", 5.45);
	arrPeople[2] = new Student("Станимир Лалов", "9311123040", "F121234", 4.34);
	for (int i = 0; i < 3; i++)
	{
		cout << "Име: " << arrPeople[i]->get_name() << " ЕГН: " << arrPeople[i]->get_egn() << endl;

		arrPeople[i]->print();
	}
	return 0;
}
