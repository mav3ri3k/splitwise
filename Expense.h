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
  Split split;
  forward_list<Person> participants;

  bool isSorted;

  Expense() {}
  Expense(float cost, string description, forward_list<Person> &participants) {
    this->cost = cost;
    this->description = description;
    this->participants = participants;

    this->split = Split(participants, cost);
  }

  bool add(Person person) {
    participants.push_front(person);
    return true;
  }

  bool remove(Person person) {
    // participants.remove(person);
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
