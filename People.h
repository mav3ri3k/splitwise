#include "Person.h"

using namespace std;

#ifndef PEOPLE_H
#define PEOPLE_H

class People {
public:
  virtual bool add(Person person) = 0;
  virtual bool remove(Person person) = 0;
  virtual Person *retrieveName(string name) = 0;
  virtual void sortList() = 0;
};

#endif // PEOPLE_H
