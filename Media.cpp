#include "Media.h"

void Media::setTitle(string t)
{
	title = t;
}

void Media::setLength(double l)
{
	length = l;
}

string Media::getTitle()
{
	return title;
}

double Media::getLength()
{
	return length;
}

Media::Media(string title, double length)
{
	this->title = title;
	this->length = length;
}

Media::Media()
{
	this->title = title;
	this->length = length;
}
