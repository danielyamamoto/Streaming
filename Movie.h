#pragma once
#include <iostream>
#include <string>
#include "Video.h"

using namespace std;

#ifndef MOVIE
#define MOVIE

class Movie : public Video {
private:
	int release, budget;

public:
	Movie(int _ID, string _name ,int _length, string _genre, float _rating, int _release, int _budget);
	~Movie();
	string toString();

	friend ostream& operator << (ostream& out, Movie* movie);
};

#endif // !MOVIE