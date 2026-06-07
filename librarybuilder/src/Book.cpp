#include <iostream>
#include <string>
#include <stdexcept>
#include "Book.h"

// Implementation of constructor
Book::Book(const std::string &title, int times_read, int user_rating, 
  const std::string &isbn, const std::string &genre, const std::string &sub_genre, const std::string &author)
: Media{title, times_read, user_rating}, isbn13{isbn}, genre{genre}, sub_genre{sub_genre}, author{author}{
}

// Getters
int Book::get_times_read() const {return Media::get_times_consumed();}
const std::string &Book::get_isbn() const {return isbn13;}
const std::string &Book::get_genre() const {return genre;}
const std::string &Book::get_sub_genre() const {return sub_genre;}
const std::string &Book::get_author() const {return author;}
// Setters
void Book::set_times_read(int times_read){
  Media::set_times_consumed(times_read);
}
void Book::set_isbn(const std::string &isbn){
  this->isbn13 = isbn;
}
void Book::set_genre(const std::string &genre){
  this->genre = genre;
}
void Book::set_sub_genre(const std::string &sub_genre){
  this->sub_genre = sub_genre;
}
void Book::set_author(const std::string &author){
  this->author = author;
}

// Custom Methods
// Display book information
void Book::display() const {
  std::cout << "Title: " << title << "\nAuthor: " << author <<
  "\nGenre: " << genre << "\nSubgenre: " << sub_genre <<
  "\nUser Rating: " << user_rating << "\nTimes Read: " << times_consumed <<
  "\nISBN: " << isbn13  << '\n' << std::endl;
}