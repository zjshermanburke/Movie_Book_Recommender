#include <iostream>
#include <string>
#include <stdexcept>
#include "Movie.h"

// Implementation of constructor
Movie::Movie(std::string title, std::string mpa_rating, int times_watched, int rating)
: title{title}, mpa_rating{mpa_rating}, times_watched{times_watched}, rating{rating}{
  if (rating > 5 || rating < 0){
    throw std::invalid_argument("Value must be between 0 and 5");
  }
  if (times_watched < 0){
    throw std::invalid_argument("Value must be greater than 0");
  }
}

// Implementation of copy constructor
Movie::Movie(const Movie &source)
: Movie{source.title, source.mpa_rating, source.times_watched, source.rating}{
}

// Implementation of Destructor
Movie::~Movie(){
}

/* Operator Overloading */

// Copy Assignment
Movie &Movie::operator=(const Movie &rhs){
  if (this == &rhs){
    return *this;
  }
  this->title = rhs.title;
  this->mpa_rating = rhs.mpa_rating;
  this->times_watched = rhs.times_watched;
  this->rating = rhs.rating;

  return *this;
}
// Move Assignment
Movie &Movie::operator=(Movie &&rhs){
  if (this == &rhs){
      return *this;
    }
  this->title = rhs.title;
  this->mpa_rating = rhs.mpa_rating;
  this->times_watched = rhs.times_watched;
  this->rating = rhs.rating;
  return *this;
  }
// Equality Operator
bool Movie::operator==(const Movie &rhs) const{
  return (title == rhs.title);
}
// Less than Operator
bool Movie::operator<(const Movie &rhs) const{
  return (title < rhs.title);
}
// Greater than Operator
bool Movie::operator>(const Movie &rhs) const{
  return (title > rhs.title);
}

// Getters
std::string Movie::get_title() const {return title;}
std::string Movie::get_mpa_rating() const {return mpa_rating;}
int Movie::get_times_watched() const {return times_watched;}
int Movie::get_rating() const {return rating;}

// Setters
void Movie::set_title(std::string title){
  this->title = title;
}
void Movie::set_mpa_rating(std::string mpa_rating){
  this->mpa_rating = mpa_rating;
}
void Movie::set_times_watched(int times_watched){
  this->times_watched = times_watched;
}
void Movie::set_rating(int rating){
  this->rating = rating;
}

// Custom Methods
// Increase number of times watched
void Movie::increment_watched(){times_watched++;}
// Display movie information
void Movie::display() const {
  std::cout << "Title: " << title << "\nMPA Rating: " << mpa_rating << "\nUser Rating: " << rating << "\nTimes Watched: " << times_watched << '\n' << std::endl;
}
