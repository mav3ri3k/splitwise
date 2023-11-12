#include "People.h"
#include <forward_list>
#include <string>

using namespace std;

class methods {};

class Expense : public People, public methods {
  float cost;
  string description;
  forward_list<Person> participants;
};
