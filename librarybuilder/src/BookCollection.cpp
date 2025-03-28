#include <iostream>
#include "../include/BookCollection.h"

// Constructor
BookCollection::BookCollection(std::string name)
: MediaCollection{name} {
  books = new std::vector<Book>;
}
// Deep Copy Constructor
BookCollection::BookCollection(const BookCollection &source)
: MediaCollection{source.name}, books{nullptr}{
  books = new std::vector<Book>{*(source.books)};
}
// Destructor
BookCollection::~BookCollection(){
  delete books;
}

// Getters and Setters
std::vector<Book> BookCollection::get_books() const{
  return *books;
}

// Add movie to collection
bool BookCollection::add_book(std::string title, int times_read, int user_rating, 
  std::string isbn, std::string genre, std::string sub_genre, std::string author){
  // If movie is in collection, return false
  for (const Book &book : *books){
    if (book.get_title() == title){
      return false;
    }
  }
  // Create temporary movie object
  Book temp {title, times_read, user_rating, isbn, genre, sub_genre, author};
  if ((*books).empty()){
    (*books).insert((*books).begin(), temp);
    return true;
  }

  // For loop to place movie in collection, in Lexigraphical Order
  for (int i = 0; i < (*books).size(); i++){
    if(temp < (*books).at(0)){
      (*books).insert((*books).begin(), temp);
      return true;
    } else if(i < (*books).size() - 1 && temp > (*books).at(i) && temp < (*books).at(i+1)){
      (*books).insert((*books).begin() + i+1, temp);
      return true;
    } else if ((*books).back() < temp){
      (*books).push_back(temp);
      return true;
    }
  }
  return false;
}

// Increment watched time for a given movie
bool BookCollection::increment_read(std::string title){
    for (Book &book : *books){
        if (book.get_title() == title){
            book.increment_read();
            return true;
        }
    }
    return false;
}

// Display movie collection
void BookCollection::display() const{
    if ((*books).size() == 0){
        std::cout << "Sorry, no books to display\n" << std::endl;
        return;
    }

    std::cout << "\n=======================================" << std::endl;
    for (const auto &book : *books){
        book.display();
    }
    std::cout << "\n=======================================" << std::endl;
}