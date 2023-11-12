#include "People.h"
#include "Split.h"
#include <forward_list>
#include <string>

using namespace std;

class Expense : public People {
private:
  static bool comparator(const Person &a, const Person &b) {
    return a.name < b.name;
  }

public:
  float cost;
  string description;
  forward_list<Person> participants;

  bool isSorted;

  bool add(Person person) {
    participants.push_front(person);
    return true;
  }

  bool remove(Person person) {
    participants.remove(person);
    return true;
  }

  Person *retrieveName(string name) {
    forward_list<Person>::iterator itr = participants.begin();

    while (itr != participants.end()) {
      if (itr->name == name) {
        return &(*itr);
      }
    }

    return nullptr;
  }

  void sortList() { participants.sort(comparator); }
};
