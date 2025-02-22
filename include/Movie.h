#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>

class Movie {
private:
  std::string title;
  std::string mpa_rating;
  int times_watched;
  int rating;

public:
  // Constructors
  Movie(std::string title, std::string mpa_rating, int times_watched=1, int rating=3);
  // Copy Constructor
  Movie(const Movie & source);
  // Destructor
  ~Movie();

  /*Operator Overloading*/
  // Copy Assignment
  Movie &operator=(const Movie &rhs);
  // Move Assignment
  Movie &operator=(Movie &&rhs);
  bool operator==(const Movie &rhs) const;
  bool operator<(const Movie &rhs) const;
  bool operator>(const Movie &rhs) const;

  // Getters and Setters
  std::string get_title() const;
  std::string get_mpa_rating() const;
  int get_times_watched() const;
  int get_rating() const;
  void set_title(std::string title);
  void set_mpa_rating(std::string mpa_rating);
  void set_times_watched(int times_watched);
  void set_rating(int rating);

  // Custom Methods
  void increment_watched(); // Increment number of times watched
  void display() const; // Display movie information
};

#endif // _MOVIE_H_
