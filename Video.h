#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef VIDEO
#define VIDEO

class Video {
private:
	int ID, length;
	float rating;
	string name, genre;

public:
	Video(int _ID, string _name, int _length, string _genre, float _rating);
	~Video();

	virtual string toString() = 0;

	int getID();
	string getName();
	int getLength();
	string getGenre();
	float getRating();
	float operator+(float _r);
};

#endif // !VIDEO