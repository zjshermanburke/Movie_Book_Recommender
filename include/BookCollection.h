#ifndef _BOOKCOLLECTION_H_
#define _BOOKCOLLECTION_H_
#include <string>
#include <vector>
#include "Book.h"
#include "MediaCollection.h"

class BookCollection: public MediaCollection{
private:
  std::vector<Book> *books;
public:
  // Constructor
  BookCollection(std::string name);
  // Copy Constructor
  BookCollection(const BookCollection &source);
  // Destructor
  ~BookCollection();

  // Getters and Setters
  std::vector<Book> get_books() const;

  // Check if book exist in collection, if it doesn't add it
  bool add_book(std::string title, int times_read, int user_rating, 
    std::string isbn, std::string genre, std::string sub_genre, std::string author);
  // If book exists, increment times watched
  bool increment_read(std::string book);
  // Display's Book collection
  virtual void display() const override;
};

#endif // _BOOKCOLLECTION_H_