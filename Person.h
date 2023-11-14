#include <string>

using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person {
public:
  string name;

  bool isFriend;
  bool isUsed;

  Person(string name, bool isFriend, bool isUsed) {
    this->name = name;
    this->isFriend = isFriend;
    this->isUsed = isUsed;
  }
};

#endif // PERSON_H
