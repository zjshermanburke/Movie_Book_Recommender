#ifndef _MOVIECOLLECTION_H_
#define _MOVIECOLLECTION_H_
#include <string>
#include <vector>
#include "Movie.h"

class MovieCollection{
private:
  std::vector<Movie> *movies;
public:
  // Constructor
  MovieCollection();
  // Copy Constructor
  MovieCollection(const MovieCollection &source);
  // Destructor
  ~MovieCollection();

  // Check if movie exist in collection, if it doesn't add it
  bool add_movie(std::string title, std::string mpa_rating, int times_watched, int rating);
  // If movie exists, increment times watched
  bool increment_watched(std::string movie);
  // Display's Movie collection
  void display() const;
}; 

#endif // _MOVIECOLLECTION_H_
