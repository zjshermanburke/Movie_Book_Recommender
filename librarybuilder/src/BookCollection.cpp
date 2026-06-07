#include <iostream>
#include "BookCollection.h"

// Constructor
BookCollection::BookCollection(const std::string &name)
: MediaCollection{name} {
  books = new std::vector<Book>;
}
// Deep Copy Constructor
BookCollection::BookCollection(const BookCollection &source)
: MediaCollection{source.name}, books{nullptr}{
  books = new std::vector<Book>{*(source.books)};
}
// Copy Assignment Operator
BookCollection &BookCollection::operator=(const BookCollection &source){
  if (this != &source){
    delete books;
    books = new std::vector<Book>{*(source.books)};
    name = source.name;
  }
  return *this;
}
// Move Constructor
BookCollection::BookCollection(BookCollection &&source) noexcept
: MediaCollection{std::move(source.name)}, books{source.books}{
  source.books = nullptr;
}
// Move Assignment Operator
BookCollection &BookCollection::operator=(BookCollection &&source) noexcept{
  if (this != &source){
    delete books;
    books = source.books;
    source.books = nullptr;
    name = std::move(source.name);
  }
  return *this;
}
// Destructor
BookCollection::~BookCollection(){
  delete books;
}

// Getters and Setters
const std::vector<Book>& BookCollection::get_books() const{
  return *books;
}

// Add book to collection
bool BookCollection::add_book(const std::string &title, int times_read, int user_rating, 
  const std::string &isbn, const std::string &genre, const std::string &sub_genre, const std::string &author){
  // If book is in collection, return false
  for (const Book &book : *books){
    if (book.get_title() == title){
      return false;
    }
  }
  // Create temporary book object
  Book temp {title, times_read, user_rating, isbn, genre, sub_genre, author};
  if ((*books).empty()){
    (*books).insert((*books).begin(), temp);
    return true;
  }

  // For loop to place book in collection, in Lexigraphical Order
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

// Increment read time for a given book
bool BookCollection::increment_read(const std::string &title){
    for (Book &book : *books){
        if (book.get_title() == title){
            book.increment_read();
            return true;
        }
    }
    return false;
}

// Display book collection
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