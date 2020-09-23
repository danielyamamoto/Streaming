#include "Serie.h"

Serie::Serie(int _idSeason, string _nameSerie, int _totalSeasons, int _totalEpisodes) {
	idSeason = _idSeason;
	nameSerie = _nameSerie;
	seasons = _totalSeasons;
	totalEpisodes = _totalEpisodes;
}

Serie::~Serie() { }

string Serie::toString() { return "I'm a serie!"; }

void Serie::AddEpisode(int _ID, string _nameChapter, int _length, string _genre, float _rating, int _season, int _chapter) {
	myEpisodes.push_back(new Episode(_ID, _nameChapter, _length, _genre, _rating, _season, _chapter));
}

void Serie::SeeAllEpisodes() {
	cout << "Serie: " + nameSerie + ", Total episodes in platform: " + to_string(myEpisodes.size()) << endl;
	for (int i = 0; i < myEpisodes.size(); i++) {
		cout << myEpisodes[i];
		cout << "\n";
	}
}

void Serie::SeeEpisodesWithSpecifRating(float _r) {
	int index = 0;
	cout << "Serie: " + nameSerie << endl;
	for (int i = 0; i < myEpisodes.size(); i++) {
		if (myEpisodes[i]->getRating() == _r) {
			cout << myEpisodes[i];
			index++;
		}
	}
	cout << "There are " + to_string(index) + " chapters with " + to_string(_r) + " rating" << endl;
}

float Serie::GetRatingOfEpisode(int _c) {
	return myEpisodes[_c]->getRating();
}

ostream& operator<<(ostream& out, Serie* serie) {
	out << serie->toString() << endl;
	out << "ID: " << serie->idSeason;
	out << "\tSerie: " << serie->nameSerie;
	out << ", Seasons: " << serie->seasons;
	out << ", Total Episodes: " << serie->totalEpisodes;
	out << "\n\n";
	return out;
}
