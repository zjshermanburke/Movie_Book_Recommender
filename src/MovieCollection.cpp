#include <iostream>
#include "MovieCollection.h"

// Constructor
MovieCollection::MovieCollection(){
  movies = new std::vector<Movie>;
}
// Deep Copy Constructor
MovieCollection::MovieCollection(const MovieCollection &source)
: movies{nullptr}{
  movies = new std::vector<Movie>{*(source.movies)};
}
// Destructor
MovieCollection::~MovieCollection(){
  delete movies;
}
// Add movie to collection
bool MovieCollection::add_movie(std::string title, std::string mpa_rating, int times_watched, int rating){
  // If movie is in collection, return false
  for (const Movie &movie : *movies){
    if (movie.get_title() == title){
      return false;
    }
  }
  // Create temporary movie object
  Movie temp {title, mpa_rating, times_watched, rating};
  if ((*movies).empty()){
    (*movies).insert((*movies).begin(), temp);
  }
  // For loop to place movie in collection, in Lexigraphical Order
  for (int i = 0; i < (*movies).size(); i++){
    if((*movies).at(0) > temp){
      (*movies).insert((*movies).begin(), temp);
    } else if(temp > (*movies).at(i) && temp < (*movies).at(i+1)){
      (*movies).insert((*movies).begin() + i+1, temp);
    } else if ((*movies).back() < temp){
      (*movies).push_back(temp);
    }
  }
  return true;
}

// Increment watched time for a given movie
bool MovieCollection::increment_watched(std::string title){
    for (Movie &movie : *movies){
        if (movie.get_title() == title){
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

// Display movie collection
void MovieCollection::display() const{
    if ((*movies).size() == 0){
        std::cout << "Sorry, no movies to display\n" << std::endl;
        return;
    }

    std::cout << "\n=======================================" << std::endl;
    for (const auto &movie : *movies){
        movie.display();
    }
    std::cout << "\n=======================================" << std::endl;
}
