#ifndef _UTIL_H_
#define _UTIL_H_
#include <string>
#include "MovieCollection.h"
#include "BookCollection.h"
// Function prototypes
void increment_watched(MovieCollection &movies, const std::string &title);
void add_movie(MovieCollection &movie, const std::string &name, const std::string &mpa_rating, int watched, int rating);

void increment_read(BookCollection &books, const std::string &title);
void add_book(BookCollection &books, const std::string &title, int times_read, int user_rating, 
    const std::string &isbn, const std::string &genre, const std::string &sub_genre, const std::string &author);

void validate_table_name(const std::string &table_name);
std::string prepare_table_name(const MediaCollection &collection);

#endif // _UTIL_H_