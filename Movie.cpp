#include "Movie.h"

Movie::Movie(int _ID, string _name, int _length, string _genre, float _rating, int _release, int _budget) : Video(_ID, _name, _length, _genre, _rating) {
	release = _release;
	budget = _budget;
}

Movie::~Movie() { }

string Movie::toString() { return "I'm a Movie"; }

ostream& operator<<(ostream& out, Movie* movie) {
	out << movie->toString() << endl;
	out << "ID: " << movie->getID(); 
	out << "\tTitle: " << movie->getName();
	out << ", Length: " << movie->getLength() << " minutes";
	out << ", Genre: " << movie->getGenre();
	out << ", Rating: " << movie->getRating();
	out << ", Release: " << movie->release;
	out << ", Budget: " << movie->budget << "MUSD";
	out << "\n\n";
	return out;
}
