//Header.h file

#ifndef _Header_H
#define _Header_H

#include <string>

struct Planet
{
	std::string name;
	int distance;
	double weight;
	double perimeter;
};
int addPlanet(Planet &s);
int setPlanets(Planet &s, std::string n, double d, double w, double p);
int printPlanets(Planet s);
double seconds(Planet s);
int heaviest(Planet *s, int N);
int smallestDiameter(Planet *s, int N);
int distantPlanet(Planet *s, int N);
int sortPlanets(Planet *s, int N);
#endif
