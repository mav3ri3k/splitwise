#include "Expense.h"
#include <cctype>
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

  string format(string s) {
    for (int i = 0; i < s.length(); i++) {
      s[i] = tolower(s[i]);
    }

    s[0] = toupper(s[0]);

    return s;
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

    if (!expenses.empty()) {
      cout << "Expense: " << endl;
      for (Expense expense : expenses) {
        cout << " - "
             << "Rs." << expense.totalCost << " " << expense.description
             << endl;

        cout << "   - You : Rs." << expense.myCost << endl;
        for (SplitPerson person : expense.participants) {
          cout << "   - " << format(person.name) << ": Rs." << person.personCost
               << endl;
        }
      }
    } else {
      cout << "You can add expense for " << name << " here" << endl;
    }
  }
};
