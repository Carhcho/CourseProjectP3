#pragma once
#include <string>
#include <iostream>
using namespace std;

class Media
{
public:
	string title;
	double length = 0.0;
	void setTitle(string t);
	void setLength(double l);
	string getTitle();
	double getLength();
	Media(string title, double length);
	Media();

};

