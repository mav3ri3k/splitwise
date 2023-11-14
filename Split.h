#include "Person.h"
#include <algorithm>
#include <forward_list>
#include <iostream>
#include <string>

using namespace std;

class SplitPerson {
public:
  string name;
  float personCost;

  SplitPerson(string name, float personCost) {
    this->name = name;
    this->personCost = personCost;
  }

  SplitPerson(string name) { this->name = name; }
};

class Split {
private:
  static void add(const int p) {}

  static bool comparator(const SplitPerson &a, const SplitPerson &b) {
    return a.name < b.name;
  }

public:
  float cost;
  forward_list<SplitPerson> splitParticipants;
  forward_list<Person> participants;

  Split() {}
  Split(forward_list<Person> &participants, float cost) {
    this->participants = participants;
    this->cost = cost;

    for (auto person : participants) {
      splitParticipants.push_front(SplitPerson(person.name));
    }
  }

  void sortList() { splitParticipants.sort(comparator); }

  void setCost() {
    this->sortList();
    cout << "Hello" << endl;

    float total = cost;

    for (auto person : splitParticipants) {
      cout << "Split Cost for " << person.name << " :";
      float temp;
      cin >> temp;
      person.personCost = temp;
      total -= temp;
      cout << "Remaining amount to divide: " << total << endl;
    }

    if (total != 0) {
      for (auto person : splitParticipants) {
        person.personCost = 0;
      }
      cout << "Unsucessfull, please try again!";
    } else {
      cout << "Successfull";
    }
    cout << endl;
  }
};
