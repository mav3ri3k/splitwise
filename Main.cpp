#include "Color.h"
#include "States.h"
#include <cctype>
#include <cstdio>
#include <cstring>
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
      cout << "Option available: " << endl;
      for (string nextState : states.nextViableStates()) {
        cout << " - " << format(nextState) << endl;
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
