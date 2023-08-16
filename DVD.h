#pragma once
#include <string>
#include <iostream>
#include "Media.h"
#include "LinkedListDVD.h"
using namespace std;

class DVD : public Media
{
public:
	struct actors
	{
		string name;
		string role;
	};
	LinkedListDVD<actors> dvd;
	void setActors(string name, string role);
	int year;
	void setYear(int y);
	int getYear();
	DVD();
	DVD(string title, double length, int year);
	bool operator == (const DVD& e);
	bool operator != (const DVD& e);
};

