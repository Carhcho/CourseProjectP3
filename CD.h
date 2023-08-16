#pragma once
#include <string>
#include <iostream>
#include "Media.h"
#include "LinkedList.h"
using namespace std;

class CD : public Media
{
public:
	struct song {
		string title;
		double length = 0.0;
	};
	LinkedList<song> disc;
	void setSong(string title, double length);
	string artist;
	void setArtist(string a);
	string getArtist();
	CD();
	CD(string title, double length, string artist);
	bool operator == (const CD& e);
	bool operator != (const CD& e);
};