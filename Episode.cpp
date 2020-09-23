#include "Episode.h"

Episode::Episode(int _ID, string _name, int _length, string _genre, float _rating, int _season, int _chapter) : Video(_ID, _name, _length, _genre, _rating) {
	season = _season;
	chapter = _chapter;
}

Episode::~Episode() { }

string Episode::toString() { return "I'm a episode"; }

ostream& operator<<(ostream& out, Episode* episode) {
	out << episode->toString() << endl;
	out << "ID: " << episode->getID();
	out << "\tSeason: " << episode->season;
	out << ", Chapter: " << episode->chapter;
	out << ", Title: " << episode->getName();
	out << ", Length: " << episode->getLength();
	out << ", Genre: " << episode->getGenre();
	out << ", Rating: " << episode->getRating();
	return out;
}