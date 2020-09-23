#include "Platform.h"

Platform::Platform() {
	myMovies = vector<Movie*>();
	mySeries = vector<Serie*>();
	
	ifstream file("streaming_service.csv");
	string line, movieName, length, genre, rating, isMovie, serieName, season, chapter, totalSeasons, totalEpisodes, release, budget;

	int indexMovies = 1, indexSeries = 1;

	while (getline(file, line)) {
		istringstream ss(line);
		getline(ss, isMovie, ',');
		getline(ss, movieName, ',');
		getline(ss, length, ',');
		getline(ss, genre, ',');
		getline(ss, rating, ',');
		getline(ss, serieName, ',');
		getline(ss, season, ',');
		getline(ss, chapter, ',');
		getline(ss, totalSeasons, ',');
		getline(ss, totalEpisodes, ',');
		getline(ss, release, ',');
		getline(ss, budget);

		if (isMovie == "VERDADERO") {
			myMovies.push_back(new Movie(indexMovies, movieName, atoi(length.c_str()), genre, stof(rating), atoi(release.c_str()), atoi(budget.c_str())));
			indexMovies++;
		}
		else {
			mySeries.push_back(new Serie(indexSeries, serieName, atoi(totalSeasons.c_str()), atoi(totalEpisodes.c_str())));
			mySeries[indexSeries - 1]->AddEpisode(1, movieName, atoi(length.c_str()), genre, stof(rating), atoi(season.c_str()), atoi(chapter.c_str()));
			indexSeries++;
		}
	}
	file.close();
}

Platform::~Platform() { }

void Platform::Menu() {
	cout << "WELCOME TO YOUR FAVORITE STREAMING PLATFORM!" << endl;
	cout << "Please enter to..." << endl;
	cout << "A. See all movies availables" << endl;
	cout << "B. Total movies in platform" << endl;
	cout << "C. See all series availables" << endl;
	cout << "D. See all episodes availables of a serie" << endl;
	cout << "E. Total series in platform" << endl;
	cout << "F. See all content" << endl;
	cout << "G. See movies with specific rating" << endl;
	cout << "H. See movies with specific genre" << endl;
	cout << "I. See chapters of serie with specific rating" << endl;
	cout << "J. Rate a movie" << endl;
	cout << "K. Close" << endl;
}

void Platform::SeeAllMovies() {
	for (int i = 0; i < myMovies.size(); i++)
		cout << myMovies[i];
}

void Platform::SeeAllSeries() {
	for (int i = 0; i < mySeries.size(); i++)
		cout << mySeries[i];
}

void Platform::SeeAllContent() {
	SeeAllMovies();
	SeeAllSeries();
}

void Platform::SeeAllEpisodesOfSerie(int id) {
	if (id > mySeries.size() || id <= 0)
		cout << "Index does not exist" << endl;
	else
		mySeries[id - 1]->SeeAllEpisodes();
}

void Platform::SeeMoviesWithSpecificRating(float _r) {
	int index = 0;
	for (int i = 0; i < myMovies.size(); i++) {
		if (myMovies[i]->getRating() == _r) {
			cout << myMovies[i];
			index++;
		}
	}
	cout << "There are " + to_string(index) + " movies with " + to_string(_r) + " rating" << endl;
}

void Platform::SeeMoviesWithSpecificGenre(string _g) {
	int index = 0;
	for (int i = 0; i < myMovies.size(); i++) {
		if (myMovies[i]->getGenre() == _g) {
			cout << myMovies[i];
			index++;
		}
	}
	cout << "There are " + to_string(index) + " movies of " + _g << endl;
}

void Platform::SeeChaptersOfSerieWithSpecificRating(int id, float _r) {
	if (id > mySeries.size() || id <= 0)
		cout << "Index does not exist" << endl;
	else
		mySeries[id - 1]->SeeEpisodesWithSpecifRating(_r);
}

int Platform::GetTotalMovies() { return myMovies.size(); }

int Platform::GetTotalSeries() { return mySeries.size(); }

void Platform::SetRatingMovies(int _id, float _r) {
	float temp = 0.0f;
	cout << "My actual rating is: " + to_string(myMovies[_id-1]->getRating()) << endl;
	temp = *myMovies[_id] + _r;
	cout << "My new rating is: " + to_string(temp) << endl;
}