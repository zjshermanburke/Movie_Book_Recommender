#ifndef _MOVIECOLLECTION_H_
#define _MOVIECOLLECTION_H_
#include <string>
#include <vector>
#include "Movie.h"
#include "MediaCollection.h"

class MovieCollection: public MediaCollection{
private:
  std::vector<Movie> *movies;
public:
  // Constructor
  MovieCollection(std::string name);
  // Copy Constructor
  MovieCollection(const MovieCollection &source);
  // Destructor
  ~MovieCollection();

  // Getters and Setters
  std::vector<Movie> get_movies() const;

  // Check if movie exist in collection, if it doesn't add it
  bool add_movie(std::string title, std::string mpa_rating, int times_watched, int rating);
  // If movie exists, increment times watched
  bool increment_watched(std::string movie);
  // Display's Movie collection
  virtual void display() const override;
}; 

#endif // _MOVIECOLLECTION_H_
