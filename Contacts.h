#include "People.h"
#include <algorithm>
#include <forward_list>
#include <iterator>
#include <string>
using namespace std;

class Contacts : public People {
private:
  static bool comparator(const Person &a, const Person &b) {
    return a.name < b.name;
  }

public:
  forward_list<Person> people;
  bool isSorted;

  bool add(Person person) {
    people.push_front(person);
    return true;
  }

  bool remove(Person person) {
    // people.remove(person);
    return true;
  }

  Person *retrieveName(string name) {
    forward_list<Person>::iterator itr = people.begin();

    while (itr != people.end()) {
      if (itr->name == name) {
        return &(*itr);
      }
    }

    return nullptr;
  }

  void sortList() { people.sort(comparator); }
};
