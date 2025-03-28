#ifndef _UTIL_H_
#define _UTIL_H_
#include <string>
#include "MovieCollection.h"
#include "BookCollection.h"
// Function prototypes
void increment_watched(MovieCollection &movies, std::string title);
void add_movie(MovieCollection &movie, std::string name, std::string mpa_rating, int watched, int rating);

void increment_read(BookCollection &books, std::string title);
void add_book(BookCollection &books, std::string title, int times_read, int user_rating, 
    std::string isbn, std::string genre, std::string sub_genre, std::string author);

#endif // _UTIL_H_