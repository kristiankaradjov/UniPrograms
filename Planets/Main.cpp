//main.cpp

#include "Header.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Planet *planets;
	int N;
	cout << "Enter number of planets " << endl;
	cin >> N;
	planets = new Planet[N];
	int choice;
	do
	{
		cout <<" "<< endl;
		cout << "Choose action : \n" <<
			"1- Enter planet's data  \n" <<
			"2- Print the seconds for which the sunlights touches the planets  \n" <<
			"3- Print the heaviest planet \n" <<
			"4- Print the planet with smallest diameter \n" <<
			"5- The most distant from the sun planet \n" <<
			"6- Full list of planets \n" <<
			"7- List of the planets sorted by distance from the sun \n" <<
			"0- End of the program";
		cout << " " << endl;
		cin >> choice;
		cout << " " << endl;
		switch (choice)
		{

		case 1: for (int i = 0; i < N; i++)
		{
				   addPlanet(planets[i]);
				   cout << " " << endl;
		}
			   break;

		case 2:for (int i = 0; i < N; i++)
		{
				   cout << " " << endl;
				   printPlanets(planets[i]);
				   cout << "Seconds for the sunlight to reach the planet : " << seconds(planets[i]) << endl;
		}
			   break;
		case 3: heaviest(planets, N);
			   break;
		case 4:smallestDiameter(planets, N);

			   break;
		case 5:distantPlanet(planets, N);

			   break;
		case 6:for (int i = 0; i <N; i++)
		{
				   printPlanets(planets[i]);
				   cout << " " << endl;
		}
			   break;
		case 7:sortPlanets(planets, N);
			for (int i = 0; i <N; i++)
			{
				printPlanets(planets[i]);
				cout << " " << endl;
			}
			   break;
		default:
			break;
		}
		cout << " " << endl;
	} while (choice != 0);
         delete []planets;
	return 0;
}
