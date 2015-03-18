/planet.cpp

#include "Header.h"
#include <iostream>

int addPlanet(Planet &s)
{
	std::cout << "Enter planet's name : ";
	std::cin >> s.name;
	std::cout << "Enter the weight of the planet : ";
	std::cin >> s.weight;
	std::cout << "Enter the diameter of the planet : ";
	std::cin >> s.perimeter;
	std::cout << "Planet's distance from the sun : ";
	std::cin >> s.distance;

	return 0;
}

int setPlanets(Planet &s, std::string n, int d, double w, double p)
{
	s.name = n;
	s.distance = d;
	s.weight = w;
	s.perimeter = p;
	return 0;
}

int printPlanets(Planet s)
{
	std::cout << "Planet's name : " << s.name <<std::endl;
	std::cout << "Planet's distance from sun : " << s.distance << std::endl;
	std::cout << "Planet's weight : " << s.weight << std::endl;
	std::cout << "Planet's diemeter : " << s.perimeter << std::endl;	
	return 0;
}

double seconds(Planet s)
{
	double secondsFromSun = s.distance / 299792;
	return secondsFromSun;
}

int heaviest(Planet *s, int N)
{
	double heavy =  s[0].weight;
	int position = 0;
	for (int i = 1; i < N; i++)
	{
		if (s[i].weight>heavy)
		{
			heavy = s[i].weight;
			position = i;
		}
	}
	printPlanets(s[position]);
	return 0;
}

int smallestDiameter(Planet *s, int N)
{
	double perimeter = s[0].perimeter;
	int position = 0;
	for (int i = 1; i < N; i++)
	{
		if (s[i].perimeter<perimeter)
		{
			perimeter = s[i].perimeter;
			position = i;
		}
	}
	printPlanets(s[position]);
	return 0;
}

int distantPlanet(Planet *s, int N)
{
	int distance = s[0].distance;
	int position = 0;
	for (int i = 0; i < N; i++)
	{
		if (s[i].distance > distance)
		{
			distance = s[i].distance;
			position = i;
		}
	}
	printPlanets(s[position]);
	return 0;
}

int sortPlanets(Planet *s, int N)
{
	Planet temporary;
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (s[j-1].distance > s[j].distance)
			{
				temporary = s[j - 1];
				s[j - 1] = s[j];
				s[j] = temporary;
			}
		}
	}
	return 0;
}