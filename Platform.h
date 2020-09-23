#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Movie.h"
#include "Serie.h"

using namespace std;

#ifndef PLATFORM
#define PLATFORM

class Platform {
private:
	vector<Movie*>myMovies;
	vector<Serie*>mySeries;

public:
	Platform();
	~Platform();
	
	void Menu();
	void SeeAllMovies();
	void SeeAllSeries();
	void SeeAllContent();
	void SeeAllEpisodesOfSerie(int id);
	void SeeMoviesWithSpecificRating(float _r);
	void SeeMoviesWithSpecificGenre(string _g);
	void SeeChaptersOfSerieWithSpecificRating(int id, float _r);
	int GetTotalMovies();
	int GetTotalSeries();
	void SetRatingMovies(int _id, float _r);
};

#endif // !PLATFORM