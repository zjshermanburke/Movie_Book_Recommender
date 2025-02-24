#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>
#include "Media.h"

class Movie: public Media {
private:
  static constexpr int def_times_consumed = 0;
  static constexpr int def_user_rating = -1;
  static constexpr const char *def_mpa_rating = "N/A";

protected:
  std::string mpa_rating;

public:
  // Constructors
  Movie(std::string title, int times_consumed=def_times_consumed, 
    int user_rating=def_user_rating, std::string mpa_rating=def_mpa_rating);


  // Getters and Setters
  std::string get_mpa_rating() const;
  int get_times_watched() const;
  void set_mpa_rating(std::string mpa_rating);
  void set_times_watched(int times_watched);

  // Custom Methods
  void display() const; // Display movie information
};

#endif // _MOVIE_H_
