#include "Person.h"

using namespace std;

class People {
public:
  virtual bool add(Person person) = 0;
  virtual bool remove(Person person) = 0;
  virtual Person retrieveName(string name) = 0;
};
