#ifndef _BOOKCOLLECTION_H_
#define _BOOKCOLLECTION_H_
#include <string>
#include <vector>
#include "Book.h"

class BookCollection{
private:
  std::vector<Book> *books;
public:
  // Constructor
  BookCollection();
  // Copy Constructor
  BookCollection(const BookCollection &source);
  // Destructor
  ~BookCollection();

  // Check if book exist in collection, if it doesn't add it
  bool add_book(std::string title, int times_read, int user_rating, 
    std::string isbn, std::string genre, std::string sub_genre, std::string author);
  // If book exists, increment times watched
  bool increment_read(std::string book);
  // Display's Book collection
  void display() const;
};

#endif // _BOOKCOLLECTION_H_