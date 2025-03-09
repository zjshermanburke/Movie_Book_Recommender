#include <iostream>
#include <string>
#include <stdexcept>
#include "../include/Book.h"

// Implementation of constructor
Book::Book(std::string title, int times_read, int user_rating, 
  std::string isbn, std::string genre, std::string sub_genre, std::string author)
: Media{title, times_read, user_rating}, isbn13{isbn}, genre{genre}, sub_genre{sub_genre}, author{author}{
}

// Getters
int Book::get_times_read() const {return Media::get_times_consumed();}
std::string Book::get_isbn() const {return isbn13;}
std::string Book::get_genre() const {return genre;}
std::string Book::get_sub_genre() const {return sub_genre;}
std::string Book::get_author() const {return author;}
// Setters
void Book::set_times_read(int times_read){
  Media::set_times_consumed(times_read);
}
void Book::set_isbn(std::string isbn){
  this->isbn13 = isbn;
}
void Book::set_genre(std::string genre){
  this->genre = genre;
}
void Book::set_sub_genre(std::string sub_genre){
  this->genre = genre;
}
void Book::set_author(std::string author){
  this->author = author;
}

// Custom Methods
// Display movie information
void Book::display() const {
  std::cout << "Title: " << title << "\nAuthor: " << author <<
  "\nGenre: " << genre << "\nSubgenre: " << sub_genre <<
  "\nUser Rating: " << user_rating << "\nTimes Watched: " << times_consumed <<
  "\nISBN: " << isbn13  << '\n' << std::endl;
}