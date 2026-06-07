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
  BookCollection(const std::string &name);
  // Deep Copy Constructor
  BookCollection(const BookCollection &source);
  // Copy Assignment Operator
  BookCollection &operator=(const BookCollection &source);
  // Move Constructor
  BookCollection(BookCollection &&source) noexcept;
  // Move Assignment Operator
  BookCollection &operator=(BookCollection &&source) noexcept;
  // Destructor
  ~BookCollection();

  // Getters and Setters
  const std::vector<Book> &get_books() const;

  // Check if book exist in collection, if it doesn't add it
  bool add_book(const std::string &title, int times_read, int user_rating, 
    const std::string &isbn, const std::string &genre, const std::string &sub_genre, const std::string &author);
  // If book exists, increment times watched
  bool increment_read(const std::string &book);
  // Display's Book collection
  virtual void display() const override;
};

#endif // _BOOKCOLLECTION_H_