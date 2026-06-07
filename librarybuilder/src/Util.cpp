#include <algorithm>
#include <iostream>
#include "Util.h"
// Helper functions
// Helper fucntion to increment the movie watched count
void increment_watched(MovieCollection &movies, const std::string &title){
    if (movies.increment_watched(title)){
        std::cout << title << " times watched incremented" << std::endl;
    } else {
        std::cout << title << " not found" << std::endl;
    }
}
// Helper function to add movie
void add_movie(MovieCollection &movies, const std::string &title, const std::string &mpa_rating, int watched, int rating){
    if (movies.add_movie(title, mpa_rating, watched, rating)){
        std::cout << title << " added to library" << std::endl;
    } else {
        std::cout << title << " is already in library" << std::endl;
    }
}

// Helper fucntion to increment the movie watched count
void increment_read(BookCollection &books, const std::string &title){
    if (books.increment_read(title)){
        std::cout << title << " times read incremented" << std::endl;
    } else {
        std::cout << title << " not found" << std::endl;
    }
}
// Helper function to add movie
void add_book(BookCollection& books, const std::string &title, int times_read, int user_rating, 
    const std::string &isbn13, const std::string &genre, const std::string &sub_genre,
    const std::string &author){
    if (books.add_book(title, times_read, user_rating, isbn13, genre, sub_genre, author)){
        std::cout << title << " added to library" << std::endl;
    } else {
        std::cout << title << " is already in library" << std::endl;
    }
}

void validate_table_name(const std::string &table_name){
    for (char c : table_name){
        if(!std::isalnum(c) && c != '_'){
            throw std::string("Invalid table name");
        }
    }
}

std::string prepare_table_name(const MediaCollection &collection){
    std::string name = collection.get_name();
    std::replace(name.begin(), name.end(), ' ', '_');
    validate_table_name(name);
    return name;
}