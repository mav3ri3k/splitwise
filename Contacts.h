#include "People.h"
#include <forward_list>
#include <string>
using namespace std;

class Contacts : public People {
  forward_list<Person> people;
};
