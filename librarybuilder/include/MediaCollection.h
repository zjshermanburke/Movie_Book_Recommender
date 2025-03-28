#ifndef _MEDIACOLLECTION_H_
#define _MEDIACOLLECTION_H_
#include <string>

class MediaCollection{
protected:
    std::string name;
public:
    // Constructor
    MediaCollection(std::string name);
    // Destructor
    virtual ~MediaCollection(){}

// Getters and Setters
  std::string get_name() const;
  void set_name(std::string name);

  virtual void display() const = 0;

};

#endif //_MEDIACOLLECITON_H_