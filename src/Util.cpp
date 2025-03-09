#include <iostream>
#include "../include/Util.h"
// Helper functions
// Helper fucntion to increment the movie watched count
void increment_watched(MovieCollection &movies, std::string title){
    if (movies.increment_watched(title)){
        std::cout << title << " times watched incremented" << std::endl;
    } else {
        std::cout << title << " not found" << std::endl;
    }
}
// Helper function to add movie
void add_movie(MovieCollection &movies, std::string title, std::string mpa_rating, int watched, int rating){
    if (movies.add_movie(title, mpa_rating, watched, rating)){
        std::cout << title << " added to library" << std::endl;
    } else {
        std::cout << title << " is already in library" << std::endl;
    }
}

// Helper fucntion to increment the movie watched count
void increment_read(BookCollection &books, std::string title){
    if (books.increment_read(title)){
        std::cout << title << " times read incremented" << std::endl;
    } else {
        std::cout << title << " not found" << std::endl;
    }
}
// Helper function to add movie
void add_book(BookCollection &books, std::string title, int times_read, int user_rating, 
    std::string isbn13, std::string genre, std::string sub_genre,
    std::string author){
    if (books.add_book(title, times_read, user_rating, isbn13, genre, sub_genre, author)){
        std::cout << title << " added to library" << std::endl;
    } else {
        std::cout << title << " is already in library" << std::endl;
    }
}