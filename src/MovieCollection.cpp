#include <iostream>
#include "../include/MovieCollection.h"

// Constructor
MovieCollection::MovieCollection(std::string name){
  this->name = name;
  movies = new std::vector<Movie>;
}
// Deep Copy Constructor
MovieCollection::MovieCollection(const MovieCollection &source)
: movies{nullptr}, name{source.name}{
  movies = new std::vector<Movie>{*(source.movies)};
}
// Destructor
MovieCollection::~MovieCollection(){
  delete movies;
}

// Getters and Setters
std::vector<Movie> MovieCollection::get_movies() const{
  return *movies;
}
std::string MovieCollection::get_name() const{
  return this->name;
}
void MovieCollection::set_name(std::string name){
  this->name = name;
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
  Movie temp {title, times_watched, rating, mpa_rating};
  if ((*movies).empty()){
    (*movies).insert((*movies).begin(), temp);
    return true;
  }
  // For loop to place movie in collection, in Lexigraphical Order
  for (int i = 0; i < (*movies).size(); i++){
    if(temp < (*movies).at(0)){
      (*movies).insert((*movies).begin(), temp);
      return true;
    } else if(i < (*movies).size() - 1 && temp > (*movies).at(i) && temp < (*movies).at(i+1)){
      (*movies).insert((*movies).begin() + i+1, temp);
      return true;
    } else if ((*movies).back() < temp){
      (*movies).push_back(temp);
      return true;
    }
  }
  return false;
}

// Increment watched time for a given movie
bool MovieCollection::increment_watched(std::string title){
    for (Movie &movie : *movies){
        if (movie.get_title() == title){
            movie.increment_times_consumed();
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
