#include <iostream>
#include <string>
#include <stdexcept>
#include "../include/Movie.h"

// Implementation of constructor
Movie::Movie(std::string title, int times_watched, int user_rating, std::string mpa_rating)
: Media{title, times_watched, user_rating}, mpa_rating{mpa_rating}{
}

// Getters
std::string Movie::get_mpa_rating() const {return mpa_rating;}
int Movie::get_times_watched() const {return Media::get_times_consumed();}
// Setters
void Movie::set_mpa_rating(std::string mpa_rating){
  this->mpa_rating = mpa_rating;
}
void Movie::set_times_watched(int times_watched){
  Movie::set_times_consumed(times_watched);
}

// Custom Methods
// Display movie information
void Movie::display() const {
  std::cout << "Title: " << title << "\nMPA Rating: " << mpa_rating << "\nUser Rating: " << user_rating << "\nTimes Watched: " << times_consumed<< '\n' << std::endl;
}
