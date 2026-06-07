#ifndef _BOOK_H_
#define _BOOK_H_
#include <string>
#include "Media.h"


class Book: public Media{
private:
  static constexpr int def_times_consumed = 0;
  static constexpr int def_user_rating = -1;
  static constexpr const char *def_string_val = "N/A";
  static constexpr const char *def_author = "Unknown";
protected:
  // Attributes specific to a book
  std::string isbn13;
  std::string genre;
  std::string sub_genre;
  std::string author;
public:
   // Constructors
  Book(const std::string&title, int times_consumed=def_times_consumed,
    int user_rating=def_user_rating, const std::string &isbn=def_string_val,
    const std::string &genre=def_string_val, const std::string &sub_genre = def_string_val,
    const std::string &author=def_author);

  // Getters and Setters
  int get_times_read() const;
  const std::string &get_isbn() const;
  const std::string &get_genre() const;
  const std::string &get_sub_genre() const;
  const std::string &get_author() const;
  void set_times_read(int times_read);
  void set_isbn(const std::string &isbn);
  void set_genre(const std::string &genre);
  void set_sub_genre(const std::string &sub_genre);
  void set_author(const std::string &author);

  // Custom Methods
  void increment_read(){Media::increment_times_consumed();} // Wrapper method to provide more intuitive naming
  void display() const; // Display Book Information
  };

#endif // _BOOK_H_