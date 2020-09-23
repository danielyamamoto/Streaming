#include <iostream>
#include <vector>
#include <string>
#include "Platform.h"

using namespace std;

int main() {
	char op;
	int indexSerie, indexChapter = 0;
	float rating = 0.0f;
	string genre = "";
	Platform* myPlataform = new Platform();
		
	do {
		myPlataform->Menu();
		cout << "Option: ";
		cin >> op;
		switch (op) {
		case 'A':
		case 'a':
			myPlataform->SeeAllMovies();
			break;
		case 'B':
		case 'b':
			cout << "There are " + to_string(myPlataform->GetTotalMovies()) + " movies" << endl;
			break;
		case 'C':
		case 'c':
			myPlataform->SeeAllSeries();
			break;
		case 'D':
		case 'd':
			cout << "Please, enter the index of the serie: ";
			cin >> indexSerie;
			myPlataform->SeeAllEpisodesOfSerie(indexSerie);
			break;
		case 'E':
		case 'e':
			cout << "There are " + to_string(myPlataform->GetTotalSeries()) + " series" << endl;
			break;
		case 'F':
		case 'f':
			myPlataform->SeeAllContent();
			break;
		case 'G':
		case 'g':
			cout << "Please, enter the rating: ";
			cin >> rating;
			myPlataform->SeeMoviesWithSpecificRating(rating);
			break;
		case 'H':
		case 'h':
			cout << "Please, enter the genre: ";
			cin >> genre;
			myPlataform->SeeMoviesWithSpecificGenre(genre);
			break;
		case 'I':
		case 'i':
			cout << "Please, enter the ID: ";
			cin >> indexSerie;
			cout << "Please, enter the rating: ";
			cin >> rating;
			myPlataform->SeeChaptersOfSerieWithSpecificRating(indexSerie, rating);
			break;
		case 'J':
		case 'j':
			cout << "Please, enter the ID: ";
			cin >> indexSerie;
			cout << "Please, enter the rating: ";
			cin >> rating;
			myPlataform->SetRatingMovies(indexSerie, rating);
			break;
		case 'K':
		case 'k':
			cout << "Closing application..." << endl;
			break;
		default:
			cout << "It is not a valid option" << endl;
			break;
		}
		
		system("PAUSE");
		system("CLS");
	} while (op != 'K' && op != 'k');

	return 0;
}