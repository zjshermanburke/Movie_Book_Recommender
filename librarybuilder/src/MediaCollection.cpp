#include "MediaCollection.h"

// Constructor
MediaCollection::MediaCollection(const std::string &name)
: name{name}{}

std::string MediaCollection::get_name() const{
    return this->name;
  }
  void MediaCollection::set_name(const std::string &name){
    this->name = name;
  }