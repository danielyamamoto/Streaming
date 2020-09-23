#pragma once
#include <iostream>
#include <string>
#include "Video.h"

using namespace std;

#ifndef EPISODE
#define EPISODE

class Episode : public Video {
private:
	int season, chapter;

public:
	Episode(int _ID, string _name, int _length, string _genre, float _rating, int _season, int _chapter);
	~Episode();

	string toString();
	friend ostream& operator << (ostream& out, Episode* episode);
};

#endif // !EPISODE