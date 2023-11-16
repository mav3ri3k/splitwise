#include "Expense.h"
#include <iostream>

using namespace std;

class Group {

private:
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

  Group(string name) { this->name = name; }

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
             << "₹" << expense.totalCost << " " << expense.description << endl;

        cout << "   - You : ₹" << expense.myCost << endl;
        for (SplitPerson person : expense.participants) {
          cout << "   - " << format(person.name) << ": ₹" << person.personCost
               << endl;
        }
      }
    } else {
      cout << "You can add expense for " << name << " here" << endl;
    }
  }
};
