#include "Video.h"

Video::Video(int _ID, string _name, int _length, string _genre, float _rating) {
	ID = _ID;
	name = _name;
	length = _length;
	genre = _genre;
	rating = _rating;
}

Video::~Video() { }

int Video::getID() { return ID; }

string Video::getName() { return name; }

int Video::getLength() { return length; }

string Video::getGenre() { return genre; }

float Video::getRating() { return rating; }

float Video::operator+(float _r) {
	this->rating = (rating + _r) / 2;
	return rating;
}