#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Episode.h"

using namespace std;

#ifndef SERIE
#define SERIE

class Serie {
private:
	vector<Episode*>myEpisodes;
	string nameSerie;
	int idSeason, seasons, totalEpisodes;

public:
	Serie(int _idSeason, string _nameSerie, int _totalSeasons, int _totalEpisodes);
	~Serie();

	string toString();
	void AddEpisode(int _ID, string _nameChapter, int _length, string _genre, float _rating, int _season, int _chapter);
	void SeeAllEpisodes();
	void SeeEpisodesWithSpecifRating(float _r);
	float GetRatingOfEpisode(int _c);
	friend ostream& operator << (ostream& out, Serie* serie);
};

#endif // !SERIE