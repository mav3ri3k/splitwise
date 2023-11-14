#include "Expense.h"
#include <forward_list>
#include <vector>
// delete later
#include <iostream>

using namespace std;

class Group : public People {

private:
  static bool comparator(const Person &a, const Person &b) {
    return a.name < b.name;
  }

public:
  vector<Expense> expenses;
  forward_list<Person> participants;

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
    cout << "Add Expense:" << endl;
    cout << "Total Cost: ";
    float cost;
    cin >> cost;

    cout << "Description: ";
    string description;
    cin >> description;

    Expense expense = Expense(cost, description, participants);
    expense.split.setCost();
  }

  void printExpenses() {
    for (auto expense : expenses) {
      cout << expense.description << endl;
      ;
    }
  }
};
