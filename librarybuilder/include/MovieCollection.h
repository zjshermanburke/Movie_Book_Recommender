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
  MovieCollection(const std::string &name);
  // Deep Copy Constructor
  MovieCollection(const MovieCollection &source);
  // Copy Assignment Operator
  MovieCollection &operator=(const MovieCollection &source);
  // Move Constructor
  MovieCollection(MovieCollection &&source) noexcept;
  // Move Assignment Operator
  MovieCollection &operator=(MovieCollection &&source) noexcept;
  // Destructor
  ~MovieCollection();

  // Getters and Setters
  const std::vector<Movie> &get_movies() const;

  // Check if movie exist in collection, if it doesn't add it
  bool add_movie(const std::string &title, const std::string &mpa_rating, int times_watched, int rating);
  // If movie exists, increment times watched
  bool increment_watched(const std::string &movie);
  // Display's Movie collection
  virtual void display() const override;
}; 

#endif // _MOVIECOLLECTION_H_
