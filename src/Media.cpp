#include <iostream>
#include <string>
#include <stdexcept>
#include "../include/Media.h"

// Implementation of base class constructor
Media::Media(std::string title, int times_consumed, int user_rating)
: title{title}, times_consumed{times_consumed}, user_rating{user_rating}{
    if (user_rating > 5 || user_rating < 0){
        throw std::out_of_range("Value must be between 0 and 5");
      }
      if (times_consumed < 0){
        throw std::out_of_range("Value must be greater than 0");
      }
}

// Operator Overloading
bool Media::operator==(const Media &rhs) const{
    return (title==rhs.title);
}
bool Media::operator<(const Media &rhs) const{
    return (title < rhs.title);
}
bool Media::operator>(const Media &rhs) const{
    return (title > rhs.title);
}

// Getters
std::string Media::get_title() const {return title;}
int Media::get_times_consumed() const {return times_consumed;}
int Media::get_user_rating() const {return user_rating;}
// Setters
void Media::set_title(std::string title){
    this->title = title;
}
void Media::set_times_consumed(int times_consumed){
    this->times_consumed = times_consumed;
}
void Media::set_user_rating(int user_rating){
    this->user_rating = user_rating;
}

// Custom Methods
void Media::increment_times_consumed(){times_consumed++;}