#include "../include/MediaCollection.h"

// Constructor
MediaCollection::MediaCollection(std::string name)
: name{name}{}

std::string MediaCollection::get_name() const{
    return this->name;
  }
  void MediaCollection::set_name(std::string name){
    this->name = name;
  }