#include "Color.h"
#include "States.h"
#include <string>

using namespace std;

string format(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (i == 0) {
      s[i] = toupper(s[i]);
    } else {
      s[i] = tolower(s[i]);
    }
  }

  return s;
}

string lower(string s) {
  for (int i = 0; i < s.length(); i++) {
    s[i] = tolower(s[i]);
  }

  return s;
}

int main() {
  Color::Modifier red(Color::FG_RED);
  Color::Modifier def(Color::FG_DEFAULT);

  States states = States();
  while (true) {
    cout << red << format(states.stateName()) << "> " << def;

    string input;
    cin >> input;
    input = lower(input);

    if (input == "help") {
      cout << "Currently in " << red << format(states.stateName()) << def
           << " menue." << endl
           << endl;

      if (states.state == states.states[0]) {
        if (!states.groups.groups.empty()) {
          cout << "Groups available: " << endl;
          for (Group grp : states.groups.groups) {
            cout << " - " << format(grp.name) << endl;
          }
        } else {
          cout << "Add New group to see list of Groups" << endl;
        }
      } else {
        Group &grp = states.groups.refGroup(states.stateName());
        if (!grp.expenses.empty()) {
          cout << "Expense: " << endl;
          for (Expense expense : grp.expenses) {
            cout << " - "
                 << "Rs." << expense.cost << " " << expense.description << endl;
          }
        } else {
          cout << "You can add expense for " << red << grp.name << def
               << " here" << endl;
        }
      }

      if (!states.actionsAvailable().empty()) {
        cout << endl;
        cout << "Commands available: " << endl;
        for (string commands : states.actionsAvailable()) {
          cout << " - " << commands << endl;
        }
      }
      cout << endl;
    } else if (input == "exit") {
      cout << "Bye "
           << "\uf25b";
      exit(0);
    } else {
      if (states.changeStateTo(input)) {
      } else if (states.doAction(input)) {
      } else if (states.moveToList(input)) {
      } else {
        cout << red << "Wrong Command!!" << def << endl;
      }
    }
  }
}
