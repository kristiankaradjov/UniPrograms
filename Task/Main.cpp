#include "Task.h"
#include <algorithm>
using namespace std;

int main()
{

	Task D2[10];

	for (int i = 0; i < 10; i++)
	{
		cin >> D2[i];
		cout << " " << endl;
	}

	Task completedTask[5];
	Task UncompletedTask[5];
	int j = 0;
	int k = 0;
	for (int i = 0; i < 10; i++)
	{
		if (D2[i].canStart(D2[i]) == true)
		{
			UncompletedTask[j] = D2[i];
			j++;
		}
		else
		{
			completedTask[k] = D2[i];
			k++;
		}
	}

	sort(completedTask, completedTask + 5);
	cout << "COMPLETED TASKS : " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << completedTask[i] << endl;
		cout << " " << endl;
	}
	cout << " " << endl;
	sort(UncompletedTask, UncompletedTask + 5);

	cout << "UNCOMPLETED TASKS : " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << UncompletedTask[i] << endl;
		cout << " " << endl;
	}

	return 0;
}
