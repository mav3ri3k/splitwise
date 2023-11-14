#include "Expense.h"
#include <forward_list>
#include <vector>
// delete later
#include <iostream>
#include <string>

using namespace std;

class Group : public People {

private:
  static bool comparator(const Person &a, const Person &b) {
    return a.name < b.name;
  }

public:
  string name;
  vector<Expense> expenses;
  forward_list<Person> participants;

  Group(string name) { this->name = name; }

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

  void addExpense() {
    Expense ex = Expense();
    ex.addExpense();
    expenses.push_back(ex);
  }

  void viewExpenses() {
    for (auto expense : expenses) {
      cout << expense.description << endl;
      ;
    }
  }
};
