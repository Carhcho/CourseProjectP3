#include "CD.h"
#include "LinkedList.h"
using namespace std;

void CD::setSong(string title, double length)
{
	song cancion = { title, length };
	disc.appendNode(cancion);
}

void CD::setArtist(string a)
{
	artist = a;
}

string CD::getArtist()
{
	return artist;
}

CD::CD()
{
	
}

CD::CD(string title, double length, string artist)
{
	this->title = title;
	this->length = length;
	this->artist = artist;
}

bool CD::operator==(const CD& e)
{
	return true;
}

bool CD::operator!=(const CD& e)
{
	return false;
}
