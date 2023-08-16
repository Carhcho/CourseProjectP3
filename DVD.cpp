#include "DVD.h"
#include "LinkedListDVD.h"

void DVD::setActors(string name, string role)
{
	actors actor = { name, role };
	dvd.appendNode(actor);
}

void DVD::setYear(int y)
{
	year = y;
}

int DVD::getYear()
{
	return year;
}

DVD::DVD()
{
}

DVD::DVD(string title, double length, int year)
{
	this->title = title;
	this->length = length;
	this->year = year;
}

bool DVD::operator==(const DVD& e)
{
	return true;
}

bool DVD::operator!=(const DVD& e)
{
	return false;
}
